# Longan Labs I2C CAN Bus Module Library

[![Actions Status](https://github.com/arduino/arduino-cli-example/workflows/test/badge.svg)](https://github.com/arduino/arduino-cli-example/actions)
[![Spell Check](https://github.com/arduino/compile-sketches/workflows/Spell%20Check/badge.svg)](https://github.com/arduino/compile-sketches/actions?workflow=Spell+Check)
[![codecov](https://codecov.io/gh/arduino/compile-sketches/branch/main/graph/badge.svg?token=Uv6f1ebMZ4)](https://codecov.io/gh/arduino/compile-sketches)

We launched the Serial CAN Bus Module years ago, which is very practial and easy to use. 
Now we have slightly modified the Serial CAN Bus Module, wrote a special firmware, and launched this I2C CAN Bus Module.

The I2C CAN Bus Module uses I2C for communication. The board is small and flexible, which make it can be quickly used in any system with an I2C interface.

The I2C CAN Bus Module is based on the high-performance MCP2515 CAN Bus controller and MCP2551 CAN Bus transceiver, provides a CAN Bus communication rate of up to 1Mb/s.

In addition, there is an Atmega168PA microcontroller on the board, you can also program it through a USB to Serial board, modify the firmware or write your application directly. 

With this library, you can,

1. Send a CAN2.0 frame
2. Receive a CAN2.0 frame
3. Get data from OBD-II
4. Set the masks and filters, there're 32 masks and filters. 

## Installation

1. [Download the library](https://github.com/Longan-Labs/I2C_CAN_Arduino/archive/refs/heads/main.zip)
2. Extract the zip file
3. In the Arduino IDe, navigate to Sketch > Include Library > Add .ZIP Library

## Respository Contents

* [**/examples**](./examples) - Example sketches for the library (.ino). Run these from the Arduino IDE.
* [**/src**](./src) - Source files for the library (.cpp, .h).
* [**keywords.txt**](./keywords.txt) - Keywords from this library that will be highlighted in the Arduino IDE.
* [**library.properties**](./library.properties) - General library properties for the Arduino package manager.

## Functions

- begin()
- sendMsgBuf()
- readMsgBuf()
- readMsgBufID()
- init_Mask()
- init_Filt()
- checkReceive()
- getCanId()
- isRemoteRequest()
- isExtendedFrame


## Examples

here are many examples implemented in this library. One of the examples is below. You can find other examples [here](./examples)

```Cpp

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

```

## Get a Dev Board

If you need a Dev board, plese try,

- [I2C CAN Bus Module](https://www.longan-labs.cc/1030017.html)

You can get others CAN Dev board below,

- [Serial CAN Bus Module](https://www.longan-labs.cc/1030001.html)
- [CAN Bus Shield for Arduino](https://www.longan-labs.cc/1030016.html)
- [CANBed V1](https://www.longan-labs.cc/1030008.html)
- [CANBed M0](https://www.longan-labs.cc/1030014.html)
- [OBD-II CAN Bus GPS Dev Kit](https://www.longan-labs.cc/1030003.html)

## License

```
MIT License

Copyright (c) 2018 @ Longan Labs

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## Contact us

If you have any question, please feel free to contact [support@longan-labs.cc](support@longan-labs.cc)


[![Analytics](https://ga-beacon.appspot.com/UA-101965714-1/I2C_CAN_Arduino)](https://github.com/igrigorik/ga-beacon)
