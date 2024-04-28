#ifndef ELECTRICAL_TYPEDEF_H
#define ELECTRICAL_TYPEDEF_H

#include <stdint.h>


typedef enum {
    SWITCH_CLOSED = 0,
    SWITTCH_OPEN
} SWITCH_STATE_e;

typedef struct {
    uint16_t Vin;   // mV
    uint16_t Vout;  // mV
    uint16_t Pin;   // mW
    SWITCH_STATE_e switch_state;
} ELECTRICAL_t;


#endif // ELECTRICAL_TYPEDEF_H
