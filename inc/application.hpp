#pragma once

#include "taskmanager.hpp"
#include <string>
#include <memory>

/**
 * A task management system that provides a menu-driven interface
 * for interacting with tasks. It supports core operations like
 * adding, updating, deleting, and listing tasks through an enumerated
 * selection menu, utilizing a TaskManager to handle the underlying
 * task data. The class is designed to manage the application's state
 * and provide a comprehensive, interactive experience for users to
 * manipulate and view their tasks efficiently.
 * 
 * @author Cihan Şenyüz
 * @date Dec-2024
 */
class Application{
    public:
    Application(const std::string& f);
    ~Application();
    void Exec();
    void Quit();
    void Help() const;

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

