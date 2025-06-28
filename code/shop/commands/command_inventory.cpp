#include "shop/commands/command_inventory.hpp"

namespace commands {

command_inventory::command_inventory(entities::player &player) noexcept
    : player_buffer{ player }
{}

void command_inventory::execute() {
    const auto &inventory{ player_buffer.get_inventory() };

    for (size_t i{}; i < std::size(inventory); ++i) {
        if(inventory[i].has_value()) {
            std::printf("%zu) %s, %d gold\n", i, std::data(inventory[i]->get_name()), inventory[i]->get_price());
        } else {
            std::printf("empty slot\n");
        }
    }
    std::printf("your balance: %u gold\n", player_buffer.get_money());
}

} // namespace commands