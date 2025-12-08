#pragma once
#include <string>
#include <algorithm>

class IDevice {
public:
    virtual ~IDevice() = default;

    virtual bool isEnabled() const = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;

    virtual int getVolume() const = 0;
    virtual void setVolume(int vol) = 0;

    virtual int getChannel() const = 0;
    virtual void setChannel(int ch) = 0;

    virtual std::string getName() const = 0;
};
class TV : public IDevice {
private:
    bool enabled = false;
    int volume = 30;
    int channel = 1;

public:
    bool isEnabled() const override;
    void enable() override;
    void disable() override;
    int getVolume() const override;
    void setVolume(int vol) override;
    int getChannel() const override;
    void setChannel(int ch) override;
    std::string getName() const override;
};

class Radio : public IDevice {
private:
    bool enabled = false;
    int volume = 50;
    int channel = 101;

public:
    bool isEnabled() const override;
    void enable() override;
    void disable() override;
    int getVolume() const override;
    void setVolume(int vol) override;
    int getChannel() const override;
    void setChannel(int ch) override;
    std::string getName() const override;
};

class RemoteControl {
protected:
    IDevice* device;

public:
    RemoteControl(IDevice* d) : device(d) {}

    virtual void togglePower();
    virtual void volumeUp();
    virtual void volumeDown();
    virtual void channelUp();
    virtual void channelDown();
};

class AdvancedRemoteControl : public RemoteControl {
public:
    AdvancedRemoteControl(IDevice* d) : RemoteControl(d) {}
    void mute();
};
