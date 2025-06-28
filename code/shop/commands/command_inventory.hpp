#pragma once

#include "shop/inventory/inventory.hpp"
#include "shop/commands/command.hpp"
#include "shop/entities/player.hpp"

namespace commands {

class command_inventory : public command {
public:
    explicit command_inventory(entities::player &player) noexcept;

    void execute() override;

private:
    entities::player &player_buffer;
};

} // namespace commands