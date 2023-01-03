/*
 * fir.h
 *
 *  Created on: Dec 29, 2022
 *      Author: user5
 */

#ifndef FIR_H_
#define FIR_H_
#include <systemc.h>
#include "defines.h"

SC_MODULE(fir) {
   sc_in<bool> clk;
   sc_in<bool> rst_n;

   sc_in<input_t> input[PSIZE];
   sc_out<output_t> output[PSIZE];

   SC_CTOR(fir) :
      clk ("clk"),
      rst_n("rst_n")
   {
      SC_CTHREAD(fir_p, clk.pos());
      async_reset_signal_is(rst_n, false);
   }

   void fir_p() {
      const coef_t coef[NTAPS] = {
	 #include "coef.dat"
      };
	input_t x[NTAPS+PSIZE-1];
      while (1)
      {
	SHIFT: for (int i=0; i<PSIZE; i++) {
   	   for (int j=0; j<NTAPS+PSIZE-2; j++) {
                x[j] = x[j+1];
   	   }
   	   x[NTAPS+PSIZE-2] = input[i];
	}

	ACC: for (int i=0; i<PSIZE; i++) {
   	   internal_t acc = 0;
   	   ACC_IN: for (int j=0; j<NTAPS-1; j++) {
     	        acc += x[j+i] * coef[j];
   	   }
   	   output[i] = acc;
	}
	 wait();
      }
   }
};
#endif /* FIR_H_ */
