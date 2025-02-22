#include "MTi_Driver.h"

float roll, pitch, yaw;

void MTi_Driver_Init(void) {

}
void MTi_Driver_Step(uint8_t *bytesIn, float euler[3], float quat[4], float bodyRates[3]) {
    uint16_t dataId;
    uint8_t  dataSize;
    // NOTE: for a full Xbus message, the payload begins at 4, for reduced Xbus, 
    // the payload begins at 2 (which is used here)
    int index = 2;  // Start index for reading the payload
    dataId   = extractUint16(bytesIn, &index);
    dataSize = extractUint8(bytesIn, &index);

    if (dataId == 0x2030 && dataSize == 12) {
        // Extract Euler angles: roll, pitch, yaw
        euler[0] = extractFloat(bytesIn, &index); // roll
        euler[1] = extractFloat(bytesIn, &index); // pitch
        euler[2]  = extractFloat(bytesIn, &index); // yaw
    }

    dataId   = extractUint16(bytesIn, &index);
    dataSize = extractUint8(bytesIn, &index);
    if(dataId == 0x2010 && dataSize == 16) {
        // Extract Quaternion (eta first!)
        quat[0] = extractFloat(bytesIn, &index); 
        quat[1] = extractFloat(bytesIn, &index); 
        quat[2]  = extractFloat(bytesIn, &index); 
        quat[3] = extractFloat(bytesIn, &index);
    }

    dataId   = extractUint16(bytesIn, &index);
    dataSize = extractUint8(bytesIn, &index);
    if (dataId == 0x8020 && dataSize == 12) {
        // Extract Body Rates 
        bodyRates[0] = extractFloat(bytesIn, &index); 
        bodyRates[1] = extractFloat(bytesIn, &index); 
        bodyRates[2]  = extractFloat(bytesIn, &index); 
    }
}
 
void MTi_Driver_Terminate(void) {

}