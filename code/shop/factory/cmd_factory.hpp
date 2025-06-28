#pragma once

#include <memory>
#include <string_view>
#include "shop/commands/command.hpp"


namespace entities {
    class player;
    class shop;

} // namespace entities

namespace factory {

class cmd_factory {
public:
    std::unique_ptr<commands::command> produce(
        std::string_view input,
        entities::player &player_buffer, //use forward declaration to declare player and shop
        entities::shop &shop_buffer
    );
};

} // namespace factory
