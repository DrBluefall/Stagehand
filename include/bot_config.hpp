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

#include <autoconf.h>
#include <string>
#include <string_view>
#include <toml++/toml.h>

namespace stagehand {
    class Config {
      private:
        toml::table m_table;

      public:
        Config(std::string_view path)
            : m_table(toml::parse_file(path)) {}
        inline std::string token() { return m_table["bot"]["token"].value<std::string>().value(); }

        inline std::uint64_t guild_id() { return m_table["theater"]["guild"].value<std::uint64_t>().value(); }
        inline std::uint64_t assistant_role_id() {
            return m_table["theater"]["assistant_role"].value<std::uint64_t>().value();
        }
        inline std::uint64_t theatermaster_role_id() {
            return m_table["theater"]["master_role"].value<std::uint64_t>().value();
        }

        inline std::uint64_t approved_actor_id() {
            return m_table["theater"]["approved_role"].value<std::uint64_t>().value();
        }
    };
}; // namespace dppexp
#endif // STAGEHAND_INCLUDE_BOT_CONFIG_H
