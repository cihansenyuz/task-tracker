#pragma once

#include <string>
#include <chrono>

class Task{
    public:
    Task(std::string descrp);

    enum Status{ TODO, ONGOING, DONE };

    int id;
    std::string descrp;
    Status status;
    std::tm created;
    std::tm updated;
    
    private:
    static int id_count;
};