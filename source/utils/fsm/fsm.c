#include "fsm.h"

static Event const entryEvent = {SIG_ENTRY};
static Event const exitEvent = {SIG_EXIT};

void FsmTran_(Fsm * me, State target) {
  FsmService(me, &exitEvent);
  me->state_ = target;
  FsmService(me, &entryEvent);
}
