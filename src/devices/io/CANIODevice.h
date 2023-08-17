/*
 * CANIODevice.h parent of canbus connected devices that can extent the system I/O.
 * does not specifically handle canopen for devices that use it. However, most devices can be
 * pretty easily faked for canopen support. Just register for messages that contain the device ID
 * as the lower 7 bits and allow all upper 4 bit patterns through. For canopen you have to
 * send on ID 0 but you aren't going to be receiving.

Copyright (c) 2015 Collin Kidder, Michael Neuweiler, Charles Galpin

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 */

#pragma once
#include <Arduino.h>
#include "../Device.h"
#include "../DeviceTypes.h"
#include "../../CanHandler.h"
#include "ExtIODevice.h"

class CanIODeviceConfiguration : public ExtIODeviceConfiguration {
public:
    uint8_t canbusNum;
};

class CANIODevice : public ExtIODevice, public CanObserver
{
public:
	CANIODevice(void);

	void setup();
    void tearDown();
    void handleCanFrame(const CAN_message_t &);
    void loadConfiguration();
    void saveConfiguration();
    void handleMessage(uint32_t msg, void* data);
};

