#ifndef _GENERICSERVICE_H_

#include <stdint.h>
#include "fsm/fsm.h"

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

  MAX_GENERICSERVICE_SIG,
};

struct GenericService_Class;

typedef struct GenericServiceFunctionTable_t {
  void (*GenericService_Class)(struct GenericService_Class*);
  void (*service)(struct GenericService_Class*);
  void (*inputEvent)(struct GenericService_Class*, uint8_t * msg, uint32_t length);
  void (*outputEvent)(struct GenericService_Class*, uint8_t * msg, uint32_t length);
} GenericServiceFunctionTable_t;

typedef struct GenericService_Class {
  Fsm_t fsm;
  uint32_t serviceID;
  uint32_t startTime_us;
  uint32_t endTime_us;
  GenericServiceFunctionTable_t * functionTable;
} GenericService_Class;

typedef struct ServiceEvent {
  EventClass event;
  uint32_t ownerID;
} ServiceEvent;

#endif
