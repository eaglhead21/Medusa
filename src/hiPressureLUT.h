#pragma once
#include <Arduino.h>
#include <global.h>
#include <sensors.h>

void hiPressureLUT()
{
    if (hiPressureValue = 0)
    {
        hiPressureTempLUT = TEMP[12];
    }

    if (hiPressureValue < 0) //Use this interpolation method if PSIG is negative
    {
        for (int i = 0; i < sizeof(PSIG); i++) // check each constant in the dataset
        {
            if (hiPressureValue >= PSIG[i])
            {
                if ((hiPressureValue - PSIG[i]) <= 1)
                {
                    hiPressureTempLUT = TEMP[i];
                }
            }
        }
    }

    if ((hiPressureValue > 0) & (hiPressureValue < 70)) //Use this interpolation method if PSIG is between 0 and 70
    {
        for (int i = 0; i < sizeof(PSIG); i++) // check each constant in the dataset
        {
            if (hiPressureValue >= PSIG[i])
            {
                if ((hiPressureValue - PSIG[i]) <= 1)
                {
                    hiPressureTempLUT = TEMP[i];
                }
            }
        }
    }

    if (hiPressureValue > 70) //Use this interpolation method if PSIG is greater than 70
    {
        for (int i = 0; i < sizeof(PSIG); i++) // check each constant in the dataset
        {
            if (hiPressureValue >= PSIG[i])
            {
                if ((hiPressureValue - PSIG[i]) <= 2.5)
                {
                    hiPressureTempLUT = TEMP[i];
                }
            }
        }
    } 
}