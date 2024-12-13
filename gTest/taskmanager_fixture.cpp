#include <gtest/gtest.h>
#include "taskmanager.hpp"

class TaskManager_Fixture : public ::testing::Test {
protected:
    TaskManager t_m1{"saved-tasks-test.json"};

    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(TaskManager_Fixture, AddTaskTest){
    int id = -1;
    id = t_m1.AddTask("New Task by AddTask");
    ASSERT_NE(id, -1);
    
    auto task = t_m1.GetTask(id);
    EXPECT_EQ(task->GetDescription(), "New Task by AddTask");
}

TEST_F(TaskManager_Fixture, UpdateTaskTest){
    EXPECT_NO_THROW(auto task = t_m1.GetTask(2));
    auto task = t_m1.GetTask(2);

    Task::Status pre_status = task->GetStatus();
    bool success = t_m1.UpdateTask(2, UpdateInfo{"Updated Task by UpdateTask", Task::StrToStatus("")});
    ASSERT_TRUE(success);
    EXPECT_EQ(task->GetDescription(), "Updated Task by UpdateTask");
    EXPECT_EQ(task->GetStatus(), pre_status);

    std::string pre_description = task->GetDescription();
    success = t_m1.UpdateTask(2, UpdateInfo{"", Task::StrToStatus("DONE")});
    ASSERT_TRUE(success);
    EXPECT_EQ(task->GetDescription(), pre_description);
    EXPECT_EQ(task->GetStatus(), Task::Status::DONE);

    success = t_m1.UpdateTask(2, UpdateInfo{"Updated again", Task::StrToStatus("ONGOING")});
    ASSERT_TRUE(success);
    EXPECT_EQ(task->GetDescription(), "Updated again");
    EXPECT_EQ(task->GetStatus(), Task::Status::ONGOING);

    success = t_m1.UpdateTask(30, UpdateInfo{"Updated again", Task::StrToStatus("ONGOING")});
    ASSERT_FALSE(success);
}

TEST_F(TaskManager_Fixture, GetTaskThrowsException) {
    EXPECT_THROW({
        t_m1.GetTask(999);
    }, std::runtime_error);
}