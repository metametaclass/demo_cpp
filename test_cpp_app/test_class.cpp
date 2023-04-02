#include "test_class.h"

#include <iostream>
#include <format>


TestClass::TestClass()
    : TestClass("default")
{
    std::cout << "TestClass::TestClass() default constructor body" << std::endl;
}

TestClass::TestClass(const std::string& name)
    : mName(name)
    , mFixedName(name)
{
    std::cout << std::format("TestClass::TestClass({})", name) << std::endl;
}

void TestClass::run(const std::string& comment)
{
    std::cout << std::format("TestClass({})::run({})", mName, comment) << std::endl;
}

void TestClass::set_name(const std::string& new_name)
{
    std::cout << std::format("TestClass::set_name(&) {}: {} -> {}", mFixedName, mName, new_name) << std::endl;
    mName = new_name;
}

void TestClass::set_name(std::string&& new_name)
{
    std::cout << std::format("TestClass::set_name(&&) {}: {} -> {}", mFixedName, mName, new_name) << std::endl;
    mName = new_name;
}

TestClass::~TestClass()
{
    std::cout << std::format("TestClass::~TestClass({}, {})", mFixedName, mName) << std::endl;
}
