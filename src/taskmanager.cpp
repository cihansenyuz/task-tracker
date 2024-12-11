#include "taskmanager.hpp"
#include "jsonfilemanager.hpp"

#include <algorithm>

TaskManager::TaskManager(){
    JsonFileManager file_man{&tasks};
    file_man.LoadTasksFromLocal("saved-tasks.json");
}

TaskManager::~TaskManager(){
    JsonFileManager file_man{&tasks};
    file_man.SaveTasksToLocal();
}

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

