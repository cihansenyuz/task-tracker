rm start-test 2>/dev/null
rm saved-tasks-test.json 2>/dev/null
touch saved-tasks-test.json
echo    '{
            "tasks": [
                {
                    "id": "1",
                    "description": "Initial Task 1",
                    "status": "TODO",
                    "created date": "13-12-2024\n",
                    "last update": "13-12-2024\n"
                },
                {
                    "id": "2",
                    "description": "Initial Task 2",
                    "status": "TODO",
                    "created date": "13-12-2024\n",
                    "last update": "13-12-2024\n"
                }
            ]
        }' > saved-tasks-test.json
clear
g++ -g -std=c++17 test_main.cpp task_fixture.cpp taskmanager_fixture.cpp ../src/* -I ../inc/ -o start-test -lgtest
./start-test