#include "anemoi.h"
#include "blst.h"
#include <stdio.h>

int main(void) {
  anemoi_ctxt_t *ctxt = anemoi_allocate_context(1, 19);
  blst_fr zero;
  memset(&zero, 0, sizeof(blst_fr));

  blst_fr init_state[2] = {zero, zero};

  anemoi_set_state_from_context(ctxt, init_state);
  anemoi_apply_permutation(ctxt);

  blst_fr *state = anemoi_get_state_from_context(ctxt);
  for (int i = 0; i < ctxt->l; i++) {
    print_blst_fr_decimal_repr(state + i);
  }

  anemoi_free_context(ctxt);

  return (0);
}
