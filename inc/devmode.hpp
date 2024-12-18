#include "task.hpp"
#include "taskmanager.hpp"
#include <iostream>

/**
 * this is where all development tests can be performed
 */
void ExecDevMode(){
    constexpr char FILE_PATH[] = "saved-tasks.json";
    
    try{
        TaskManager tMan{FILE_PATH};
        // tMan.AddTask("this is 7nd test task.");
        // const Task* selected_task = tMan.GetTask(1);
        // if(selected_task)
        //     std::cout << selected_task->ToString() << std::endl;
        // else
        //     std::cout << "provided task id is not valid" << std::endl;

        // tMan.UpdateTask(1, UpdateInfo{selected_task->GetDescription(),
        //                             Task::Status::ONGOING});

        // std::cout << "after update:\n" << selected_task->ToString() << std::endl;
        // tMan.AddTask("this is 2nd test task.");
        // tMan.AddTask("this is 3nd test task.");
        // tMan.AddTask("this is 4nd test task.");
        // tMan.AddTask("this is 5nd test task.");
        // tMan.AddTask("this is 6nd test task.");

        // tMan.UpdateTask(4, UpdateInfo{tMan.GetTask(4)->GetDescription(),
                                    // Task::Status::DONE});

        // tMan.DeleteTask(2);
        // for(int i=1; i<=6; i++)
        //     try { std::cout << tMan.GetTask(i)->ToString() << std::endl; }
        //     catch(const std::exception& e) { std::cout << "invalid task id: " << i << std::endl; }

        // std::cout << "list of TODOs:" << std::endl;
        // auto ids = tMan.GetIdByStatus(Task::Status::TODO);
        // for(const auto id : ids)
        //     std::cout << tMan.GetTask(id)->ToString() << std::endl;

        for(int i=1; i<=8; i++)
            try {
                std::cout << tMan.GetTask(i)->ToString() << std::endl;
                std::cout << "use count: " << tMan.GetTask(i).use_count() << std::endl;
            }
            catch(const std::exception& e) { std::cout << "invalid task id: " << i << std::endl; }

        // std::cout << Task::TmDateToStr(Task::StrToTmDate("25-11-2024")) << std::endl;
    }
    catch(const char* msg){ 
        std::cout << "Error: " << msg << std::endl;
    }
}