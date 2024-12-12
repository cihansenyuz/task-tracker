#include "application.hpp"
#include <iostream>
#include <unordered_map>

void Application::Exec(){
    running = true;

    while(running){
        PrintMenu();
        ProcessSelection(GetUserInput());
    }
}

void Application::PrintMenu() const{
    std::cout << "Menu:" << std::endl;
    std::cout << "0. Quit" << std::endl;
    std::cout << "1. Add a New" << std::endl;
    std::cout << "2. Update a Task" << std::endl;
    std::cout << "3. Delete a Task" << std::endl;
    std::cout << "4. List All Tasks" << std::endl;
    std::cout << "5. List Done Tasks" << std::endl;
    std::cout << "6. List Not Done Tasks" << std::endl;
    std::cout << "7. List Ongoing Tasks" << std::endl;
    std::cout << "Enter your selection: ";
}

Application::Selection Application::GetUserInput() const{
    std::string user_selection;
    std::getline(std::cin, user_selection);
    return StrToSelection(user_selection);
}

void Application::ProcessSelection(Application::Selection user_selection){
        try{
        switch (user_selection) {
            case Selection::QUIT:
                running = false;
                break;
            case Selection::ADD: AddAction(); break;
            case Selection::UPDATE: UpdateAction(); break;
            case Selection::DELETE: DeleteAction(); break;
            case Selection::LIST_ALL:
                /* code */
                break;
            case Selection::LIST_DONE:
                /* code */
                break;
            case Selection::LIST_NDONE:
                /* code */
                break;
            case Selection::LIST_ONGOING:
                /* code */
                break;
        }
    }
    catch(const std::exception& e){
        std::cout << "Selection is not valid, try again: " << std::endl;
    }
}

Application::Selection Application::StrToSelection(const std::string& s) const{
    std::unordered_map<std::string, Selection> convertion_map = {
                                                                    {"0", QUIT},
                                                                    {"1", ADD},
                                                                    {"2", UPDATE},
                                                                    {"3", DELETE},
                                                                    {"4", LIST_ALL},
                                                                    {"5", LIST_DONE},
                                                                    {"6", LIST_NDONE},
                                                                    {"7", LIST_ONGOING}
                                                                };

    if(convertion_map.count(s) == 0)
        throw std::exception{}; // invalid input
    
    return convertion_map[s];
}

 Application::Application(const std::string& file_path)
    : task_manager{std::make_unique<TaskManager>(file_path)} {
    std::cout << "Loading the app..." << std::endl;
}

 Application::~Application(){ 
    std::cout << "Quitting the app..." << std::endl;
}

void Application::AddAction(){
    std::cout << "Enter the description: ";
    std::string input;
    std::getline(std::cin, input);
    int task_id = task_manager->AddTask(input);
    std::cout << "Created task:" << std::endl;
    std::cout << task_manager->GetTask(task_id)->ToString() << std::endl;
}

void Application::UpdateAction(){
    std::cout << "Enter the task id: ";
    std::string input;
    std::getline(std::cin, input);
    auto selected_task = task_manager->GetTask(std::stoi(input));
    std::cout << "Selected task:" << std::endl;
    std::cout << selected_task->ToString() << std::endl;

    UpdateInfo new_info;
    std::cout << "Enter new status(TODO, ONGOING, DONE): ";
    std::getline(std::cin, input);
    new_info.status = Task::StrToStatus(input);

    std::cout << "Enter new description: ";
    std::getline(std::cin, input);
    new_info.description = input;

    task_manager->UpdateTask(selected_task->GetID(), new_info);
    std::cout << "Updated task:" << std::endl;
    std::cout << selected_task->ToString() << std::endl;
}

void Application::DeleteAction(){
    std::cout << "Enter the task id to delete: ";
    std::string input;
    std::getline(std::cin, input);
    task_manager->DeleteTask(std::stoi(input));
    std::cout << "Task is deleted." << std::endl;
}