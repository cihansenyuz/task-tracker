#pragma once

#include <forward_list>
#include "task.hpp"

class TaskManager{
    public:
    TaskManager() = default;
    void AddTask(const std::string& description);

    const Task* GetTask(int id) const;

    private:
    std::forward_list<Task*> tasks;
};