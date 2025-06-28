#include <cstdio>
#include <iostream>
#include <stdexcept>
#include "shop/factory/cmd_factory.hpp"
#include "shop/commands/help.hpp"
#include "shop/commands/command_buy.hpp"
#include "shop/commands/command_inventory.hpp"
#include "shop/commands/command_shop.hpp"
#include "shop/commands/command_sell.hpp"

int main() {
    entities::shop shop{ "Shop", 1300 };
    shop.add_item(inventory::item{ "Sword", 100 });
    shop.add_item(inventory::item{ "Axe", 90 });

    entities::player player{ "Player", 100 };

    factory::cmd_factory cmd_factory{};

    std::string input{};

    while(input != "end") {
        std::cin >> input;
        std::unique_ptr<commands::command> cmd{
            cmd_factory.produce(input, player, shop)
        };

        if(!cmd) {
            std::printf("wrong command\n");
            cmd_factory.produce("help", player, shop);
            continue;
        }

        cmd->execute();
    }
}