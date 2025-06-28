#pragma once

namespace commands {

class command {
public:
    virtual ~command() = default;

    virtual  void execute() = 0;
};

} //namespace commands