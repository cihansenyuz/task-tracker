#pragma once

#include "task.hpp"
#include <forward_list>
#include <memory>

using boost::property_tree::ptree;

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