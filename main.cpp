#include "application.hpp"

#if defined(DEVMODE)
    #include "task.hpp"
    #include <iostream>
#endif
/**
 * place where all development tests can be performed
 */
void ExecDevMode(){
    Task test{"this is test task."};
    std::cout << test.ToString() << std::endl;
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