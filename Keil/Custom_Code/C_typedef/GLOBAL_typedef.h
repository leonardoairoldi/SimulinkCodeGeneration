#ifndef GLOBAL_TYPEDEF_H
#define GLOBAL_TYPEDEF_H

#include <stdint.h>

#ifndef MATLAB_MEX_FILE
#include "ELECTRICAL_typedef.h"
#include "FSM_typedef.h"
#else
#include "Keil/Custom_Code/C_typedef/ELECTRICAL_typedef.h"
#include "Keil/Custom_Code/C_typedef/FSM_typedef.h"
#endif 

typedef struct {
    ELECTRICAL_t electrical;
    FSM_t fsm;
} GLOBAL_t;

extern GLOBAL_t SMKACADEMY;

#endif // GLOBAL_TYPEDEF_H
