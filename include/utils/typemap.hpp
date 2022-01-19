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

#ifndef STAGEHAND_INCLUDE_UTILS_TYPEMAP_H
#define STAGEHAND_INCLUDE_UTILS_TYPEMAP_H

#include <bot_config.hpp>
#include <any>
#include <atomic>
#include <memory>
#include <type_traits>
#include <typeindex>
#include <unordered_map>

namespace stagehand::utils {

    namespace tm_keys {
        template<typename T>
        concept TypeMapKey = requires {
            typeid(typename T::Value);
        };

        struct ShutdownBool {
            using Value = std::atomic_bool;
        };
    };

    class TypeMap {
        std::unordered_map<std::type_index, std::any> m_map;

      public:
        template<typename Key>
        requires tm_keys::TypeMapKey<Key>
        inline void insert(const std::shared_ptr<typename Key::Value> value) {
            m_map.insert({ std::type_index(typeid(Key)), value });
        }

        template<typename Key>
        requires tm_keys::TypeMapKey<Key>
        inline std::shared_ptr<typename Key::Value> at() {
            std::any val = m_map[std::type_index(typeid(Key))];
            return std::any_cast<std::shared_ptr<typename Key::Value>>(val);
        }
    };
};

#endif // STAGEHAND_INCLUDE_UTILS_TYPEMAP_H
