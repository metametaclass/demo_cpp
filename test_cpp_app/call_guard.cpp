#include "call_guard.h"

#include "iostream"
#include "format"

CallGuard::CallGuard(const std::string& comment)
    : mComment(comment)
{
    std::cout << std::format("\"{}\" enter", mComment) << std::endl;
}

CallGuard::~CallGuard()
{
    std::cout << std::format("\"{}\" exit", mComment) << std::endl;
}
