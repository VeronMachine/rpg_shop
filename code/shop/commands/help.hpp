#pragma once

#include <string>
#include <vector>
#include "shop/commands/command.hpp"

namespace commands {

class help : public command {
public:
    explicit help(std::vector<std::string> data) noexcept;

    void execute() override;

private:
    std::vector<std::string> m_data;
};

} //namespace commands