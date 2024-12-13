## PROJECT INFORMATION
This project is a practical example of object-oriented programming using newer standards of the language C++.
You can find CRC models of components in conceptual design pdf and UML class diagrams in technical design pdf
under doc folder.

The project based on the project described here; https://roadmap.sh/projects/task-tracker

## PREREQUISITES
Make sure that g++ is installed on your machine and its version supports at least C++17.

Make sure boost is installed on your machine. If not, run the code below.

`$ sudo apt-get install libboost-all-dev`

Make sure gTest is installed on your machine. If not, run the code below.

`$ sudo apt install libgtest-dev`

You may need to manually build the gtest libraries after installing the libgtest-dev package. You will need to have cmake and GNU make.

```
cd /usr/src/gtest
sudo cmake .
sudo make
sudo cp *.a /usr/lib
```

## HOW TO RUN
The project includes a bash script to compile the project and run it. To run the script,
run the code below to provide writing permissions, once your current working directory is the project directory.
This is needed for the first time only.

`$ chmod +x compileNrun.sh`

Then, run the following.

`$ ./compileNrun.sh`

Optionally, if you want to change something or try something as a developer,
use the header file "devmode.hpp" and modify ExecDevMode() behaviour. Then,
run the script, providing the flag -DDEVMODE. This will invoke ExecDevMode()
function instead normal behaviour.

`$ ./compileNrun.sh -DDEVMODE`

To get help about how to use the application, pass --help argument to the application.
This will print a guide for the application.

`$ ./app --help`

## HOW TO TEST
The project uses gTest to do unit testing. Test sources is under gTest folder.
The folder includes compileNrun-test.sh script to compile and start testing.
# Note: Test is only for Task component. This is subject to change, including other components.

`$ ./compileNrun-test.sh`

## AUTHOR
This project is developed by Cihan Şenyüz in the Dec of 2024.

Contact: cihansenyuz@hotmail.com
