#ifndef _SERVICE_H_

#include <stdint.h>
#include <stdbool.h>
#include "fsm.h"

/**
 * Inherits from fsm class
 */

/**
 * Add additional signals on top of those already defined in the parent class.
 */
enum {
  SIG_POWER = MAX_FSM_SIG,
  SIG_NRESET,
  SIG_ENABLE,
  SIG_INPUT,
  SIG_OUTPUT,

  MAX_SERVICE_SIG,
};

struct Service_Class;

typedef struct ServiceEvt {
  Event event;
  uint32_t ownerID;
  uint8_t * message;
  uint32_t length;
} ServiceEvt;

typedef struct ServiceFunctionTable {
  void (*Service_Class)(struct Service_Class*);
  void (*service)(struct Service_Class*);
  void (*inputEvent)(struct Service_Class*, ServiceEvt const * evt);
  void (*outputEvent)(struct Service_Class*, ServiceEvt const * evt);
} ServiceFunctionTable;

typedef struct Service_Class {
  Fsm                     fsm;
  uint32_t                serviceID;
  uint32_t                startTime_us;
  uint32_t                endTime_us;
  bool                    idle;
  ServiceFunctionTable  * functionTable;
} Service_Class;

#endif
