#ifndef ELECTRICAL_MODULE_H
#define ELECTRICAL_MODULE_H

#include <stdint.h>
#include "main.h"
#include "GLOBAL_typedef.h"

#define GET_SWITCH_STATE() (HAL_GPIO_ReadPin(USRBTN_GPIO_Port, USRBTN_Pin) == GPIO_PIN_SET ? 1 : 0)

void switch_state_set(void);

#endif // ELECTRICAL_MODULE_H
