

#include "TempSensor.h"
#include "MDB_Labels.h"



// ------------------------------------------------
// Input pins for the NANO

//                 A   B   C   D
// int tempPins[] = {18, 19, 20, 21};


// ---------------------------------------------------
// Input pins for the uno

int tempPins[] = {PC0, PC1, PC2, PC3};



// ----------------------------------------------------
// Updates the temps from each pins into an array

void TempSensor::updateTemp()
{

    for (uint8_t CHANNEL = 0; CHANNEL < CHANNELS; CHANNEL++)
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

    uint8_t averageTemperature = 0;

   for (int CHANNEL = 0; CHANNEL < CHANNELS; CHANNEL++)
   {

        this->tempSensor.temp[CHANNEL] += averageTemperature;

   }

   this->tempSensor.avgTemp = this->tempSensor.avgTemp / CHANNELS;

}


// ------------------------------------------------------
// Returns an array of average temperatures

uint8_t TempSensor::getAvgTemp()
{

    return this->tempSensor.avgTemp;

}

