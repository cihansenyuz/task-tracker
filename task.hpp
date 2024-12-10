#pragma once

#include <string>
#include <chrono>

class Task{
    public:
    Task(std::string d);

    enum Status{ TODO, ONGOING, DONE };

    std::string id;
    std::string descrp;
    Status status;
    std::tm created;
    std::tm updated;
};

