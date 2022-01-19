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
#ifndef STAGEHAND_INCLUDE_COMMANDS_BASE_HPP
#define STAGEHAND_INCLUDE_COMMANDS_BASE_HPP

#include <dpp/dpp.h>
#include <memory>
#include <string>
#include <utils/typemap.hpp>
#include <vector>

namespace stagehand::commands {

    using CommandFunction = std::function<void(
        const dpp::interaction_create_t&, const std::shared_ptr<stagehand::utils::TypeMap>)>;

    class Command {
      public:
        /*
         * The name of the command.
         * */
        static inline std::string name;
        /*
         * Command description.
         * */
        static inline std::string desc;
        /*
         * The arguments the command takes.
         * */
        static inline std::vector<dpp::command_option> options {};

        /*
         * Required permissions for the command
         * */
        static inline std::vector<dpp::command_permission> permissions {};

        /*
         * Execute the command.
         * */
        static void execute(
            const dpp::interaction_create_t& event, const std::shared_ptr<stagehand::utils::TypeMap>& map);
    };
};

#endif // STAGEHAND_INCLUDE_COMMANDS_BASE_HPP
