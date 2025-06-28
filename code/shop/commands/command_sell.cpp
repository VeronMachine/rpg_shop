#include <cstdio>
#include "shop/commands/command_sell.hpp"

namespace commands {

command_sell::command_sell(entities::player &player, entities::shop &shop) noexcept
    : player_buffer{ player }
    , shop_buffer{ shop }
{}

void command_sell::set_id(size_t id) noexcept {
    item_id = id;
}

void command_sell::execute() {
    shop_buffer.buy(item_id, player_buffer);
}

} // namespace commands