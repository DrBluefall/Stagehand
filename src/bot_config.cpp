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

#include <bot_config.hpp>
#include <string_view>

stagehand::config::config(std::string_view path) {
    m_table = toml::parse_file(path);
}

std::string stagehand::config::token() {
    return m_table["bot"]["token"].value<std::string>().value();
}

#ifdef STAGEHAND_DEBUG_BUILD
std::uint64_t stagehand::config::guild_id() {
    return m_table["bot"]["debug_guild"].value<std::uint64_t>().value();
}
#endif // STAGEHAND_DEBUG_BUILD
