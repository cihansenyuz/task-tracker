#pragma once

#include <string>
#include <chrono>
#include <boost/property_tree/ptree.hpp>

/**
 * represents a task management system with properties like ID, description,
 * status, creation, and update times. It provides static utility methods
 * for converting between string and status representations, as well as
 * date handling. The class supports creating tasks either by user input
 * or when loading from a persistent storage, with methods to get and set
 * task attributes, convert to string or JSON format, and track the last used ID.
 * 
 * @author Cihan Şenyüz
 * @date Dec-2024
 */
class Task{
    public:
    enum Status{ INVALID, TODO, ONGOING, DONE };
    static std::string StatusToStr(Status s);
    static Status StrToStatus(const std::string& s);
    static std::tm StrToTmDate(const std::string& date);
    static std::string TmDateToStr(const std::tm& date);

    Task(std::string descrp); // for user creation
    Task(int i,                 // for loading creation
         const std::string& d,
         Status s,
         const std::tm& c,
         const std::tm& u); 

    std::string ToString() const;
    boost::property_tree::ptree ToJson() const;
    void Updated();

    int GetID() const;
    std::string GetDescription() const;
    Status GetStatus() const;
    std::tm GetCreated() const;
    std::tm GetUpdated() const;
    void SetID(int id);
    void SetDescription(std::string descrp);
    void SetStatus(Status status);
    void SetCreated(std::tm created);
    void SetUpdated(std::tm updated);
    static void SetLastIdCount(int n);

    private:
    static int id_count;
    
    int id;
    std::string descrp;
    Status status;
    std::tm created;
    std::tm updated;
};