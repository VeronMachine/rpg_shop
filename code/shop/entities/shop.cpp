#include "shop/entities/shop.hpp"

namespace entities {

shop::shop(std::string name, uint32_t money) noexcept
    : m_name{ name }
    , m_money{ money }
{}

std::string_view shop::get_name() const noexcept {
    return m_name;
}

uint32_t shop::get_money() const noexcept {
    return m_money;
}

const std::array<std::optional<inventory::item>, 8> &shop::get_inventory() const {
    return shop_items;
}

void shop::set_name(std::string_view other) noexcept {
    m_name = std::move(other);
}

void shop::set_money(uint32_t other) noexcept {
    m_money = other;
}

bool shop::add_item(inventory::item item) {
    for(size_t i{}; i < std::size(shop_items); ++i) {
        if(!shop_items[i].has_value()) {
            shop_items[i] = std::move(item);
            return true;
        }
    }
    return false;
}

std::optional<inventory::item> shop::remove_item(size_t index) {
    std::optional<inventory::item> temp{};
    shop_items[index].swap(temp);
    return temp;
}

bool shop::sell(size_t index, entities::player &player) {
    std::optional<inventory::item> temp{ remove_item(index) };

    if(!temp.has_value()) {
        return false;
    }

    if(player.get_money() < temp->get_price()) {
        temp.swap(shop_items[index]);
        return false;
    }

    this->set_money(this->get_money() + temp->get_price());
    player.set_money(player.get_money() - temp->get_price());
    player.add_item(std::move(temp).value());
    return true;
}

bool shop::buy(size_t index, entities::player &player) {
    std::optional<inventory::item> temp{ player.remove_item(index) };

    if(!temp.has_value()) {
        return false;
    }

    if(this->get_money() < temp->get_price()) {
        temp.swap(player.player_items[index]);
        return false;
    }

    player.set_money(player.get_money() + temp->get_price());
    this->set_money(this->get_money() - temp->get_price());
    this->add_item(std::move(temp).value());
    return true;
}

} // namespace entities