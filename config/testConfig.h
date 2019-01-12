#ifndef _TESTCONFIG_H_

#include <stdint.h>
#include "../source/ucServices/genericUc.h"
#include "../source/ucServices/gpioServices/genericGpio/genericGpio.h"

genericUcInterface_t testConfigUcInterface = {


};

genericGpioInterface_t gpioBank0 = {
  .bankNumber = 0

};

#endif
