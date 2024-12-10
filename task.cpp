#include "task.hpp"

int Task::id_count = 0;

Task::Task(std::string d)
    : id{++id_count}, descrp{d}, status{TODO} {
    
    auto now = std::chrono::system_clock::now(); // get current time
    std::time_t current_time = std::chrono::system_clock::to_time_t(now); // convert to time_t
    created = *std::localtime(&current_time);
    updated = created;

}

std::string Task::ToString() const{
    std::string output = "Task ID: " + std::to_string(id) + " Status: " + StatusToStr(status) + "\n";
    output += "Description: " + descrp + "\n";
    output += "Created: " + std::to_string(created.tm_mday)
                    + '-' + std::to_string(created.tm_mon+1)
                    + '-' + std::to_string(created.tm_year+1900) + "\n";
    output += "Updated: " + std::to_string(updated.tm_mday)
                    + '-' + std::to_string(updated.tm_mon+1)
                    + '-' + std::to_string(updated.tm_year+1900) + "\n";
    return output;
}

std::string Task::StatusToStr(Status s){
    switch(s) {
        case TODO: return "TODO";
        case ONGOING: return "ONGOING";
        case DONE: return "DONE";
    }
    return "INVALID";
}

int Task::GetID() const { return id; }
std::string Task::GetDescription() const { return descrp; }
Task::Status Task::GetStatus() const { return status; }
std::tm Task::GetCreated() const { return created; }
std::tm Task::GetUpdated() const { return updated; }
void Task::SetID(int id) { this->id = id; }
void Task::SetDescription(std::string descrp) { this->descrp = descrp; }
void Task::SetStatus(Status status) { this->status = status; }
void Task::SetCreated(std::tm created) { this->created = created; }
void Task::SetUpdated(std::tm updated) { this->updated = updated; }

