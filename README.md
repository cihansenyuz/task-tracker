# PROJECT INFORMATION
This project is to do OOP practice using newer standards of the language C++
The project bases on the project described here; https://roadmap.sh/projects/task-tracker

# PREREQUISITES
Make sure that g++ is installed on your machine and its version supports at least C++17.

# HOW TO RUN
Projects includes a bash script to compile the project and run it.

Simply prompt the following, once your current working directory is the project directory:
$ ./compileNrun.sh

Optionally, if you want to change something or try something as a developer,
use the header file "devmode.hpp" and modify ExecDevMode() behaviour. Then,
run the script, providing the flag -DDEVMODE

$ ./compileNrun.sh -DDEVMODE

This will invoke ExecDevMode() function instead normal behaviour.

# AUTHOR
This project is developed by Cihan Şenyüz in the Dec of 2024.
Contact: cihansenyuz@hotmail.com