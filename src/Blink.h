#ifndef _Blink_H
#define _Blink_H

#if defined(ARDUINO_ARCH_ESP8266)
    #define PIN LED_BUILTIN
    #define ON LOW
    #define OFF HIGH
#elif defined(ARDUINO_ARCH_AVR)
    #define PIN 13
    #define ON HIGH
    #define OFF LOW
#else
    #warning "No builtin led defined"
#endif

#include <Arduino.h>
#include <inttypes.h>
#include "InterruptTimerDispatcher.h"
#include "InterruptHandler.h"

namespace g3rb3n
{

    class Blink : public InterruptHandler
    {
    
    private:
        uint8_t pin = PIN;
        long high = 100;
        long low = 900;
        uint8_t lowState = OFF;
        uint8_t highState = ON;
        uint32_t cycle;
    public:
        bool state = false;
        uint32_t count = 0;

    public:
        Blink();
        Blink(uint8_t pin);
        Blink(uint8_t _lowState, uint8_t _highState);
        Blink(uint8_t pin, uint8_t _lowState, uint8_t _highState);
        ~Blink();

        void setInterval(long interval);
        void setIntervals(long low, long high);
        void handle();
        uint32_t next();
    };
}

#endif
