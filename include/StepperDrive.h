#ifndef StepperDrive_h
#define StepperDrive_h
#ifdef __cplusplus
extern "C" {
#endif


void StepperDrive_Init(void);
void StepperDrive_Step(int desiredPos1, int desiredPos2);
void StepperDrive_Terminate(void);

#ifdef __cplusplus
}
#endif
#endif