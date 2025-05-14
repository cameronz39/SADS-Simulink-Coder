#include "MTi_Driver.h"

float roll, pitch, yaw;

void MTi_Driver_Init(void) {

}
void MTi_Driver_Step(uint8_t *bytesIn, float g_body[3], float quat[4], float bodyRates[3], float eulerAngles[3], uint16_t *debug) {
    uint16_t dataId;
    uint8_t  dataSize;
    // NOTE: for a full Xbus message, the payload begins at 4, for reduced Xbus, 
    // the payload begins at 2 (which is used here)
    int index = 2;  // Start index for reading the payload
    dataId   = extractUint16(bytesIn, &index);
    dataSize = extractUint8(bytesIn, &index);

    *debug = dataId;
    float rotMatrix[9];
    if (dataId == 0x2020 && dataSize == 36) {
        // Extract rotation matrix, (matrix takes a vector from the body frame to the inertial frame)
        rotMatrix[0] = extractFloat(bytesIn, &index); 
        rotMatrix[1] = extractFloat(bytesIn, &index);
        rotMatrix[2]  = extractFloat(bytesIn, &index);
        rotMatrix[3] = extractFloat(bytesIn, &index);
        rotMatrix[4] = extractFloat(bytesIn, &index);
        rotMatrix[5]  = extractFloat(bytesIn, &index);
        rotMatrix[6] = extractFloat(bytesIn, &index);
        rotMatrix[7] = extractFloat(bytesIn, &index);
        rotMatrix[8]  = extractFloat(bytesIn, &index);
    }

    g_body[0] = rotMatrix[2]*-9.81;
    g_body[1] = rotMatrix[5]*-9.81;
    g_body[2] = rotMatrix[8]*-9.81;

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

    dataId   = extractUint16(bytesIn, &index);
	dataSize = extractUint8(bytesIn, &index);
	if (dataId == 0x2030) {
        // Extract Euler Angles
	    eulerAngles[0] = extractFloat(bytesIn, &index);
	    eulerAngles[1] = extractFloat(bytesIn, &index);
	    eulerAngles[2] = extractFloat(bytesIn, &index);
	}
}
 
void MTi_Driver_Terminate(void) {

}