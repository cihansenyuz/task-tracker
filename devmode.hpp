#include "task.hpp"
#include "taskmanager.hpp"
#include <iostream>

/**
 * this is where all development tests can be performed
 */
void ExecDevMode(){
    Task test{"this is a test task."};
    std::cout << test.ToString() << std::endl;

    TaskManager tMan;
    tMan.AddTask("this is another test task.");
    const Task* selected_task = tMan.GetTask(2);
    if(selected_task)
        std::cout << selected_task->ToString() << std::endl;
    else
        std::cout << "provided task id is not valid" << std::endl;

    tMan.UpdateTask(2, UpdateInfo{selected_task->GetDescription(),
                                  Task::Status::ONGOING});

    std::cout << "after update:\n" << selected_task->ToString() << std::endl;
}