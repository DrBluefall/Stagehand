/* Copyright (C) 2022 Alexander Bisono.
 * This file is a part of Stagehand.
 *
 * Stagehand is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Affero General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * Stagehand is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Affero General Public License along
 * with Stagehand. If not, see <https://www.gnu.org/licenses/>.
 */

#include <atomic>
#include <autoconf.h>
#include <dpp/dpp.h>
#include <iomanip>
#include <iostream>
#include <type_traits>

#include <bot_config.hpp>
#include <commands/command_list.hpp>
#include <utils/typemap.hpp>

using stagehand::utils::TypeMap;

using namespace std::chrono_literals;
namespace cmds = stagehand::commands;

template<typename Cmd>
requires std::is_base_of_v<cmds::Command, Cmd>
static void register_command(dpp::cluster& bot, std::unordered_map<std::string, cmds::CommandFunction>& cmdmap) {
    bot.on_ready([&bot](const dpp::ready_t& event) {
        dpp::slashcommand command;
        command.set_name(Cmd::name)
            .set_description(Cmd::desc);
        for (auto i : Cmd::options) {
            command.add_option(i);
        }
        for (auto i : Cmd::permissions) {
            command.add_permission(i);
        }
        bot.global_command_create(command);
    });
    cmdmap[Cmd::name] = &Cmd::execute;
}

int main() {
    std::cout << "Initializing " PACKAGE_NAME " ver. " PACKAGE_VERSION "..." << std::endl;

    stagehand::config config("bot.toml");

    dpp::cluster bot(config.token());

    std::shared_ptr<TypeMap> typemap(std::make_shared<TypeMap>());

    auto shutdown_p(std::make_shared<std::atomic_bool>(false));

    typemap->insert<stagehand::utils::tm_keys::ShutdownBool>(shutdown_p);

    std::unordered_map<std::string, cmds::CommandFunction> command_map;

    register_command<cmds::ShutdownCommand>(bot, command_map);

    bot.on_ready([&bot, &config](const dpp::ready_t& event) {
        std::cout << "Logged in as " << bot.me.username << "#" << std::setfill('0') << std::setw(4)
                  << bot.me.discriminator << "." << std::endl;
    });

    bot.on_interaction_create([&command_map, typemap](const dpp::interaction_create_t& event){
        if (event.command.type == dpp::it_application_command) {
            dpp::command_interaction cmd_data = std::get<dpp::command_interaction>(event.command.data);
            command_map.at(cmd_data.name)(event, typemap);
        }
    });

    bot.start();

    while (!shutdown_p->load()) continue; /* Hold here until prompted. */

    return 0;
}
