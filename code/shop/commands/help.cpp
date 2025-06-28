#include <cstdio>
#include "shop/commands/help.hpp"

namespace commands {

help::help(std::vector<std::string> data) noexcept
    : m_data{ std::move(data) }
{}

void help::execute() {
    for (size_t i{}; i < std::size(m_data); ++i) {
        std::printf("%s\n", std::data(m_data[i]));
    }
}

} // namespace commands
