#include "jsonfilemanager.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

JsonFileManager::JsonFileManager(std::forward_list<std::shared_ptr<Task>>* t)
    : tasks{t} {}

bool JsonFileManager::SaveTasksToLocal(const std::string& file_path) const{
    ptree json_array;

    for(const auto& task : *tasks){
        json_array.push_back(std::make_pair("", task->ToJson()));
    }
    ptree json_root;
    json_root.add_child("tasks", json_array);

    try {
        boost::property_tree::write_json(file_path, json_root);
        return true;
    }
    catch (const std::exception& e) {
        throw e;
    }
}

bool JsonFileManager::LoadTasksFromLocal(const std::string& file_path){
    ptree file = LoadFile(file_path);
    int last_id = 0;

    for(const auto& task : file){
        const auto& task_data = task.second;

        tasks->emplace_front(std::move(ParseJsonTaskData(task_data)));
        int current_id = tasks->front()->GetID();
        if(current_id > last_id)
            last_id = current_id;
    }

    Task::SetLastIdCount(last_id);
    return true;
}

std::unique_ptr<Task> JsonFileManager::ParseJsonTaskData(const ptree& task_data) const{
        return std::make_unique<Task>(
                        task_data.get<int>("id"),
                        task_data.get<std::string>("description"),
                        Task::StrToStatus(task_data.get<std::string>("status")),
                        Task::StrToTmDate(task_data.get<std::string>("created date")),
                        Task::StrToTmDate(task_data.get<std::string>("last update"))
                    );
}

ptree JsonFileManager::LoadFile(const std::string& file_path) const{
    ptree json_root;

    try {
        boost::property_tree::read_json(file_path, json_root);
    }
    catch (const std::exception& e) {
        throw "couldnot read the json file";
    }

    return json_root.get_child("tasks");
}