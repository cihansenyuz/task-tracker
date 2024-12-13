rm start-test 2>/dev/null
clear
g++ -g -std=c++17 test_main.cpp task_fixture.cpp ../src/* -I ../inc/ -o start-test -lgtest
./start-test