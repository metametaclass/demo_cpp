#include "task_queue.h"
#include "iostream"
#include "format"

void TaskQueue::defer_task(Task&& task, const std::string comment)
{
    std::cout << std::format("defer_task(&&{})", comment) << std::endl;
    tasks.emplace(std::move(task));
}

void TaskQueue::defer_task(Task& task, const std::string comment)
{
    std::cout << std::format("defer_task(&{})", comment) << std::endl;
    tasks.emplace(task);
}

void TaskQueue::exec_deferred_tasks(float dt)
{
    std::queue<Task> deferred_tasks;
    {
        deferred_tasks.swap(tasks);
    }

    while (!deferred_tasks.empty())
    {
        const Task& task = deferred_tasks.front();
        task(dt);
        deferred_tasks.pop();
    }
}

