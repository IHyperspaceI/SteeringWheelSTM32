/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SteeringWheelSTM32_private.h
 *
 * Code generated for Simulink model 'SteeringWheelSTM32'.
 *
 * Model version                  : 13.145
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Jun  7 22:52:02 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef SteeringWheelSTM32_private_h_
#define SteeringWheelSTM32_private_h_
#include "rtwtypes.h"
#include "SteeringWheelSTM32.h"
#include "SteeringWheelSTM32_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
extern uint32_T plook_u32f_binckan(real32_T u, const real32_T bp[], uint32_T
  maxIndex);
extern uint32_T binsearch_u32f(real32_T u, const real32_T bp[], uint32_T
  startIndex, uint32_T maxIndex);
extern void Ste_SPIControllerTransfer1_Init(DW_SPIControllerTransfer1_Ste_T
  *localDW);
extern void Steering_SPIControllerTransfer1(uint8_T rtu_0,
  DW_SPIControllerTransfer1_Ste_T *localDW);
extern void S_SPIControllerTransfer1_d_Init(DW_SPIControllerTransfer1_S_f_T
  *localDW);
extern void Steeri_SPIControllerTransfer1_p(const uint8_T rtu_0[3],
  DW_SPIControllerTransfer1_S_f_T *localDW);
extern void SteeringWheelST_MATLABFunction1(real32_T rtu_Voltage, uint8_T rtu_In,
  real_T rtu_N, uint8_T *rty_Position, DW_MATLABFunction1_SteeringWh_T *localDW);
extern void Ste_SPIControllerTransfer1_Term(DW_SPIControllerTransfer1_Ste_T
  *localDW);
extern void S_SPIControllerTransfer1_o_Term(DW_SPIControllerTransfer1_S_f_T
  *localDW);

#endif                                 /* SteeringWheelSTM32_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
