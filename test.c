#include "anemoi.h"
#include "blst.h"
#include <stdio.h>

void print_blst_fr_decimal_repr(blst_fr *r) {
  uint64_t r_uint64[4];
  blst_scalar s;
  blst_scalar_from_fr(&s, r);
  blst_uint64_from_scalar(r_uint64, &s);

  printf("%lu", r_uint64[0]);
  printf("%lu", r_uint64[1]);
  printf("%lu", r_uint64[2]);
  printf("%lu\n", r_uint64[3]);
}

int main(void) {
  anemoi_ctxt_t *ctxt = anemoi_allocate_context(1, 19);
  blst_fr zero;
  memset(&zero, 0, sizeof(blst_fr));

  blst_fr init_state[2] = {zero, zero};

  anemoi_set_state_from_context(ctxt, init_state);
  anemoi_apply_permutation(ctxt);

  blst_fr *state = anemoi_get_state_from_context(ctxt);
  for(int i = 0;i < ctxt->l;i++) {
     print_blst_fr_decimal_repr(state + i);
  }

  anemoi_free_context(ctxt);

  return (0);
}
