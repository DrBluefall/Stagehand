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
#ifndef STAGEHAND_INCLUDE_BOT_CONFIG_H
#define STAGEHAND_INCLUDE_BOT_CONFIG_H

#include <string>
#include <string_view>
#include <toml++/toml.h>
#include <autoconf.h>

namespace stagehand {
    class config {
      private:
        toml::table m_table;

      public:
        config(std::string_view path);
        std::string token();
#ifdef STAGEHAND_DEBUG_BUILD
        std::uint64_t guild_id();
#endif // STAGEHAND_DEBUG_BUILD
    };
}; // namespace dppexp
#endif // STAGEHAND_INCLUDE_BOT_CONFIG_H
