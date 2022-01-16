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

using namespace std::chrono_literals;
namespace cmds = stagehand::commands;

template<typename Cmd,
    std::enable_if_t<std::is_base_of_v<stagehand::Command, Cmd> && std::is_default_constructible_v<Cmd>,
        bool> = true>
static void register_command(dpp::cluster& bot) {
    Cmd c;
    std::cout << c.name << std::endl;
}

int main() {
    std::cout << "Initializing " PACKAGE_NAME " ver. " PACKAGE_VERSION "..." << std::endl;
    auto config = stagehand::config("bot.toml");

    dpp::cluster bot(config.token());

    std::atomic_bool shutdown_p(false);

    register_command<cmds::ShutdownCommand>(bot);

    bot.on_ready([&bot, &config](const dpp::ready_t& event) {
        std::cout << "Logged in as " << bot.me.username << "#" << std::setfill('0') << std::setw(4)
                  << bot.me.discriminator << "." << std::endl;
    });

    bot.start();

    while (!shutdown_p.load()) continue; /* Hold here until prompted. */

    return 0;
}
