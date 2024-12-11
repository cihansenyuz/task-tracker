#pragma once

#include <forward_list>
#include <vector>
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
    void DeleteTask(int id);

    const Task* GetTask(int id) const;
    std::vector<int> GetIdByStatus(Task::Status status) const;
    std::vector<int> GetAllIds() const;

    private:
    std::forward_list<Task*> tasks;
};