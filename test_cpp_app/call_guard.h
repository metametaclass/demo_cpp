#pragma once

#include <string>

class CallGuard
{
public:
    CallGuard(const std::string& comment);
    ~CallGuard();
private:
    std::string mComment;
};
