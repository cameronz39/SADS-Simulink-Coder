#ifndef Comm_Driver_h
#define Comm_Driver_h
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "board.h"
#include "main.h"

#define COMM_TX_LEN 33
void Comm_Driver_Init(void);
float Comm_Driver_Step(float eulerAngles[3], float bodyRates[3], int pos[2], char txBuffer[COMM_TX_LEN]);
void Comm_Driver_Terminate(void);

#ifdef __cplusplus
}
#endif
#endif