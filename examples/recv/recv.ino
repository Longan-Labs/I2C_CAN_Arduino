/*  receive a frame from can bus
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

void setup()
{
    Serial.begin(115200);
    //while(!Serial);
    
    Serial.println("begin to init can");
    
    while (CAN_OK != CAN.begin(CAN_500KBPS))    // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS FAIL!");
        delay(100);
    }
    Serial.println("CAN BUS OK!");
    pinMode(13, OUTPUT);
}


void loop()
{
    unsigned char len = 0;
    unsigned char buf[8];

    if(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
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
    blink();
}

void blink()
{
    static unsigned long timer_s = millis();
    if(millis()-timer_s < 100)return;
    timer_s = millis();
    digitalWrite(13, 1-digitalRead(13));
}
// END FILE
