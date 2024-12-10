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
            case Selection::ADD:
                /* code */
                break;
            case Selection::UPDATE:
                /* code */
                break;
            case Selection::DELETE:
                /* code */
                break;
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

 Application::~Application(){ std::cout << "Quitting the app..." << std::endl; }