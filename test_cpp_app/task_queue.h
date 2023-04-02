#pragma once

#include <string>
#include <queue>
#include <functional>

class TaskQueue
{
public:
    using Task = std::function<void(float dt)>;
    /**
    Defer task to execute in main thread
    */
    void defer_task(Task&& task, const std::string comment = "");

    /**
    Defer task to execute in main thread
    */
    void defer_task(Task& task, const std::string comment = "");

    /**
    Execute deferred tasks on main thread
    */
    void exec_deferred_tasks(float dt);

private:
    /**
    deferred tasks queue
    */
    std::queue<Task> tasks;
};
