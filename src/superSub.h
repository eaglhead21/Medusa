#pragma once
#include <Arduino.h>
#include <global.h>
#include <sensors.h>
#include <hiPressureLUT.h>
#include <loPressureLUT.h>

void superSubCalc()
{
    superheatTemp = temp6 - loPressureTempLUT;
    subcoolingTemp = hiPressureTempLUT - temp4;
}
    
