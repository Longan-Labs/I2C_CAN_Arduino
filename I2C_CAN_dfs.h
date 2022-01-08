#ifndef __I2C_CAN_DFS_H__
#define __I2C_CAN_DFS_H__

#define DEFAULT_I2C_ADDR    0X25

#define REG_ADDR        0X01
#define REG_DNUM        0x02
#define REG_BAUD        0X03
#define REG_MASK0       0X60
#define REG_MASK1       0X65
#define REG_FILT0       0X70
#define REG_FILT1       0X80
#define REG_FILT2       0X90
#define REG_FILT3       0XA0
#define REG_FILT4       0XB0
#define REG_FILT5       0XC0

#define REG_SEND        0X30
#define REG_RECV        0X40

#define REG_ADDR_SET    0X51


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

#define CAN_OK              (0)
#define CAN_FAILINIT        (1)
#define CAN_FAILTX          (2)
#define CAN_MSGAVAIL        (3)
#define CAN_NOMSG           (4)
#define CAN_CTRLERROR       (5)
#define CAN_GETTXBFTIMEOUT  (6)
#define CAN_SENDMSGTIMEOUT  (7)
#define CAN_FAIL            (0xff)


#endif

// END FILE