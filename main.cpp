#include "application.hpp"

#if defined(DEVMODE)
    #include "devmode.hpp"
#endif

constexpr char FILE_PATH[] = "saved-tasks.json";

int main(){
    Application app{FILE_PATH};

#if defined(DEVMODE)
    ExecDevMode();
#else
    app.Exec();
#endif

    return EXIT_SUCCESS;
}