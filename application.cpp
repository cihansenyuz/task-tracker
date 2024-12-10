#include "application.hpp"
#include <iostream>
#include <unordered_map>

void Application::Exec(){
    running = true;

    while(running){
        PrintMenu();
        // get user input
        // process user input
    }
}

Application::Selection Application::GetUserInput(){
    std::string userSelection;
    std::getline(std::cin, userSelection);
    
    try{
        switch (StrToSelection(userSelection)) {
            case Selection::OPT1:
                /* code */
                break;
            
            case Selection::OPT2:
                /* code */
                break;
            
            case Selection::QUIT:
                running = false;
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
                                                                    {"1", OPT1},
                                                                    {"2", OPT2}
                                                                };

    if(convertion_map.count(s) == 0)
        throw std::exception{}; // invalid input
    
    return convertion_map[s];
}