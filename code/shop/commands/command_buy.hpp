#pragma once

#include "shop/commands/command.hpp"
#include "shop/entities/player.hpp"
#include "shop/entities/shop.hpp"

namespace commands {

class command_buy : public command {
public:
    command_buy(entities::player &player, entities::shop &shop) noexcept;

    void set_id(size_t id) noexcept;
    void execute() override;
private:
    size_t item_id{};
    entities::player &player_buffer;
    entities::shop &shop_buffer;
};

} // namespace commands