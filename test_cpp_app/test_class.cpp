#include "test_class.h"

#include <iostream>
#include <format>


TestClass::TestClass()
    : TestClass("default")
{
    std::cout << "TestClass::TestClass() default constructor called" << std::endl;
}

TestClass::TestClass(const std::string& name)
    : mName(name)
    , mFixedName(name)
{
    std::cout << std::format("TestClass::TestClass({})", name) << std::endl;
}

TestClass::TestClass(TestClass& t) 
    : mFixedName(t.mFixedName)
    , mName(t.mName)
{
    std::cout << std::format("TestClass::TestClass({},{}) copy constructor called",mFixedName,mName) << std::endl;
}

TestClass::TestClass(const TestClass& t)
    : mFixedName(t.mFixedName)
    , mName(t.mName)
{
    std::cout << std::format("TestClass::TestClass({},{}) const copy constructor called", mFixedName, mName) << std::endl;
}

TestClass::TestClass(TestClass&& t) noexcept
    : mFixedName(std::move(t.mFixedName))
    // : mFixedName("moved:" + t.mFixedName)
    , mName(std::move(t.mName))
{
    std::cout << std::format("TestClass::TestClass({},{}) move constructor called", mFixedName, mName) << std::endl;
}


TestClass::~TestClass()
{
    std::cout << std::format("TestClass::~TestClass({}, {})", mFixedName, mName) << std::endl;
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

std::string TestClass::get_desc() const
{
    return std::format("TestClass({},{})", mFixedName, mName);
}