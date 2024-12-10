#pragma once

#include <forward_list>
#include "task.hpp"

struct UpdateInfo {
    std::string description;
    Task::Status status;
};

class TaskManager{
    public:
    TaskManager() = default;
    void AddTask(const std::string& description);
    bool UpdateTask(int id, UpdateInfo info);

    const Task* GetTask(int id) const;

    private:
    std::forward_list<Task*> tasks;
};