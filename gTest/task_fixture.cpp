#include <gtest/gtest.h>
#include "task.hpp"
#include <ctime>

/** necessary to compare tm type dates */
bool operator==(const std::tm& lhs, const std::tm& rhs) {
    return (lhs.tm_mday == rhs.tm_mday
            && lhs.tm_mon == rhs.tm_mon
            && lhs.tm_year == rhs.tm_year);
}

class Task_Fixture : public ::testing::Test {
protected:
    Task t1{"task1 description"};
    Task t2{2,
            "task2 description",
            Task::StrToStatus("TODO"),
            Task::StrToTmDate("11-12-2024"),
            Task::StrToTmDate("13-12-2024") };
    Task t3{"task1 description"};

    std::tm today;

    void SetUp() override {
        auto now = std::chrono::system_clock::now(); // get current time
        std::time_t current_time = std::chrono::system_clock::to_time_t(now); // convert to time_t
        today = *std::localtime(&current_time);
    }

    void TearDown() override {

    }
};

TEST_F(Task_Fixture, TestGetStatus_WhenInitialized_ThenIsTODO){
    EXPECT_EQ(t1.GetStatus(), Task::TODO);
    EXPECT_EQ(t2.GetStatus(), Task::TODO);
}

TEST_F(Task_Fixture, TestGetCreated_WhenInitialized_Then){
    EXPECT_EQ(t1.GetCreated(), today);
    EXPECT_EQ(t2.GetCreated(), Task::StrToTmDate("11-12-2024"));
}

TEST_F(Task_Fixture, TestGetters_WhenSettersUsed_ThenEqualsToSetValues){
    t3.SetStatus(Task::ONGOING);
    t3.SetCreated(Task::StrToTmDate("11-12-2024"));
    t3.SetID(33);
    t3.SetDescription("set description");
    t3.SetUpdated(Task::StrToTmDate("15-12-2024"));

    EXPECT_EQ(t3.GetStatus(), Task::ONGOING);
    EXPECT_EQ(t3.GetCreated(), Task::StrToTmDate("11-12-2024"));
    EXPECT_EQ(t3.GetID(), 33);
    EXPECT_EQ(t3.GetDescription(), "set description");
    EXPECT_EQ(t3.GetUpdated(), Task::StrToTmDate("15-12-2024"));
}

TEST_F(Task_Fixture, TestUpdated_When_ThenEqualsToToday){
    t3.Updated();

    EXPECT_EQ(t3.GetUpdated(), today);
}

TEST_F(Task_Fixture, TestSetLastIdCount) {
    Task::SetLastIdCount(100);
    Task t4{"new task"};
    EXPECT_EQ(t4.GetID(), 101);
}

TEST_F(Task_Fixture, TestToJson) {
    auto json = t1.ToJson();
    EXPECT_EQ(json.get<std::string>("description"), "task1 description");
    EXPECT_EQ(json.get<std::string>("status"), "TODO");
}