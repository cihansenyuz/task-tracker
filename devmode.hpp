#include "task.hpp"
#include "taskmanager.hpp"
#include <iostream>

/**
 * this is where all development tests can be performed
 */
void ExecDevMode(){
    TaskManager tMan;
    tMan.AddTask("this is 1st test task.");
    const Task* selected_task = tMan.GetTask(1);
    if(selected_task)
        std::cout << selected_task->ToString() << std::endl;
    else
        std::cout << "provided task id is not valid" << std::endl;

    tMan.UpdateTask(1, UpdateInfo{selected_task->GetDescription(),
                                  Task::Status::ONGOING});

    std::cout << "after update:\n" << selected_task->ToString() << std::endl;
    tMan.AddTask("this is 2nd test task.");
    tMan.AddTask("this is 3nd test task.");

    tMan.DeleteTask(2);
    for(int i=1; i<=3; i++)
        try { std::cout << tMan.GetTask(i)->ToString() << std::endl; }
        catch(const std::exception& e) { std::cout << "invalid task id: " << i << std::endl; }

    
}