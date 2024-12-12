#pragma once

#include "task.hpp"
#include <forward_list>
#include <memory>

using boost::property_tree::ptree;

/**
 * @brief Responsible for managing task persistence by providing methods
 * to save and load tasks to/from local JSON files. It maintains a
 * pointer to a list of shared task pointers and includes methods
 * for parsing JSON task data and loading files. The class acts as
 * a bridge between the task collection and file storage, facilitating
 * serialization and deserialization of task data.
 * 
 * @author Cihan Şenyüz
 * @date Dec-2024
 */
class JsonFileManager{
    public:
    JsonFileManager(std::forward_list<std::shared_ptr<Task>>* t);

    bool SaveTasksToLocal(const std::string& file_path) const;
    bool LoadTasksFromLocal(const std::string& file_path);

    private:
    std::forward_list<std::shared_ptr<Task>>* tasks;
    
    std::unique_ptr<Task> ParseJsonTaskData(const ptree& json_root) const;
    ptree LoadFile(const std::string& file_path) const;
};