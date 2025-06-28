#include "shop/commands/command_shop.hpp"

namespace commands {

command_shop::command_shop(entities::shop &shop) noexcept
    : shop_buffer{ shop }
{}

void command_shop::execute() {
    const auto &inventory{ shop_buffer.get_inventory() };

    for (size_t i{}; i < std::size(inventory); ++i) {
        if(inventory[i].has_value()) {
            std::printf("%zu) %s, %d gold\n", i, std::data(inventory[i]->get_name()), inventory[i]->get_price());
        } else {
            std::printf("empty slot\n");
        }
    }
    std::printf("shop balance: %u gold\n", shop_buffer.get_money());
}

} // namespace commands