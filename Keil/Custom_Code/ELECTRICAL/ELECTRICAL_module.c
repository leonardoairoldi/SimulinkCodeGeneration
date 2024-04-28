#include "ELECTRICAL_module.h"

void switch_state_set(void) {
  if(GET_SWITCH_STATE() == 1) 
		SMKACADEMY.electrical.switch_state = SWITCH_CLOSED;
	else
		SMKACADEMY.electrical.switch_state = SWITTCH_OPEN;
}
