#pragma once
#include <Arduino.h>
#include <global.h>
#include <sensors.h>

void loPressureLUT()
{
    if (loPressureValue = 0)
    {
        loPressureTempLUT = TEMP[12];
    }

    if (loPressureValue < 0) //Use this interpolation method if PSIG is negative
    {
        for (int i = 0; i < sizeof(PSIG); i++) // check each constant in the dataset
        {
            if (loPressureValue >= PSIG[i])
            {
                if ((loPressureValue - PSIG[i]) <= 1)
                {
                    loPressureTempLUT = TEMP[i];
                }
            }
        }
    }

    if ((loPressureValue > 0) & (loPressureValue < 70)) //Use this interpolation method if PSIG is between 0 and 70
    {
        for (int i = 0; i < sizeof(PSIG); i++) // check each constant in the dataset
        {
            if (loPressureValue >= PSIG[i])
            {
                if ((loPressureValue - PSIG[i]) <= 1)
                {
                    loPressureTempLUT = TEMP[i];
                }
            }
        }
    }

    if (loPressureValue > 70) //Use this interpolation method if PSIG is greater than 70
    {
        for (int i = 0; i < sizeof(PSIG); i++) // check each constant in the dataset
        {
            if (loPressureValue >= PSIG[i])
            {
                if ((loPressureValue - PSIG[i]) <= 2.5)
                {
                    loPressureTempLUT = TEMP[i];
                }
            }
        }
    }
}
