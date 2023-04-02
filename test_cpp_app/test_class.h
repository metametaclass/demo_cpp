#pragma once

#include <string>

class TestClass {
public:
    TestClass();

    TestClass(const std::string& name);

    ~TestClass();

    void run(const std::string& comment);

    void set_name(const std::string& new_name);

    void set_name(std::string&& new_name);

private:
    std::string mName;
    std::string mFixedName;
};