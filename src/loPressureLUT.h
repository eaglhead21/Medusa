#pragma once
#include <Arduino.h>
#include <global.h>
#include <sensors.h>

void loPressureLUT()
{
    if ((loPressurePSI > 4) & (loPressurePSI <= 70)) //Use this interpolation method if PSIG is between 0 and 70
    {
        for (int i = 0; i < sizeof(PSIG); i++) // check each constant in the dataset
        {
            if (loPressurePSI >= PSIG[i])
            {
                if ((loPressurePSI - PSIG[i]) <= 1)
                {
                    loPressureTempLUT = TEMP[i];
                }
            }
        }
    }

    if (loPressurePSI > 70 & (loPressurePSI <= 180)) //Use this interpolation method if PSIG is greater than 70
    {
        for (int i = 0; i < sizeof(PSIG); i++) // check each constant in the dataset
        {
            if (loPressurePSI >= PSIG[i])
            {
                if ((loPressurePSI - PSIG[i]) <= 2.5)
                {
                    loPressureTempLUT = TEMP[i];
                }
            }
        }
    }
}
