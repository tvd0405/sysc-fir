/*
 * top.h
 *
 *  Created on: Dec 29, 2022
 *      Author: user5
 */

#ifndef TOP_H_
#define TOP_H_
#include <systemc>
using namespace sc_core;
#include "defines.h"
#include "tb.h"
#include "fir.h"

SC_MODULE(top) {
   sc_clock clk;
   sc_signal<bool> rst_n;

   sc_signal<input_t> input[PSIZE];
   sc_signal<output_t> output[PSIZE];

   tb m_tb;
   fir m_fir;

   SC_CTOR(top):
      clk ("clk", CLK_PERIOD, CLK_UNIT),
      m_tb("tb"),
      m_fir("fir")
   {
      m_fir.clk(clk);
      m_tb.clk(clk);
      m_fir.rst_n(rst_n);
      m_tb.rst_n(rst_n);

      for (int i=0; i<PSIZE; i++) {
	 m_fir.input[i](input[i]);
	 m_tb.input[i](input[i]);
	 m_fir.output[i](output[i]);
	 m_tb.output[i](output[i]);
      }
   }
};
#endif /* TOP_H_ */
