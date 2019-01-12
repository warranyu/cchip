#include "fsm.h"

static Event_t const entryEvent = {SIG_ENTRY};
static Event_t const exitEvent = {SIG_EXIT};

void fsmTran_(Fsm_t * me, State_t target) {
  fsmService(me, &exitEvent);
  me->state_ = target;
  fsmService(me, &entryEvent);
}
