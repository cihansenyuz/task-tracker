#include "task.hpp"
#include <iomanip> // Include this header for std::setw
                    // and std::setfill

int Task::id_count = 0;

Task::Task(std::string d)
    : id{++id_count}, descrp{d}, status{TODO} {
    
    auto now = std::chrono::system_clock::now(); // get current time
    std::time_t current_time = std::chrono::system_clock::to_time_t(now); // convert to time_t
    created = *std::localtime(&current_time);
    updated = created;
}

Task::Task(int i,
         const std::string& d,
         Status s,
         const std::tm& c,
         const std::tm& u)
    : id{i}, descrp{d}, status{s}, created{c}, updated{u} {}

std::string Task::ToString() const{
    std::string output = "Task ID: " + std::to_string(id) + " Status: " + StatusToStr(status) + "\n";
    output += "Description: " + descrp + "\n";
    output += "Created: " + TmDateToStr(created);
    output += "Updated: " + TmDateToStr(updated);
    return output;
}

boost::property_tree::ptree Task::ToJson() const{
    boost::property_tree::ptree json_tree;
    json_tree.put("id", id);
    json_tree.put("description", descrp);
    json_tree.put("status", StatusToStr(status));
    json_tree.put("created date", TmDateToStr(created));
    json_tree.put("last update", TmDateToStr(updated));

    return json_tree;
}


void Task::Updated(){
    auto now = std::chrono::system_clock::now(); // get current time
    std::time_t current_time = std::chrono::system_clock::to_time_t(now); // convert to time_t
    updated = *std::localtime(&current_time);
}

std::string Task::StatusToStr(Status s){
    switch(s) {
        case TODO: return "TODO";
        case ONGOING: return "ONGOING";
        case DONE: return "DONE";
    }
    return "INVALID";
}

Task::Status Task::StrToStatus(const std::string& s){
    if(s == "TODO") return TODO;
    if(s == "ONGOING") return ONGOING;
    if(s == "DONE") return DONE;
    return INVALID;
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
void Task::SetLastIdCount(int n) { id_count = n; }

std::tm Task::StrToTmDate(const std::string& date){
    std::tm tm_date;
    tm_date.tm_mday = std::stoi(date.substr(0,2));
    tm_date.tm_mon = std::stoi(date.substr(3,2)) - 1;
    tm_date.tm_year = std::stoi(date.substr(6,4)) - 1900;
    return tm_date;
}

std::string Task::TmDateToStr(const std::tm& date){
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << date.tm_mday << '-'
        << std::setw(2) << std::setfill('0') << date.tm_mon + 1 << '-'
        << date.tm_year+1900 << std::endl;
    
    return oss.str();
}