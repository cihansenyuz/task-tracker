#pragma once

#include "task.hpp"
#include <forward_list>

using boost::property_tree::ptree;

class JsonFileManager{
    public:
    JsonFileManager(std::forward_list<Task*>* t);

    bool SaveTasksToLocal(const std::string& file_path) const;
    bool LoadTasksFromLocal(const std::string& file_path);

    private:
    std::forward_list<Task*>* tasks;
    
    Task* ParseJsonTaskData(const ptree& json_root) const;
    ptree LoadFile(const std::string& file_path) const;
};