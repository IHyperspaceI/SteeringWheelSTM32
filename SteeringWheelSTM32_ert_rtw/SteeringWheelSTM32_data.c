/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SteeringWheelSTM32_data.c
 *
 * Code generated for Simulink model 'SteeringWheelSTM32'.
 *
 * Model version                  : 13.117
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu May 21 19:51:06 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SteeringWheelSTM32.h"

/* Constant parameters (default storage) */
const ConstP_SteeringWheelSTM32_T SteeringWheelSTM32_ConstP = {
  /* Pooled Parameter (Expression: [0.38, 0.58, 0.78, 0.97, 1.16, 1.35, 1.53, 1.73, 1.90, 2.08, 2.27, 2.44, 2.62, 2.80, 2.97, 3.14])
   * Referenced by:
   *   '<S10>/1-D Lookup Table'
   *   '<S10>/1-D Lookup Table1'
   *   '<S10>/1-D Lookup Table2'
   */
  { 0.38F, 0.58F, 0.78F, 0.97F, 1.16F, 1.35F, 1.53F, 1.73F, 1.9F, 2.08F, 2.27F,
    2.44F, 2.62F, 2.8F, 2.97F, 3.14F },

  /* Expression: [0x02, 0x2A, 0xC0]
   * Referenced by: '<S8>/CNF1'
   */
  { 2U, 42U, 192U },

  /* Expression: [0x02, 0x29, 0x99]
   * Referenced by: '<S8>/CNF2'
   */
  { 2U, 41U, 153U },

  /* Expression: [0x02, 0x28, 0x02]
   * Referenced by: '<S8>/CNF3'
   */
  { 2U, 40U, 2U },

  /* Expression: [0x02, 0x0F, 0x00]
   * Referenced by: '<S8>/ 000: normal mode, 0: don't abort pending transmit buffers, 0: one-shot disabled, 0: CLKOUT disabled, 00: sysclk//1 | 0000 0000 | 0x00'
   */
  { 2U, 15U, 0U },

  /* Pooled Parameter (Expression: [15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0])
   * Referenced by:
   *   '<S10>/1-D Lookup Table'
   *   '<S10>/1-D Lookup Table1'
   *   '<S10>/1-D Lookup Table2'
   */
  { 15U, 14U, 13U, 12U, 11U, 10U, 9U, 8U, 7U, 6U, 5U, 4U, 3U, 2U, 1U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
