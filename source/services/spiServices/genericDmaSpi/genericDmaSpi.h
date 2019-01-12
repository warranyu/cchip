#ifndef _GENERICDMASPI_H_

#include <stdint.h>
#include "../../dmaServices/genericDma/genericDma.h"

typedef struct genericDmaSpiInterface_t {
  const uint8_t * powerRail;
  const uint8_t * reset;

} genericDmaSpiInterface_t;

typedef struct genericDmaSpiOutput_t {

} genericDmaSpiOutput_t;

typedef struct genericDmaSpiInput_t {
  genericDmaInput_t * dmaConfig;
  
} genericDmaSpiInput_t;

typedef enum genericDmaSpiError_t {
  ERRNONE,
} genericDmaSpiError_t;

typedef enum genericDmaSpiStates_t {
  UNPOWERED,
  UNINITIALIZED,
  INITIALIZING,
  IDLE,
} genericDmaSpiStates_t;

genericDmaSpiError_t genericDmaSpiRegisterInterface(genericDmaSpiInterface_t * interface);

genericDmaSpiError_t genericDmaSpiService(void);

genericDmaSpiError_t genericDmaSpiRead(genericDmaSpiOutput_t * output);

genericDmaSpiError_t genericDmaSpiWrite(genericDmaSpiInput_t * input);

#endif
