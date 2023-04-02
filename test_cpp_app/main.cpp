#include "test_class.h"

#include <format>
#include <iostream>
#include <string>
#include <string_view>

int main(int argc, const char* argv[]) {
    int test = 1;
    std::cout << std::format("{}\n", test);

    TestClass class1;
    TestClass class2(std::string("class2"));

    auto class3 = class2;
    auto& class4 = class2;
    class1.run("class1.run");
    class2.run("class2.run");
    class3.run("class3.run");
    class4.run("class4.run");

    class1.set_name("class1.1");
    class2.set_name("class2.1");    
    class3.set_name("class3.1");
    class4.set_name("class4.1");
    
    class1.run("class1.run");
    class2.run("class2.run");
    class3.run("class3.run");
    class4.run("class4.run");
}
