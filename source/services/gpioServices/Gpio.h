#ifndef _GPIO_H_

#include <stdint.h>
#include "Service.h"

struct Gpio_Class;

typedef enum GpioCommand {
  READBANK,
  WRITEBANK,
  READPIN,
  WRITEPIN,
  TOGGLEPIN,
} GpioCommand;

typedef struct GpioEvt {
  ServiceEvt serviceEvt;
  GpioCommand command;
  uint8_t gpioNumber;
  uint32_t value;
} GpioEvt;

typedef struct Gpio_FunctionTable {
  void (*Gpio_Class)(struct Gpio_Class *);
} Gpio_FunctionTable;

typedef struct Gpio_Class {
  Service_Class service;
  GpioEvt gpioEvt;
  uint32_t bankID;
  uint32_t bankSize;
  uint32_t directionMask;
  Gpio_FunctionTable * functionTable;
} Gpio_Class;

void Gpio_constructor(Gpio_Class *);

#endif
