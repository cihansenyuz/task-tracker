#include "taskmanager.hpp"

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