#ifndef _FSM_H_

#include <stdint.h>

typedef int16_t Signal;
typedef struct Event Event;
typedef struct Fsm Fsm;
typedef void (*State)(Fsm *, Event const *);

enum {
  SIG_ENTRY,
  SIG_EXIT,

  MAX_FSM_SIG,
};

struct Event {
  Signal signal;
};

struct Fsm {
  State state_;
};

#define fsmCtor_(me_, init_)  ((me_)->state_ = (State)(init_))
#define fsmInit(me_, e_)      (*(me_)->state_)((me_), (e_))
#define fsmService(me_, e_)  (*(me_)->state_)((me_), (e_))

void fsmTran_(Fsm *me, State target);

#endif
