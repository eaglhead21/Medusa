#pragma once
#include <Arduino.h>
#include <global.h>
#include <sensors.h>
#include <hiPressureLUT.h>
#include <loPressureLUT.h>

void superSubCalc()
{
    superheatTemp = temp1 - loPressureTempLUT;
    subcoolingTemp = hiPressureTempLUT - temp2;
}
    
