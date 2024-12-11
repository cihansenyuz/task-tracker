#pragma once

#include <forward_list>
#include <vector>
#include <memory>
#include "task.hpp"
#include "jsonfilemanager.hpp"

struct UpdateInfo {
    std::string description;
    Task::Status status;
};

class TaskManager{
    public:
    TaskManager(const std::string& file_path);
    ~TaskManager();

    int AddTask(const std::string& description);
    bool UpdateTask(int id, UpdateInfo info);
    void DeleteTask(int id);

    const std::shared_ptr<Task> GetTask(int id) const;
    std::vector<int> GetIdByStatus(Task::Status status) const;
    std::vector<int> GetAllIds() const;

    private:
    std::forward_list<std::shared_ptr<Task>> tasks;
    JsonFileManager file_man{&tasks};
    std::string file_path;
};