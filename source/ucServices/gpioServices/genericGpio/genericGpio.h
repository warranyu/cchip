#ifndef _GENERICGPIO_H_

#include <stdint.h>
#include "../../../utils/genericService.h"

struct GenericGpio_Class;

typedef enum GenericGpioCommand{
  READBANK,
  WRITEBANK,
  READPIN,
  WRITEPIN,
  TOGGLEPIN,
} GenericGpioCommand;

typedef struct genericGpioMsg {
  GenericGpioCommand command;
  uint8_t gpioNumber;
  uint32_t value;
} genericGpioMsg;

typedef struct GenericGpio_FunctionTable {
  void (*GenericGpio_Class)(struct GenericGpio_Class *);
} GenericGpio_FunctionTable;

typedef struct GenericGpio_Class {
  GenericService_Class service;
  uint32_t bankID;
  uint32_t bankSize;
  uint32_t directionMask;
  GenericGpio_FunctionTable * functionTable;
} GenericGpio_Class;

typedef struct GpioEvent {
  ServiceEvent serviceEvent;
} GpioEvent;

void GenericGpio_constructor(GenericGpio_Class *);

#endif
