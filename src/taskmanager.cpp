#include "taskmanager.hpp"
#include <algorithm>

TaskManager::TaskManager(const std::string& file_path) : file_path{file_path} {
    file_man.LoadTasksFromLocal(file_path);
}

TaskManager::~TaskManager(){
    file_man.SaveTasksToLocal(file_path);
}

int TaskManager::AddTask(const std::string& description){
    tasks.emplace_front(std::make_shared<Task>(description));
    return tasks.front()->GetID();
}

bool TaskManager::UpdateTask(int id, UpdateInfo info){
    for(const auto& task : tasks)
        if(task->GetID() == id){
            if(info.description.size())
                task->SetDescription(info.description);
            if(info.status != Task::INVALID)
                task->SetStatus(info.status);
            
            task->Updated();
            return true;
        }
    return false;
}

void TaskManager::DeleteTask(int id){
    tasks.remove_if([id](std::shared_ptr<Task> t){
                            return t->GetID() == id;
                        });
}

const std::shared_ptr<Task> TaskManager::GetTask(int id) const{
    for(const auto& task : tasks)
        if(task->GetID() == id)
            return std::shared_ptr<Task>(task);
    
    throw std::runtime_error{"Task with ID " + std::to_string(id) + " not found."};
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

