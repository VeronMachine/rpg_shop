#include "shop/inventory/inventory.hpp"

namespace inventory {

item::item(std::string_view name, uint32_t price) noexcept
    : m_name{ name }
    , m_price{ price }
{}

std::string item::get_name() const noexcept {
    return m_name;
}

uint32_t item::get_price() const noexcept {
    return m_price;
}

void item::set_name(std::string_view other) noexcept {
    m_name = other;
}

void item::set_price(uint32_t other) noexcept {
    m_price = other;
}

} // namespace inventory