/*
 * tb.h
 *
 *  Created on: Dec 29, 2022
 *      Author: user5
 */

#ifndef TB_H_
#define TB_H_
#include <systemc.h>
#include "defines.h"

SC_MODULE(tb) {
   sc_in_clk clk;
   sc_out<bool> rst_n;

   sc_out<input_t> input[PSIZE];
   sc_in<output_t> output[PSIZE];

   SC_CTOR(tb) :
      clk ("clk"),
      rst_n("rst_n")
   {
      SC_CTHREAD(stim, clk.pos());
      //async_reset_signal_is(rst_n, false);

      SC_CTHREAD(monitor, clk.pos());
      //async_reset_signal_is(rst_n, false);
   }
   void stim();
   void monitor();
};
#endif /* TB_H_ */
