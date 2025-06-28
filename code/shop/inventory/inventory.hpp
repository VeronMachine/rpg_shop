#pragma once

#include <cstdint>
#include <string>

namespace inventory {

class item {
public:
    item(std::string_view name, uint32_t price) noexcept;
    ~item() = default;

    std::string get_name() const noexcept;
    uint32_t get_price() const noexcept;
    void set_name(std::string_view other) noexcept;
    void set_price(uint32_t other) noexcept;
private:
    std::string m_name{};
    uint32_t m_price{};
    uint32_t m_count{};
    uint32_t full_price{};

};

} // namespace inventory