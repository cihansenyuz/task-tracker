#include "application.hpp"

#if defined(DEVMODE)
    #include "devmode.hpp"
#endif

int main(){
    Application app;

#if defined(DEVMODE)
    ExecDevMode();
#else
    app.Exec();
#endif

    return EXIT_SUCCESS;
}