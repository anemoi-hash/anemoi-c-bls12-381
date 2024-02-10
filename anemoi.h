#ifndef ANEMOI_H
#define ANEMOI_H

#include "blst.h"
#include <string.h>

/**
   An Anemoi context consists of a contiguous C array to keep the state, the
   linear layer, the round constants and the parameters beta and delta
 */

typedef struct anemoi_ctxt_s {
  // state_size := m = 2 * l
  int l;
  int nb_rounds;
  // A contiguous C array to keep the state, the MDS, the round constants and
  // the parameters beta and delta
  blst_fr *ctxt;
} anemoi_ctxt_t;

/* Apply n times the SPN construction where [n] is the number of rounds for the
   instances */
void anemoi_apply_permutation(anemoi_ctxt_t *ctxt);

/* Context related functions */
blst_fr *anemoi_get_state_from_context(anemoi_ctxt_t *ctxt);

anemoi_ctxt_t *anemoi_allocate_context(int l, int nb_rounds);

void anemoi_free_context(anemoi_ctxt_t *ctxt);

void anemoi_set_state_from_context(anemoi_ctxt_t *ctxt, blst_fr *state);

int anemoi_get_state_size_from_context(anemoi_ctxt_t *ctxt);

#ifdef ANEMOI_INTERNAL
/* Apply one round of the SPN construction */
void anemoi_apply_one_round(anemoi_ctxt_t *ctxt, int round);

blst_fr *compute_round_constants(int l, int nb_rounds);

/* Building blocks of the SPN permutation  */
void anemoi_apply_constants_addition(anemoi_ctxt_t *ctxt, int round);

void anemoi_apply_linear_layer(anemoi_ctxt_t *ctxt);

void anemoi_apply_flystel(anemoi_ctxt_t *ctxt);

void anemoi_apply_pht(anemoi_ctxt_t *ctxt);

blst_fr *anemoi_get_mds_from_context(anemoi_ctxt_t *ctxt);

blst_fr *anemoi_get_round_constants_from_context(anemoi_ctxt_t *ctxt);

blst_fr *anemoi_get_beta_from_context(anemoi_ctxt_t *ctxt);

blst_fr *anemoi_get_delta_from_context(anemoi_ctxt_t *ctxt);
#endif

void print_blst_fr_decimal_repr(blst_fr *res);

#endif
