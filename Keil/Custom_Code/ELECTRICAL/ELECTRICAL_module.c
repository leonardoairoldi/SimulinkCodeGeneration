#include "ELECTRICAL_module.h"

void hwswitch_state_set(void) {
  if(GET_SWITCH_STATE() == 1) 
		SMKACADEMY.fsm.hw_switch = 1;
	else
		SMKACADEMY.fsm.hw_switch = 0;
}
