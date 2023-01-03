/*
 * main.cpp
 *
 *  Created on: Dec 29, 2022
 *      Author: user5
 */
#include <systemc>
#include "top.h"
#include <string>

int sc_main(int, char*[])
{
   top m_top("m_top");
   sc_trace_file* tfile = sc_create_vcd_trace_file("trace");
   sc_trace(tfile, m_top.clk, "clk");
   sc_trace(tfile, m_top.rst_n, "rst_n");
   for (int i=0; i<PSIZE; i++)
   {
	   sc_trace(tfile, m_top.input[i], "input" + std::to_string(i));
	   sc_trace(tfile, m_top.output[i],"output" + std::to_string(i));
   }
   sc_start();
   sc_close_vcd_trace_file(tfile);
   return(0);
}
