#ifndef _STOCR_H_
#define _STOCR_H_

#include <cstdint>
#include <stdexcept>
#include "numpy/random/bitgen.h"

class StocRBase {

  // bitgen_state is owned by the collater and its
  // lifetime will be assumed to be the same or
  // greater than this StocRBase object
  bitgen_t* bitgen_state;

public:
  StocRBase() : bitgen_state(NULL) {}
  StocRBase(std::int32_t seed) : bitgen_state(NULL) {}

  void SetBitGen(bitgen_t* that_bitgen_state) {
    bitgen_state = that_bitgen_state;
  }
  
  void InitRan() {
    // we can only generate random numbers if we have bitgen_t object
    if (bitgen_state == NULL) {
      throw std::runtime_error("SetBitGen(bitgen_state) has not been called!");
    }
  }

  void EndRan() {}

  double Random() {
    return bitgen_state->next_double(bitgen_state->state);
  }
};

#endif // _STOCR_H_
