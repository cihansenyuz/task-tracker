#include "task.hpp"

int Task::id_count = 0;

Task::Task(std::string d)
    : id{++id_count}, descrp{d}, status{TODO} {
    
    auto now = std::chrono::system_clock::now(); // get current time
    std::time_t current_time = std::chrono::system_clock::to_time_t(now); // convert to time_t
    created = *std::localtime(&current_time);

}