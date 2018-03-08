#include "Blink.h"

#include <Arduino.h>

namespace g3rb3n
{

    Blink::Blink():
        pin(PIN), lowState(OFF), highState(ON)
    {
        pinMode(pin, OUTPUT);
    }

    Blink::Blink(uint8_t _pin):
        pin(_pin), lowState(OFF), highState(ON)
    {
        pinMode(pin, OUTPUT);
    }

    Blink::Blink(uint8_t _lowState, uint8_t _highState):
        pin(PIN), lowState(_lowState), highState(_highState)
    {
        pinMode(pin, OUTPUT);
    }

    Blink::Blink(uint8_t _pin, uint8_t _lowState, uint8_t _highState):
    pin(_pin), lowState(_lowState), highState(_highState)
    {
        pinMode(pin, OUTPUT);
    }

    Blink::~Blink()
    {}

    void Blink::setInterval(long _interval)
    {
        high = _interval;
        low = _interval;
    }

    void Blink::setIntervals(long _low, long _high)
    {
        low = _low;
        high = _high;
    }

    uint32_t Blink::next(){
        uint32_t interval = state ? high : low;
        return interval * 1000;
    }

    void Blink::handle()
    {
        state = !state;
        digitalWrite(pin, state ? highState : lowState);
    }

}
