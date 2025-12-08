#include <iostream>
#include "Bridge.h"

int main() {
    TV tv;
    Radio radio;

    RemoteControl tvRemote(&tv);
    AdvancedRemoteControl radioRemote(&radio);

    std::cout << "DIRECT SET FUNCTION USAGE" << std::endl;
    tv.enable();
    tv.setVolume(45);
    tv.setChannel(7);

    std::cout << "TV (direct set): power=" << tv.isEnabled() << " vol=" << tv.getVolume() << " ch=" << tv.getChannel() << std::endl;

    radio.enable();
    radio.setVolume(20);
    radio.setChannel(95);

    std::cout << "Radio (direct set): power = " << radio.isEnabled() << " vol=" << radio.getVolume() << " ch=" << radio.getChannel() << std::endl <<std::endl;
    std::cout << "REMOTE CONTROL USAGE " <<std::endl;
    tvRemote.togglePower();
    tvRemote.volumeUp();
    tvRemote.channelUp();

    std::cout << "TV (remote used): power=" << tv.isEnabled() << " vol=" << tv.getVolume() << " ch=" << tv.getChannel() << std::endl;

    radioRemote.togglePower();
    radioRemote.volumeDown();
    radioRemote.channelDown();
    radioRemote.mute();

    std::cout << "Radio (remote used): power=" << radio.isEnabled() << " vol=" << radio.getVolume() << " ch=" << radio.getChannel() << std::endl;
    return 0;
}
