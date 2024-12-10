#include "task.hpp"

Task::Task(std::string d)
    : descrp{d} {

    // create random id
    auto now = std::chrono::system_clock::now(); // get current time
    std::time_t current_time = std::chrono::system_clock::to_time_t(now); // convert to time_t
    created = *std::localtime(&current_time);
    
}