
#include <stdio.h>
#include "printfGpio.h"

void PrintfGpio_unpowered(Gpio_Class * this, Event const * e);
void PrintfGpio_uninitialized(Gpio_Class * this, Event const * e);
void PrintfGpio_initializing(Gpio_Class * this, Event const * e);
void PrintfGpio_idle(Gpio_Class * this, Event const * e);
void PrintfGpio_readPin(Gpio_Class * this, Event const * e);
void PrintfGpio_writePin(Gpio_Class * this, Event const * e);

void PrintfGpio_unpowered(Gpio_Class * this, Event const * e) {
  switch(e->signal){

    case SIG_ENTRY:
      printf("Unpowered.\n");
    break;

    // When we receive a SIG_POWER and the message is > 0, go to uninitialized
    case SIG_POWER:
      if(((ServiceEvt *)e)->message[0] > 0) {
        printf("Received signal to power on.\n");
        this->gpioEvt.serviceEvt.event.signal = SIG_NONE;  // Event handled
        FsmTran_(((Fsm *) this), (State) &PrintfGpio_uninitialized);
      }
    break;

    // Since we are powered off, ignore all other signals
    default:
    break;
  }
}

void PrintfGpio_uninitialized(Gpio_Class * this, Event const * e) {
  switch(e->signal){

    case SIG_ENTRY:
      printf("Uninitialized.\n");
    break;

    // Powered on and received power off message, go to unpowered state
    case SIG_POWER:
      if(((ServiceEvt *)e)->message[0] == 0) {
        printf("Received signal to power off.\n");
        this->gpioEvt.serviceEvt.event.signal = SIG_NONE;  // Event handled
        FsmTran_(((Fsm *) this), (State) &PrintfGpio_unpowered);
      }
    break;

    // The reset signal is used to go to the initializing state.
    case SIG_NRESET:
      if(((ServiceEvt *)e)->message[0] > 0) {
        printf("Received reset signal - reinitializing.\n");
        this->gpioEvt.serviceEvt.event.signal = SIG_NONE;  // Event handled
        FsmTran_(((Fsm *) this), (State) &PrintfGpio_initializing);
      }
    break;

    // Ignore all other signals
    default:
    break;
  }
}

void PrintfGpio_initializing(Gpio_Class * this, Event const * e) {
  switch(e->signal){

    case SIG_ENTRY:
      printf("Initializing.\n");
    break;

    // Powered on and received power off message, go to unpowered state
    case SIG_POWER:
      if(((ServiceEvt *)e)->message[0] == 0) {
        printf("Received signal to power off.\n");
        this->gpioEvt.serviceEvt.event.signal = SIG_NONE;  // Event handled
        FsmTran_(((Fsm *) this), (State) &PrintfGpio_unpowered);
      }
    break;

    // The reset signal is used to go to the uninitialized state.
    case SIG_NRESET:
    if(((ServiceEvt *)e)->message[0] == 0) {
      printf("Received reset signal - reinitializing.\n");
      this->gpioEvt.serviceEvt.event.signal = SIG_NONE;  // Event handled
      FsmTran_(((Fsm *) this), (State) &PrintfGpio_initializing);
    }
    break;

    default:
      // Do stuff here or wait around until we're ready
      // Then transition to the idle state
      this->gpioEvt.serviceEvt.event.signal = SIG_NONE;  // Event handled
      FsmTran_(((Fsm *) this), (State) &PrintfGpio_idle);
    break;
  }
}

void PrintfGpio_idle(Gpio_Class * this, Event const * e) {
  switch(e->signal){

    case SIG_ENTRY:
      printf("Idle.\n");
      this->service.idle = true;
    break;

    case SIG_EXIT:
      printf("Busy.\n");
      this->service.idle = false;
    break;

    // Powered on and received power off message, go to unpowered state
    case SIG_POWER:
      if(((ServiceEvt *)e)->message[0] == 0) {
        printf("Received signal to power off.\n");
        this->gpioEvt.serviceEvt.event.signal = SIG_NONE;  // Event handled
        FsmTran_(((Fsm *) this), (State) &PrintfGpio_unpowered);
      }
    break;

    // The reset signal is used to go to the uninitialized state.
    case SIG_NRESET:
      if(((ServiceEvt *)e)->message[0] == 0) {
        printf("Received reset signal - reinitializing.\n");
        this->gpioEvt.serviceEvt.event.signal = SIG_NONE;  // Event handled
        FsmTran_(((Fsm *) this), (State) &PrintfGpio_initializing);
      }
    break;

    case SIG_INPUT:
      switch(((GpioEvt *)e)->command) {
        case READBANK:
        break;

        case WRITEBANK:
        break;

        case READPIN:
        break;

        case WRITEPIN:
        break;

        case TOGGLEPIN:
        break;
      }
    break;

    case SIG_OUTPUT:
      switch(((GpioEvt *)e)->command) {
        case READBANK:
        break;

        case WRITEBANK:
        break;

        case READPIN:
        break;

        case WRITEPIN:
        break;

        case TOGGLEPIN:
        break;
      }
    break;

    default:
    break;
  }
}


void PrintfGpio_constructor(Gpio_Class * this) {
  // TODO
}

void PrintfGpio_inputEvent(Gpio_Class * this, ServiceEvt * msg) {
  // TODO
  if(this->service.idle) {
    this->service.idle = false;
  }
}

void PrintfGpio_outputEvent(Gpio_Class * this, ServiceEvt * msg) {
  // TODO
  if(this->service.idle) {

  }
}

void PrintfGpio_service(Gpio_Class * this) {
  // TODO
  FsmService((Fsm *) &this, (Event *) &this->gpioEvt);
}
