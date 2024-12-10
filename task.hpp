#pragma once

#include <string>
#include <chrono>

class Task{
    public:
    Task(std::string descrp);

    enum Status{ TODO, ONGOING, DONE };

    int GetID() const;
    std::string GetDescription() const;
    Status GetStatus() const;
    std::tm GetCreated() const;
    std::tm GetUpdated() const;
    void SetID(int id);
    void SetDescription(std::string descrp);
    void SetStatus(Status status);
    void SetCreated(std::tm created);
    void SetUpdated(std::tm updated);

    private:
    static int id_count;
    
    int id;
    std::string descrp;
    Status status;
    std::tm created;
    std::tm updated;

    public:

};