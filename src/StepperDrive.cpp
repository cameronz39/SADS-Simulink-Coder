#include "StepperDrive.h"
#include "main.h"
#include "board.h"
#include "xbus.h"

static char toggleState1;

int currentPos1;

extern "C" void StepperDrive_Init(void) {
   toggleState1 = 0;

   currentPos1 = 0;
}

extern "C" void StepperDrive_Step(int desiredPos1, int desiredPos2) {
    if (desiredPos1 > currentPos1) {
        DIR4_GPIO_Port->BSRR = DIR4_Pin;
        if (toggleState1 == 0) { // rising edge: set STEP high
            STEP4_GPIO_Port->BSRR = STEP4_Pin;
            
            toggleState1 = 1;
        } else { // falling edge: set STEP low and update position
            STEP4_GPIO_Port->BSRR = (STEP4_Pin << 16);
            
            toggleState1 = 0;
            currentPos1++;
        }
    } else if (desiredPos1 < currentPos1) {
        DIR4_GPIO_Port->BSRR = (DIR4_Pin << 16);
        if (toggleState1 == 0) { // rising edge: set STEP high
            STEP4_GPIO_Port->BSRR = STEP4_Pin;
            
            toggleState1 = 1;
        } else { // falling edge: set STEP low and update position
            STEP4_GPIO_Port->BSRR = (STEP4_Pin << 16);
            
            toggleState1 = 0;
            currentPos1--;
        }
    }   
}

extern "C" void StepperDrive_Terminate(void) {

}

