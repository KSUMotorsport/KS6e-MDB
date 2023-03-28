

#include "TempSensor.h"
#include "SPI_handle.h"


// ------------------------------------------------
// Initializes the SPI pins, mode, and CS

void init_SPI()
{

    SPI.begin();

    SPI.beginTransaction(SPISettings(9600, LSBFIRST, SPI_MODE0));

    pinMode(CHIPSELECT, OUTPUT);

}


// -------------------------------------------------
// Sends through SPI. Maybe this works?

void send_SPI(uint32_t id, uint8_t buf[])
{

    CAN_Frame msg;

    msg.id = id;

    msg.extended = false;

    msg.length = 8;


    // Load buffer with Temperature array 

    for (uint8_t INDEX = 0; INDEX < CHANNELS; INDEX++)
    {

        msg.data[INDEX] = buf[INDEX];

    }

    msg.data[4] = batteryTemp.getAvgTemp();
    msg.data[5] = batteryTemp.getMinTemp();
    msg.data[6] = batteryTemp.getMaxTemp();


  
}

