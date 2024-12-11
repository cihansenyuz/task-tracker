#pragma once

#include "taskmanager.hpp"
#include <string>

class Application{
    public:
    Application(const std::string& f);
    ~Application();
    void Exec();
    void Quit();

    private:
    bool running{false};
    enum Selection{ QUIT, ADD, UPDATE, DELETE,
                LIST_ALL, LIST_DONE, LIST_NDONE, LIST_ONGOING };
    TaskManager* task_manager;

    void PrintMenu() const;
    Selection GetUserInput() const;
    void ProcessSelection(Selection user_selection);
    Selection StrToSelection(const std::string& s) const;
};

