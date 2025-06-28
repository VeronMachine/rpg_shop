#pragma once

#include <string>
#include <array>
#include <optional>
#include "shop/inventory/inventory.hpp"
#include "shop/entities/player.hpp"


namespace entities {

class shop {
public:
    shop(std::string name, uint32_t money) noexcept;

    std::string_view get_name() const noexcept;
    uint32_t get_money() const noexcept;
    const std::array<std::optional<inventory::item>, 8> &get_inventory() const;
    void set_name(std::string_view other) noexcept;
    void set_money(uint32_t other) noexcept;

    bool add_item(inventory::item item);
    std::optional<inventory::item> remove_item(size_t index);

    bool sell(size_t index, entities::player &player);
    bool buy(size_t index, entities::player &player);

private:
    std::array<std::optional<inventory::item>, 8> shop_items{};
    std::string m_name{};
    uint32_t m_money{};
};

} // namespace entities