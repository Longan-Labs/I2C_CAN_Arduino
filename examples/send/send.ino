/*  send a frame from can bus
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


I2C_CAN CAN(0x25);                                    // Set CS pin

void setup()
{
    Serial.begin(115200);

    while (CAN_OK != CAN.begin(CAN_500KBPS))    // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS FAIL!");
        delay(100);
    }
    Serial.println("CAN BUS OK!");
}

unsigned char stmp[8] = {1, 2, 3, 4, 5, 6, 7, 0};
int cnt = 0;

void loop()
{
    stmp[7] = cnt++;
    if(cnt > 100)cnt = 0;
    
    CAN.sendMsgBuf(0x01, 0, 8, stmp);
    delay(5);                       // send data per 100ms
}

// END FILE
