#ifndef _FSM_H_

#include <stdint.h>

typedef int16_t Signal;
typedef struct Event Event;
typedef struct Fsm Fsm;
typedef void (*State)(Fsm *, Event const *);

enum {
  SIG_ENTRY,
  SIG_EXIT,
  SIG_NONE,

  MAX_FSM_SIG,
};

struct Event {
  Signal signal;
};

struct Fsm {
  State state_;
};

#define FsmCtor_(me_, init_)  ((me_)->state_ = (State)(init_))
#define FsmInit(me_, e_)      (*(me_)->state_)((me_), (e_))
#define FsmService(me_, e_)  (*(me_)->state_)((me_), (e_))

void FsmTran_(Fsm *me, State target);

#endif
