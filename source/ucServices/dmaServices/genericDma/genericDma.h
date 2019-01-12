#ifndef _GENERICDMA_H_

#include <stdint.h>

typedef struct genericDmaInterface_t {
  const uint8_t * powerRail;
  const uint8_t * reset;
} genericDmaInterface_t;

typedef struct genericDmaInput_t {
  const uint8_t * channel;
  const uint32_t * source;
  const uint32_t * destination;
} genericDmaInput_t;



#endif
