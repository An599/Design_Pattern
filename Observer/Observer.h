#pragma once
#include <string>
#include <vector>
#include <mutex>

class IObserver 
{
public:
    virtual ~IObserver() = default;
    virtual void onNotify(const std::string& message) = 0;
};

class NotificationManager 
{
public:
    void subscribe(IObserver* obs);
    void unsubscribe(IObserver* obs);
    void notify(const std::string& msg);

private:
    std::vector<IObserver*> observers;
    std::mutex mtx;
};

class ConsoleObserver : public IObserver 
{
public:
    ConsoleObserver(const std::string& name);
    void onNotify(const std::string& message) override;

private:
    std::string name;
};
