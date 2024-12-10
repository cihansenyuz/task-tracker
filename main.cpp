#include "application.hpp"

#if defined(DEVMODE)
    #include "task.hpp"
    #include "taskmanager.hpp"
    #include <iostream>
#endif
/**
 * this is where all development tests can be performed
 */
void ExecDevMode(){
    Task test{"this is a test task."};
    std::cout << test.ToString() << std::endl;

    TaskManager tMan;
    tMan.AddTask("this is another test task.");
    Task* selected_task = tMan.GetTask(3);
    if(selected_task)
        std::cout << selected_task->ToString() << std::endl;
    else
        std::cout << "provided task id is not valid" << std::endl;

}

int main(){
    Application app;

#if defined(DEVMODE)
    ExecDevMode();
#else
    app.Exec();
#endif

    return EXIT_SUCCESS;
}