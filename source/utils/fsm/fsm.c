#include "fsm.h"

static Event const entryEvent = {SIG_ENTRY};
static Event const exitEvent = {SIG_EXIT};

void fsmTran_(Fsm * me, State target) {
  fsmService(me, &exitEvent);
  me->state_ = target;
  fsmService(me, &entryEvent);
}
