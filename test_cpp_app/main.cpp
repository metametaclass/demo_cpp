#include "test_class.h"
#include "call_guard.h"
#include "task_queue.h"

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

void test_task_queue()
{
    CallGuard cg(__FUNCTION__);
    TaskQueue q;
    q.defer_task([](float dt) {}, "task1");
    // by copy
    TestClass class2("class2");
    q.defer_task([class2](float dt)
                 { 
        class2.run("task2 class2.run"); 
        }, "task2");

    // by reference
    TestClass class3("class3");
    q.defer_task([& class3](float dt)
                 { class3.run("task3 class3.run"); },
                 "task3");

    TestClass class4("class4");
    q.defer_task([class4 = std::move(class4)](float dt)
                 { class4.run("task4 class4.run"); },
                 "task4");


    TestClass class5("class5");
    auto task5 = [class5](float dt) { 
        class5.run("task5 class5.run"); 
    };
    q.defer_task(task5, "task5");

    q.exec_deferred_tasks(0);
}

void test_constructors()
{
    CallGuard cg(__FUNCTION__);
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
}

void test_copy()
{
    CallGuard cg(__FUNCTION__);
    TestClass class1("class1");
    TestClass class2("class2");
    TestClass class3("class3");
    class2 = class1;
    class3 = std::move(class1);
}

int main(int argc, const char* argv[]) {
    // test_constructors();

    test_copy();

    // test_sinks();

    //test_task_queue();
}
