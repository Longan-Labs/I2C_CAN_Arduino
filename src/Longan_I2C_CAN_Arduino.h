#ifndef __LONGAN_I2C_CAN_ARDUINO_H__
#define __LONGAN_I2C_CAN_ARDUINO_H__

#include <Arduino.h>
#include <Wire.h>
#include "I2C_CAN_dfs.h"

#define MCP_CAN I2C_CAN

class I2C_CAN{

private:

    unsigned char IIC_ADDR;
    unsigned long m_ID;
    unsigned char m_RTR;
    unsigned char m_EXT;
    
    unsigned char makeCheckSum(unsigned char *dta, int len);
    
public:
    void begin();
    void IIC_CAN_SetReg(unsigned char __reg, unsigned char __len, unsigned char *__dta);
    void IIC_CAN_SetReg(unsigned char __reg, unsigned char __dta);
    bool IIC_CAN_GetReg(unsigned char __reg, unsigned char *__dta);
    bool IIC_CAN_GetReg(unsigned char __reg, int len, unsigned char *__dta);
    
public:
    
    I2C_CAN(unsigned char __addr);
    byte begin(byte speedset);                                      // init can
    byte init_Mask(byte num, byte ext, unsigned long ulData);       // init Masks
    byte init_Filt(byte num, byte ext, unsigned long ulData);       // init filters
    byte sendMsgBuf(unsigned long id, byte ext, byte rtr, byte len, byte *buf);     // send buf
    byte sendMsgBuf(unsigned long id, byte ext, byte len, byte *buf);               // send buf
    byte readMsgBuf(byte *len, byte *buf);                          // read buf
    byte readMsgBufID(unsigned long *ID, byte *len, byte *buf);     // read buf with object ID
    byte checkReceive(void);                                        // if something received
    byte checkError(void);                                          // if something error
    unsigned long getCanId(void);                                   // get can id when receive
    byte isRemoteRequest(void);                                     // get RR flag when receive
    byte isExtendedFrame(void);                                     // did we recieve 29bit frame?

    
};

#endif