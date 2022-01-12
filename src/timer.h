#pragma once
#include <Arduino.h>
#include <sensors.h>
#include <global.h>

void timerStart()
{
    timeStart = millis();
}

void timeStop()
{
    timeInterval = (millis() - timeStart);
}