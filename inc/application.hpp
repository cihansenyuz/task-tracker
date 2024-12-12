#pragma once

#include "taskmanager.hpp"
#include <string>
#include <memory>

class Application{
    public:
    Application(const std::string& f);
    ~Application();
    void Exec();
    void Quit();

    private:
    bool running{false};
    std::unique_ptr<TaskManager> task_manager;

    enum Selection{ QUIT, ADD, UPDATE, DELETE,
                LIST_ALL, LIST_DONE, LIST_NDONE, LIST_ONGOING };
    Selection StrToSelection(const std::string& s) const;
    
    void PrintMenu() const;
    Selection GetUserInput() const;
    void ProcessSelection(Selection user_selection);
    
    void AddAction();
    void UpdateAction();
    void DeleteAction();
    void ListAllAction();
    void ListActionByStatus(Task::Status status);
};

