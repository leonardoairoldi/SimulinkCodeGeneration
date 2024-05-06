#ifndef ELECTRICAL_TYPEDEF_H
#define ELECTRICAL_TYPEDEF_H

#include <stdint.h>


typedef enum {
    SWITCH_OPEN = 0,
		SWITCH_PRECHARGE,
    SWITCH_DISCHARGE,
		SWITCH_CLOSED
} SWITCH_STATE_e;

typedef struct {
    uint16_t vTSAcc;   // V
    uint16_t vSumOfCells;  // V
    uint8_t perSOC;   // mW
		uint16_t iTSAcc; // mA
    SWITCH_STATE_e switch_state;
} ELECTRICAL_t;


#endif // ELECTRICAL_TYPEDEF_H
