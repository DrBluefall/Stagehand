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
#include <string>
#include <vector>

namespace stagehand {
    class Command {
      public:
        /*
         * The name of the command.
         * */
        const std::string name;
        /*
         * Command description.
         * *
        const std::string desc;
        /*
         * The arguments the command takes.
         * */
        const std::vector<dpp::command_option> options {};

        /*
         * Required permissions for the command
         * */
        const std::vector<dpp::command_permission> permissions {};

        /*
         * Execute the command.
         *
         * Note that this should be registered like so:
         *
         * ```cpp
         * cmd_handler.add_command(
         *     &command.name,
         *     &command.parameter_list,
         *     [&cmd_handler](const std::string& cmd_name,
         *                    const dpp::parameter_list_t& params,
         *                    dpp::command_source src) {
         *         command.execute(cmd_name, params, src, cmd_handler);
         *     }
         * );
         * ```
         * */
        virtual void execute(const std::string& cmd_name,
            const dpp::parameter_list_t& params,
            dpp::command_source src,
            dpp::commandhandler handler)
            = 0;
    };
};

#endif // STAGEHAND_INCLUDE_COMMANDS_BASE_HPP
