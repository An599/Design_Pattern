#include "Bridge.h"

bool TV::isEnabled() const 
{
    return enabled; 
}
void TV::enable() 
{ 
    enabled = true; 
}
void TV::disable() 
{ 
    enabled = false;
}

int TV::getVolume() const 
{
    return volume; 
}

void TV::setVolume(int vol) 
{ 
    volume = std::max(0, std::min(vol, 100)); 
}

int TV::getChannel() const 
{ 
    return channel; 
}
void TV::setChannel(int ch) 
{
    if (ch > 0) channel = ch; 
}

std::string TV::getName() const 
{ 
    return "TV"; 
}


bool Radio::isEnabled() const 
{ 
    return enabled; 
}
void Radio::enable() 
{ 
    enabled = true; 
}
void Radio::disable() 
{ 
    enabled = false;
}

int Radio::getVolume() const 
{ 
    return volume; 
}
void Radio::setVolume(int vol) 
{ 
    volume = std::max(0, std::min(vol, 100)); 
}

int Radio::getChannel() const 
{ 
    return channel; 
}
void Radio::setChannel(int ch) 
{ 
    if (ch > 0) channel = ch; 
}

std::string Radio::getName() const 
{ 
    return "Radio"; 
}

void RemoteControl::togglePower() 
{
    if (device->isEnabled())
        device->disable();
    else
        device->enable();
}

void RemoteControl::volumeUp() 
{
    device->setVolume(device->getVolume() + 10);
}

void RemoteControl::volumeDown() 
{
    device->setVolume(device->getVolume() - 10);
}

void RemoteControl::channelUp() 
{
    device->setChannel(device->getChannel() + 1);
}

void RemoteControl::channelDown() 
{
    device->setChannel(device->getChannel() - 1);
}


void AdvancedRemoteControl::mute() 
{
    device->setVolume(0);
}
