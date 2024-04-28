#ifndef _FSM_TYPEDEF_H
#define _FSM_TYPEDEF_H

#include <stdint.h>

typedef enum {
    FSM_SENSE = 0,
    FSM_OVERVOLTAGE,
    FSM_OVERVOLTAGE_FAULT
} FSM_STATE_e;

typedef enum {
    HW_SWITCH_PRESSED = 0,
    HW_SWITCH_NOT_PRESSED
} HW_SWITCH_e;

typedef struct {
    FSM_STATE_e state;
    HW_SWITCH_e hw_switch;
    uint8_t fault;
} FSM_t;



#endif
