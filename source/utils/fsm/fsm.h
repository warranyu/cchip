#ifndef _FSM_H_

#include <stdint.h>

typedef int16_t Signal_t;
typedef struct EventClass EventClass;
typedef struct Fsm_t Fsm_t;
typedef void (*State_t)(Fsm_t *, EventClass const *);

enum {
  SIG_ENTRY,
  SIG_EXIT,

  MAX_FSM_SIG,
};

struct EventClass {
  Signal_t signal;
};

struct Fsm_t {
  State_t state_;
};

#define fsmCtor_(me_, init_)  ((me_)->state_ = (State_t)(init_))
#define fsmInit(me_, e_)      (*(me_)->state_)((me_), (e_))
#define fsmService(me_, e_)  (*(me_)->state_)((me_), (e_))

void fsmTran_(Fsm_t *me, State_t target);

#endif
