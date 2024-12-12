#include "application.hpp"
#include <cstring>

#if defined(DEVMODE)
    #include "devmode.hpp"
#endif

constexpr char FILE_PATH[] = "saved-tasks.json";
constexpr char HELP[] = "--help";

int main(int argc, char* argv[]){
    Application app{FILE_PATH};

#if defined(DEVMODE)
    ExecDevMode();
#else
    if(argc == 2 && !strcmp(argv[1], HELP))
        app.Help();
    app.Exec();
#endif

    return EXIT_SUCCESS;
}