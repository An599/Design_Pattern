#pragma once
#include <memory>
#include <string>

class TrafficLight;
class LightState 
{
public:
    virtual ~LightState() = default;

    virtual void enter(TrafficLight& light) = 0;
    virtual void handle(TrafficLight& light) = 0;
    virtual std::string name() const = 0;
    virtual int durationSeconds() const = 0;
};
class TrafficLight 
{
public:
    explicit TrafficLight(std::unique_ptr<LightState> initialState);

    void setState(std::unique_ptr<LightState> newState);
    void run(int cycles);
    std::string currentStateName() const;

private:
    std::unique_ptr<LightState> state_;
};

class RedState : public LightState 
{
public:
    void enter(TrafficLight& light) override;
    void handle(TrafficLight& light) override;
    std::string name() const override { return "RED"; }
    int durationSeconds() const override { return 5; }
};

class YellowAfterRed : public LightState 
{
public:
    void enter(TrafficLight& light) override;
    void handle(TrafficLight& light) override;
    std::string name() const override { return "YELLOW"; }
    int durationSeconds() const override { return 2; }
};

class GreenState : public LightState 
{
public:
    void enter(TrafficLight& light) override;
    void handle(TrafficLight& light) override;
    std::string name() const override { return "GREEN"; }
    int durationSeconds() const override { return 4; }
};

class YellowAfterGreen : public LightState 
{
public:
    void enter(TrafficLight& light) override;
    void handle(TrafficLight& light) override;
    std::string name() const override { return "YELLOW"; }
    int durationSeconds() const override { return 2; }
};
