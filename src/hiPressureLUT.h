#pragma once
#include <Arduino.h>
#include <global.h>
#include <sensors.h>

void hiPressureLUT()
{
    if ((hiPressurePSI > 100) & (hiPressurePSI <= 180)) //Use this interpolation method if PSIG is between 0 and 70
    {
        for (int i = 0; (i < sizeof(PSIG)); i++) // check each constant in the dataset
        {
            if (hiPressurePSI >= PSIG[i])
            {
                if ((hiPressurePSI - PSIG[i]) <= 2.5)
                {
                    hiPressureTempLUT = TEMP[i];
                }
            }
        }
    }

    else
    { 
        hiPressureTempLUT = NULL; 
    }

}