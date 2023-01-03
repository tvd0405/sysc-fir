/*
 * tb.cpp
 *
 *  Created on: Dec 29, 2022
 *      Author: user5
 */
#include <fstream>
#include <iostream>
using namespace std;
#include "defines.h"
#include "tb.h"

void tb::stim() {
   ifstream stim_f;
   stim_f.open("input.dat");
   bool eof = false;
   double temp;
   rst_n.write(false);
   wait(10);
   rst_n.write(true);
   wait(2);

   while (!eof) {
      for (int i=0; i<PSIZE; i++) {
    	  stim_f >> temp;
    	  input[i].write(input_t(temp));
      }
      wait();
      eof = stim_f.eof();
   }
   stim_f.close();
   wait(10);
   cout << "Simulation ends successfully" << endl;
   sc_stop();
}

void tb::monitor() {
   ofstream out_f;
   out_f.open("output.dat");

   while (1) {
      for (int i=0; i<PSIZE; i++)
    	  out_f << output[i] << endl;
      wait();
   }
   out_f.close();
}
