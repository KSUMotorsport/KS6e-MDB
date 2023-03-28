

#include "TempSensor.h"
#include "MDB_Labels.h"



// ------------------------------------------------
// Input pins for the NANO

//                 A   B   C   D
// int tempPins[] = {18, 19, 20, 21};


// ---------------------------------------------------
// Input pins for the uno

int tempPins[] = {PF7, PF6, PF5, PF4};



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

uint8_t *TempSensor::getTemp()
{

    return this->tempSensor.temp;

}


// ------------------------------------------------------
// Averages all channels into one temperature reading

void TempSensor::AvgTemp()
{

    uint8_t averageTemperature = 0;

    for (int CHANNEL = 0; CHANNEL < CHANNELS; CHANNEL++)
    {

        averageTemperature += this->tempSensor.temp[CHANNEL];

    }

    this->tempSensor.avgTemp = averageTemperature / CHANNELS;

}


// ------------------------------------------------------
// Returns an array of average temperatures

uint8_t TempSensor::getAvgTemp()
{

    return this->tempSensor.avgTemp;

}



uint8_t TempSensor::getMinTemp()
{

    for (int CHANNEL = 0; CHANNEL < CHANNELS; CHANNEL++)
    {



    } 

}



uint8_t TempSensor::getMaxTemp()
{

    for (int CHANNEL = 0; CHANNEL < CHANNELS; CHANNEL++)
    {

        

    } 

}

