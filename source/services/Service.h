#ifndef _SERVICE_H_

#include <stdint.h>
#include "fsm.h"

/**
 * Inherits from fsm class
 */

/**
 * Add additional signals on top of those already defined in the parent class.
 */
enum {
  SIG_POWER = MAX_FSM_SIG,
  SIG_RESET,
  SIG_ENABLE,
  SIG_INPUT,
  SIG_OUTPUT,

  MAX_SERVICE_SIG,
};

struct Service_Class;

typedef struct ServiceMsg {
  Event event;
  uint32_t ownerID;
  uint8_t * message;
  uint32_t length;
} ServiceMsg;

typedef struct ServiceFunctionTable {
  void (*Service_Class)(struct Service_Class*);
  void (*service)(struct Service_Class*);
  void (*inputEvent)(struct Service_Class*, ServiceMsg * msg);
  void (*outputEvent)(struct Service_Class*, ServiceMsg * msg);
} ServiceFunctionTable;

typedef struct Service_Class {
  Fsm fsm;
  uint32_t serviceID;
  uint32_t startTime_us;
  uint32_t endTime_us;
  ServiceFunctionTable * functionTable;
} Service_Class;

#endif
