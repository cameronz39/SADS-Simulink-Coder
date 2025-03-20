#include "StepperDrive.h"
#include "main.h"
#include "board.h"
#include "xbus.h"

static char toggleState1;
static char toggleState2;
int currentPos1;
int currentPos2;

extern "C" void StepperDrive_Init(void) {
   toggleState1 = 0;
   toggleState1 = 0;
   currentPos1 = 0;
   currentPos2 = 0; 
}

extern "C" void StepperDrive_Step(int desiredPos1, int desiredPos2) {
    if (currentPos1 < desiredPos1) {
        DIR3_GPIO_Port->BSRR = (DIR3_Pin << 16);
        DIR4_GPIO_Port->BSRR = DIR4_Pin;
        
        if (toggleState1 == 0) { // rising edge: set STEP high
            STEP3_GPIO_Port->BSRR = STEP3_Pin;
            STEP4_GPIO_Port->BSRR = STEP4_Pin;
            toggleState1 = 1;
        } else { // falling edge: set STEP low and update position
            STEP3_GPIO_Port->BSRR = (STEP3_Pin << 16);
            STEP4_GPIO_Port->BSRR = (STEP4_Pin << 16);
            toggleState1 = 0;
            currentPos1++;
        }
    } else if (currentPos1 > desiredPos1) {
        DIR3_GPIO_Port->BSRR = DIR3_Pin;
        DIR4_GPIO_Port->BSRR = (DIR4_Pin << 16); 
        if (toggleState1 == 0) { // rising edge: set STEP high
            STEP3_GPIO_Port->BSRR = STEP3_Pin;
            STEP4_GPIO_Port->BSRR = STEP4_Pin;
            toggleState1 = 1;
        } else { // falling edge: set STEP low and update position
            STEP3_GPIO_Port->BSRR = (STEP3_Pin << 16);
            STEP4_GPIO_Port->BSRR = (STEP4_Pin << 16);
            toggleState1 = 0;
            currentPos1--;
        }
    }

    if (currentPos2 < desiredPos2) {
        DIR1_GPIO_Port->BSRR = (DIR1_Pin << 16);
        DIR2_GPIO_Port->BSRR = DIR2_Pin;
        
        if (toggleState2 == 0) { // rising edge: set STEP high
            STEP1_GPIO_Port->BSRR = STEP1_Pin;
            STEP2_GPIO_Port->BSRR = STEP2_Pin;
            toggleState2 = 1;
        } else { // falling edge: set STEP low and update position
            STEP1_GPIO_Port->BSRR = (STEP1_Pin << 16);
            STEP2_GPIO_Port->BSRR = (STEP2_Pin << 16);
            toggleState2 = 0;
            currentPos2++;
        }
    } else if (currentPos2 > desiredPos2) {
        DIR1_GPIO_Port->BSRR = DIR1_Pin;
        DIR2_GPIO_Port->BSRR = (DIR2_Pin << 16); 
        if (toggleState2 == 0) { // rising edge: set STEP high
            STEP1_GPIO_Port->BSRR = STEP1_Pin;
            STEP2_GPIO_Port->BSRR = STEP2_Pin;
            toggleState2 = 1;
        } else { // falling edge: set STEP low and update position
            STEP1_GPIO_Port->BSRR = (STEP1_Pin << 16);
            STEP2_GPIO_Port->BSRR = (STEP2_Pin << 16);
            toggleState2 = 0;
            currentPos2--;
        }
    }   
}

extern "C" void StepperDrive_Terminate(void) {

}

