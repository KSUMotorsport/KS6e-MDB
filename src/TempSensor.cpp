

#include "TempSensor.h"
#include "MDB_Labels.h"



// ------------------------------------------------
// Input pins for the NANO
 
//                  A    B    C    D
 int tempPins[] = {PF7, PF6, PF5, PF4};


// ----------------------------------------------------
// Updates the temps from each pins into an array

void TempSensor::updateTemp()
{

    for (int CHANNEL = 0; CHANNEL < CHANNELS; CHANNEL++)
    {

        this->tempSensor.temp[CHANNEL] = this->data.read(tempPins[CHANNEL]);

    }

}


// ----------------------------------------------------
// Returns the temperture of a channel (A B C D)

uint8_t TempSensor::getTemp(int channel)
{

    return this->tempSensor.temp[channel];

}


// ------------------------------------------------------
// Averages all channels into one temperature reading

void TempSensor::AvgTemp()
{

   for (int CHANNEL = 0; CHANNEL < CHANNELS; CHANNEL++)
   {

        this->tempSensor.temp[CHANNEL] += this->tempSensor.avgTemp;

   }

}


// ------------------------------------------------------
// Returns an array of average temperatures

uint8_t TempSensor::getAvgTemp()
{

    return this->tempSensor.avgTemp;

}

