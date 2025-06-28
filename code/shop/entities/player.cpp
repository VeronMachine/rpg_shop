#include "shop/entities/player.hpp"

namespace entities {

player::player(std::string name, uint32_t money) noexcept
    : m_name{ std::move(name) }
    , m_money{ money }
{}

std::string_view player::get_name() const noexcept{
    return m_name;
}

uint32_t player::get_money() const noexcept {
    return m_money;
}

const std::array<std::optional<inventory::item>, 8> &player::get_inventory() const {
    return player_items;
}

void player::set_name(std::string_view other) noexcept {
    m_name = other;
}

void player::set_money(uint32_t other) noexcept {
    m_money = other;
}

bool player::add_item(inventory::item item) {
    for(size_t i{}; i < std::size(player_items); ++i) {
        if(!player_items[i].has_value()) {
            player_items[i] = std::move(item);
            return true;
        }
    }
    return false;
}

std::optional<inventory::item> player::remove_item(size_t index) {
    std::optional<inventory::item> temp{};
    player_items[index].swap(temp);
    return temp;
}

} //namespace entities
