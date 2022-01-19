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
#include <commands/command_list.hpp>
#include <utils/typemap.hpp>

using stagehand::utils::tm_keys::ShutdownBool;

namespace stagehand::commands {
    void ShutdownCommand::execute(
        const dpp::interaction_create_t& event, const std::shared_ptr<stagehand::utils::TypeMap> map) {

        auto shutdown_p (map->at<ShutdownBool>());

        event.reply(dpp::ir_channel_message_with_source, dpp::message("Shutting down."), [shutdown_p](auto& _) {
            shutdown_p->store(true);
        });
    }
};
