#include "task.hpp"

int Task::id_count = 0;

Task::Task(std::string d)
    : id{++id_count}, descrp{d}, status{TODO} {
    
    auto now = std::chrono::system_clock::now(); // get current time
    std::time_t current_time = std::chrono::system_clock::to_time_t(now); // convert to time_t
    created = *std::localtime(&current_time);

}

int Task::GetID() const { return id; }
Task::Status Task::GetStatus() const { return status; }
std::tm Task::GetCreated() const { return created; }
std::tm Task::GetUpdated() const { return updated; }
void Task::SetID(int id) { this->id = id; }
void Task::SetDescription(std::string descrp) { this->descrp = descrp; }
void Task::SetStatus(Status status) { this->status = status; }
void Task::SetCreated(std::tm created) { this->created = created; }
void Task::SetUpdated(std::tm updated) { this->updated = updated; }

