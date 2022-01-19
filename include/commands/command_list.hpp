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
#ifndef STAGEHAND_INCLUDE_COMMANDS_COMMAND_LIST_H
#define STAGEHAND_INCLUDE_COMMANDS_COMMAND_LIST_H
#include <commands/base.hpp>

namespace stagehand::commands {

    class ShutdownCommand : public stagehand::commands::Command {
      public:
        static inline std::string name { "shutdown" };
        static inline std::string desc { "Exit the bot's process." };
        static inline std::vector<dpp::command_permission> permissions {};
        static void execute(const dpp::interaction_create_t& event, const std::shared_ptr<stagehand::utils::TypeMap> map);
    };

};

#endif // STAGEHAND_INCLUDE_COMMANDS_COMMAND_LIST_H
