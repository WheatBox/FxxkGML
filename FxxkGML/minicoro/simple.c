#define MINICORO_IMPL
#include "minicoro.h"
#include <stdio.h>

mco_coro* co;

void middle() {
mco_yield(co);
}

// Coroutine entry function.
void coro_entry() {
  printf("coroutine 1\n");
  middle();
  printf("coroutine 2\n");
}

int main() {
  // First initialize a `desc` object through `mco_desc_init`.
  mco_desc desc = mco_desc_init(coro_entry, 0);
  // Configure `desc` fields when needed (e.g. customize user_data or allocation functions).
  desc.user_data = NULL;
  // Call `mco_create` with the output coroutine pointer and `desc` pointer.
  mco_result res = mco_create(&co, &desc);
  // assert(res == MCO_SUCCESS);
  // The coroutine should be now in suspended state.
  // assert(mco_status(co) == MCO_SUSPENDED);
  // Call `mco_resume` to start for the first time, switching to its context.
  printf("A1\n");
  res = mco_resume(co); // Should print "coroutine 1".
  printf("A2\n");
  // assert(res == MCO_SUCCESS);
  // We get back from coroutine context in suspended state (because it's unfinished).
  // assert(mco_status(co) == MCO_SUSPENDED);
  // Call `mco_resume` to resume for a second time.
  printf("B1\n");
  res = mco_resume(co); // Should print "coroutine 2".
  printf("B2\n");
  // assert(res == MCO_SUCCESS);
  // The coroutine finished and should be now dead.
  // assert(mco_status(co) == MCO_DEAD);
  // Call `mco_destroy` to destroy the coroutine.
  res = mco_destroy(co);
  // assert(res == MCO_SUCCESS);
  return 0;
}
