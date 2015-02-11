#ifndef NEXA_SELFLEARNING_RECEIVER_H
#define NEXA_SELFLEARNING_RECEIVER_H

#include "Arduino.h"

class NexaSelfLearningReceiver{

public:
    NexaSelfLearningReceiver(uint8_t pin, uint8_t led = NULL);
    uint64_t receiveSignal(uint32_t* transmitter, bool* on, bool* group, uint8_t* channel, short* dim, unsigned long timeout = 100);
    
private:
    inline bool isDuplicateSignal(const uint64_t* receivedData) const;

    uint8_t rxPin;
    uint8_t rxLED;
    uint64_t prevReceivedData;
    unsigned long prevReceivedDataTime;
    
};

#endif  //NEXA_SELFLEARNING_RECEIVER_H