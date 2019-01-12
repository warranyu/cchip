#ifndef _GENERICSPI_H_

#include <stdint.h>
#include "../../gpioServices/genericGpio/genericGpio.h"

typedef struct genericSpiOutput_t {

} genericSpiOutput_t;

typedef struct genericSpiInput_t {
  const genericGpioOutput_t * chipSelect;
  const uint32_t baud;

} genericSpiInput_t;

#endif
