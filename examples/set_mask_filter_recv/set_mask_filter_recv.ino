/*  receive a frame from can bus with mask and filter setting
    support@longan-labs.cc

    CAN Baudrate,
    
    #define CAN_5KBPS           1
    #define CAN_10KBPS          2
    #define CAN_20KBPS          3
    #define CAN_25KBPS          4 
    #define CAN_31K25BPS        5
    #define CAN_33KBPS          6
    #define CAN_40KBPS          7
    #define CAN_50KBPS          8
    #define CAN_80KBPS          9
    #define CAN_83K3BPS         10
    #define CAN_95KBPS          11
    #define CAN_100KBPS         12
    #define CAN_125KBPS         13
    #define CAN_200KBPS         14
    #define CAN_250KBPS         15
    #define CAN_500KBPS         16
    #define CAN_666KBPS         17
    #define CAN_1000KBPS        18
*/

#include <Wire.h>
#include "Longan_I2C_CAN_Arduino.h"

I2C_CAN CAN(0x25);                                    // Set I2C Address


unsigned char flagRecv = 0;
unsigned char len = 0;
unsigned char buf[8];
char str[20];

void setup()
{
    Serial.begin(115200);
    
    while (CAN_OK != CAN.begin(CAN_500KBPS))    // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS FAIL!");
        delay(100);
    }
    Serial.println("CAN BUS OK!");
    

    /*
     * set mask, set both the mask to 0x3ff
     */
    CAN.init_Mask(0, 0, 0x7ff);                         // there are 2 mask in mcp2515, you need to set both of them
    CAN.init_Mask(1, 0, 0x7ff);

    /*
     * set filter, we can receive id from 0x04 ~ 0x09
     */
    CAN.init_Filt(0, 0, 0x1);                          // there are 6 filter in mcp2515
    CAN.init_Filt(1, 0, 0x2);                          // there are 6 filter in mcp2515

    CAN.init_Filt(2, 0, 0x3);                          // there are 6 filter in mcp2515
    CAN.init_Filt(3, 0, 0x4);                          // there are 6 filter in mcp2515
    CAN.init_Filt(4, 0, 0x5);                          // there are 6 filter in mcp2515
    CAN.init_Filt(5, 0, 0x6);                          // there are 6 filter in mcp2515
}

void loop()
{
    if(CAN_MSGAVAIL == CAN.checkReceive())                   // check if get data
    {
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

        if(len)
        {
            unsigned long canId = CAN.getCanId();

            Serial.print("Get ID: ");
            Serial.println(canId, HEX);
            
            for(int i = 0; i<len; i++)    // print the data
            {
                Serial.print(buf[i], HEX);
                Serial.print("\t");
            }
            Serial.println();
        }
    }
    
    delay(10);
}

// END FILE
