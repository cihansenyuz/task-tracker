#include "taskmanager.hpp"

void TaskManager::AddTask(const std::string& description){
    tasks.emplace_front(new Task{description});
}

const Task* TaskManager::GetTask(int id) const{
    for(const auto& task : tasks)
        if(task->GetID() == id)
            return task;
    
    return nullptr;
}