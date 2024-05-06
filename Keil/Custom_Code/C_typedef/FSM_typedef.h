#ifndef _FSM_TYPEDEF_H
#define _FSM_TYPEDEF_H

#include <stdint.h>

typedef enum {
  FAULT = 0,
	TS_OFF,
	PRECHARGE,
	TS_ON
} FSM_STATE_e;

typedef struct {
    FSM_STATE_e state;
    uint8_t hw_switch;
		uint8_t tPrecharge;
    uint8_t fault;
} FSM_t;



#endif
