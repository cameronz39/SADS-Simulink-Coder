#ifndef MTi_Driver_h
#define MTi_Driver_h
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <board.h>
#include <main.h>
#include <xbus.h>

void MTi_Driver_Init(void);
void MTi_Driver_Step(uint8_t *bytesIn, float g_body[3], float quat[4], float bodyRates[3], float eulerAngles[3], uint16_t *debug);
void MTi_Driver_Terminate(void);

#ifdef __cplusplus
}
#endif
#endif