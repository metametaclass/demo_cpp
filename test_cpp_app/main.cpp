#include "test_class.h"
#include "call_guard.h"

#include <format>
#include <iostream>
#include <string>
#include <string_view>

void sink1(TestClass data)
{
    CallGuard cg(__FUNCTION__);
    std::cout << std::format("sink1({})", data.get_desc()) << std::endl;
}

void sink2(TestClass& data)
{
    CallGuard cg(__FUNCTION__);
    std::cout << std::format("sink2(&{})", data.get_desc()) << std::endl;
}

void sink3(TestClass&& data)
{
    CallGuard cg(__FUNCTION__);
    auto t = std::move(data);
    std::cout << std::format("sink3(&&{})", t.get_desc()) << std::endl;
}

void test_sinks()
{
    CallGuard cg(__FUNCTION__);
    TestClass class6("class6");
    sink1(class6);
    TestClass class7("class7");
    sink2(class7);
    TestClass class8("class8");
    sink3(std::move(class8));

    sink1(TestClass("class9"));
    //sink2(TestClass("class10"));
    sink3(TestClass("class11"));
}

int main(int argc, const char* argv[]) {
    int test = 1;
    std::cout << std::format("{}\n", test);

    TestClass class1;
    TestClass class2(std::string("class2"));

    auto class3 = class2; // copy constructor is called
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

    auto class5 = class3;

    test_sinks();
}
