#pragma once

#include "shop/inventory/inventory.hpp"
#include "shop/commands/command.hpp"
#include "shop/entities/shop.hpp"

namespace commands {

class command_shop : public command {
public:
    explicit command_shop(entities::shop &shop) noexcept;

    void execute() override;

private:
    entities::shop &shop_buffer;

};

} //namespace commands