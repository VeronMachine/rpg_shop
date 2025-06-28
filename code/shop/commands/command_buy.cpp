#include "shop/commands/command_buy.hpp"

namespace commands {

command_buy::command_buy(entities::player &player, entities::shop &shop) noexcept
    : player_buffer{ player }
    , shop_buffer{ shop }
{}

void command_buy::set_id(size_t id) noexcept {
    item_id = id;
}

void command_buy::execute() {
    shop_buffer.sell(item_id, player_buffer);
}

} // namespace commands