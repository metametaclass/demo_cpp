#pragma once

#include <string>

class TestClass {
public:
    TestClass();

    TestClass(const std::string& name);

    // delete copy constructor
    // TestClass(TestClass& t) = delete;

    TestClass(TestClass& t);

    TestClass(const TestClass& t);

    // move constructor
    TestClass(TestClass&& t) noexcept;

    // copy assignment 
    TestClass& operator=(const TestClass&);

    // move assigment
    TestClass& operator=(TestClass&&) noexcept;

    ~TestClass();

    void run(const std::string& comment) const;

    void set_name(const std::string& new_name);

    void set_name(std::string&& new_name);

    std::string get_desc() const;

private:

    std::string mName;
    std::string mFixedName;
};