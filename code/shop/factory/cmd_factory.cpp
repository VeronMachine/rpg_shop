#include <vector>
#include <iostream>
#include "shop/factory/cmd_factory.hpp"
#include "shop/commands/command.hpp"
#include "shop/commands/help.hpp"
#include "shop/commands/command_buy.hpp"
#include "shop/commands/command_inventory.hpp"
#include "shop/commands/command_shop.hpp"
#include "shop/commands/command_sell.hpp"

namespace factory {

std::unique_ptr<commands::command> cmd_factory::produce(
    std::string_view input,
    entities::player &player_buffer,
    entities::shop &shop_buffer
) {
    if (input.starts_with("help")) {
        return std::make_unique<commands::help>(commands::help {
                std::vector<std::string>{
                    "help            - show this message.",
                    "shop            - show shop items.",
                    "inventory       - show your inventory.",
                    "sell <id> [<N>] - sell item <id> slot from your inventory.",
                    "buy <id> [<N>]  - buy item <id> from the shop."
                    "end - close the program."
                }
            }
        );

    }
    else if (input.starts_with("shop")) {
        return std::make_unique<commands::command_shop>(
            commands::command_shop{ shop_buffer }
        );
    }
    else if (input.starts_with("inventory")) {
        return std::make_unique<commands::command_inventory>(
            commands::command_inventory{ player_buffer }
        );
    }
    else if (input.starts_with("buy")) {
        size_t buy_id{};

        std::printf("\nenter the item id: ");
        std::cin >> buy_id;

        commands::command_buy buy{ player_buffer, shop_buffer };
        buy.set_id(buy_id);

        return std::make_unique<commands::command_buy>(buy);
    }
    else if (input.starts_with("sell")) {
        size_t sell_id{};

        std::printf("\nenter the item id: ");
        std::cin >> sell_id;

        commands::command_sell sell{ player_buffer, shop_buffer };
        sell.set_id(sell_id);

        return std::make_unique<commands::command_sell>(sell);
    }
    else return nullptr;
}


} // namespace factory