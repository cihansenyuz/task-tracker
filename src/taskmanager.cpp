#include "taskmanager.hpp"
#include <algorithm>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

void TaskManager::AddTask(const std::string& description){
    tasks.emplace_front(new Task{description});
}

bool TaskManager::UpdateTask(int id, UpdateInfo info){
    for(const auto& task : tasks)
        if(task->GetID() == id){
            task->SetDescription(info.description);
            task->SetStatus(info.status);
            task->Updated();
            return true;
        }
    return false;
}

void TaskManager::DeleteTask(int id){
    tasks.remove_if([id](Task* t){
                            return t->GetID() == id;
                        });
}

const Task* TaskManager::GetTask(int id) const{
    for(const auto& task : tasks)
        if(task->GetID() == id)
            return task;
    
    throw std::exception{}; // not found
}

std::vector<int> TaskManager::GetIdByStatus(Task::Status status) const{
    std::vector<int> task_id_vector;
    for(const auto& task : tasks)
        if(task->GetStatus() == status)
            task_id_vector.push_back(task->GetID());

    return task_id_vector;
}

std::vector<int> TaskManager::GetAllIds() const{
    std::vector<int> task_id_vector;
    for(const auto& task : tasks)
        task_id_vector.push_back(task->GetID());

    return task_id_vector;
}

bool TaskManager::SaveTasksToLocal() const{
    boost::property_tree::ptree json_array;

    for(const auto& task : tasks){
        json_array.push_back(std::make_pair("", task->ToJson()));
    }
    boost::property_tree::ptree json_root;
    json_root.add_child("tasks", json_array);

    try {
        boost::property_tree::write_json("saved-tasks.json", json_root);
        return true;
    }
    catch (const std::exception& e) {
        throw e;
    }
}

bool TaskManager::LoadTasksFromLocal(const std::string& file_path){
    boost::property_tree::ptree json_root;

    try {
        boost::property_tree::read_json(file_path, json_root);
    }
    catch (const std::exception& e) {
        throw e;
    }

    boost::property_tree::ptree tasks_from_file = json_root.get_child("tasks");
    
    for(const auto& task : tasks_from_file){
        const auto& task_data = task.second;

        tasks.emplace_front(new Task{
                                    task_data.get<int>("id"),
                                    task_data.get<std::string>("description"),
                                    Task::StrToStatus(task_data.get<std::string>("status")),
                                    Task::StrToTmDate(task_data.get<std::string>("created date")),
                                    Task::StrToTmDate(task_data.get<std::string>("last update"))
                                }
                            );
    }
    return true;
}