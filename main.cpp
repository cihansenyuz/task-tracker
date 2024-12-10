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
    std::cout << "created date: " << test.created.tm_mday << '-'
                                  << test.created.tm_mon+1 << '-'
                                  << test.created.tm_year+1900
                                  << std::endl;
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