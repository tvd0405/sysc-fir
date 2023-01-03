/*
 * defines.h
 *
 *  Created on: Dec 29, 2022
 *      Author: user5
 */

#ifndef DEFINES_H_
#define DEFINES_H_
#define CLK_PERIOD 10
#define CLK_UNIT SC_NS
#define NTAPS 49
#define PSIZE 2
#define DW 12
#if 0
typedef double input_t;
typedef double output_t;
typedef double coef_t;
typedef double internal_t;
#else
#include "sc_fixed.h"
typedef sc_dt::sc_fixed<DW, 1> data_t;
typedef sc_dt::sc_fixed<2*DW+7, 8> int_t;
typedef data_t input_t;
typedef data_t output_t;
typedef data_t coef_t;
typedef int_t internal_t;
#endif
#endif /* DEFINES_H_ */
