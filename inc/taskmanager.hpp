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

/**
 * @brief This class serves as a central management system for tasks,
 * providing methods to add, update, delete, and retrieve tasks. It
 * maintains a list of tasks and uses a JsonFileManager to handle
 * file-based persistence. The class offers functionality to manipulate
 * tasks by their unique IDs, filter tasks by status, and manage the
 * overall task collection with methods for adding, updating, and
 * retrieving task information.
 * 
 * @author Cihan Şenyüz
 * @date Dec-2024
 */
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