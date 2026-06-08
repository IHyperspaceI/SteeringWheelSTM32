/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SteeringWheelSTM32.h
 *
 * Code generated for Simulink model 'SteeringWheelSTM32'.
 *
 * Model version                  : 13.149
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon Jun  8 11:40:06 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef SteeringWheelSTM32_h_
#define SteeringWheelSTM32_h_
#ifndef SteeringWheelSTM32_COMMON_INCLUDES_
#define SteeringWheelSTM32_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "math.h"
#include "MW_SPI.h"
#include "mw_stm32_spi_ll.h"
#include "main.h"
#endif                                 /* SteeringWheelSTM32_COMMON_INCLUDES_ */

#include "SteeringWheelSTM32_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "stm32h7xx_ll_tim.h"

/* Block states (default storage) for system '<S9>/SPI Controller Transfer1' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S9>/SPI Controller Transfer1' */
  boolean_T objisempty;                /* '<S9>/SPI Controller Transfer1' */
} DW_SPIControllerTransfer1_Ste_T;

/* Block states (default storage) for system '<S19>/SPI Controller Transfer1' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S19>/SPI Controller Transfer1' */
  boolean_T objisempty;                /* '<S19>/SPI Controller Transfer1' */
} DW_SPIControllerTransfer1_S_f_T;

/* Block states (default storage) for system '<S5>/MATLAB Function1' */
typedef struct {
  real_T count;                        /* '<S5>/MATLAB Function1' */
  uint8_T current;                     /* '<S5>/MATLAB Function1' */
  uint8_T candidate;                   /* '<S5>/MATLAB Function1' */
  boolean_T current_not_empty;         /* '<S5>/MATLAB Function1' */
} DW_MATLABFunction1_SteeringWh_T;

/* Block signals (default storage) */
typedef struct {
  CAN_MESSAGE_BUS CANPack;             /* '<S2>/CAN Pack' */
  real32_T Gain4[5];                   /* '<Root>/Gain4' */
  uint8_T Position;                    /* '<S5>/MATLAB Function2' */
  uint8_T Position_e;                  /* '<S5>/MATLAB Function1' */
  uint8_T Position_n;                  /* '<S5>/MATLAB Function' */
  boolean_T NOT2;                      /* '<Root>/NOT2' */
  boolean_T NOT3;                      /* '<Root>/NOT3' */
  boolean_T NOT1;                      /* '<Root>/NOT1' */
  boolean_T NOT;                       /* '<Root>/NOT' */
  boolean_T OutportBufferForMCPInitialized;/* '<S18>/Constant' */
} B_SteeringWheelSTM32_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInputF_T obj; /* '<S7>/Analog to Digital Converter' */
  stm32cube_blocks_SPIControlle_T obj_d;/* '<S9>/SPI Controller Transfer' */
  real_T UnitDelay_DSTATE;             /* '<S4>/Unit Delay' */
  real_T DelayInput1_DSTATE;           /* '<S17>/Delay Input1' */
  real_T DelayInput1_DSTATE_f;         /* '<S16>/Delay Input1' */
  real_T count;                        /* '<S5>/MATLAB Function' */
  int_T CANPack_ModeSignalID;          /* '<S2>/CAN Pack' */
  uint8_T Output_DSTATE;               /* '<S8>/Output' */
  uint8_T current;                     /* '<S5>/MATLAB Function' */
  uint8_T candidate;                   /* '<S5>/MATLAB Function' */
  boolean_T current_not_empty;         /* '<S5>/MATLAB Function' */
  DW_MATLABFunction1_SteeringWh_T sf_MATLABFunction2;/* '<S5>/MATLAB Function2' */
  DW_MATLABFunction1_SteeringWh_T sf_MATLABFunction1;/* '<S5>/MATLAB Function1' */
  DW_SPIControllerTransfer1_S_f_T SPIControllerTransfer4;/* '<S19>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_S_f_T SPIControllerTransfer3;/* '<S19>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_S_f_T SPIControllerTransfer2;/* '<S19>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_S_f_T SPIControllerTransfer1_p;/* '<S19>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_Ste_T SPIControllerTransfer_p;/* '<S9>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_Ste_T SPIControllerTransfer1;/* '<S9>/SPI Controller Transfer1' */
} DW_SteeringWheelSTM32_T;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean_T Constant;            /* '<S18>/Constant' */
} ConstB_SteeringWheelSTM32_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [0.38, 0.58, 0.78, 0.97, 1.16, 1.35, 1.53, 1.73, 1.90, 2.08, 2.27, 2.44, 2.62, 2.80, 2.97, 3.14])
   * Referenced by:
   *   '<S5>/1-D Lookup Table1'
   *   '<S5>/1-D Lookup Table2'
   *   '<S5>/1-D Lookup Table3'
   */
  real32_T pooled4[16];

  /* Expression: [0x02, 0x2A, 0xC0]
   * Referenced by: '<S19>/CNF1'
   */
  uint8_T CNF1_Value[3];

  /* Expression: [0x02, 0x29, 0x99]
   * Referenced by: '<S19>/CNF2'
   */
  uint8_T CNF2_Value[3];

  /* Expression: [0x02, 0x28, 0x02]
   * Referenced by: '<S19>/CNF3'
   */
  uint8_T CNF3_Value[3];

  /* Expression: [0x02, 0x0F, 0x00]
   * Referenced by: '<S19>/ 000: normal mode, 0: don't abort pending transmit buffers, 0: one-shot disabled, 0: CLKOUT disabled, 00: sysclk//1 | 0000 0000 | 0x00'
   */
  uint8_T u00normalmode0dontabortpendingt[3];

  /* Pooled Parameter (Expression: [1, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2])
   * Referenced by:
   *   '<S5>/1-D Lookup Table2'
   *   '<S5>/1-D Lookup Table3'
   */
  uint8_T pooled5[16];

  /* Computed Parameter: uDLookupTable1_tableData
   * Referenced by: '<S5>/1-D Lookup Table1'
   */
  uint8_T uDLookupTable1_tableData[16];
} ConstP_SteeringWheelSTM32_T;

/* Real-time Model Data Structure */
struct tag_RTM_SteeringWheelSTM32_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block signals (default storage) */
extern B_SteeringWheelSTM32_T SteeringWheelSTM32_B;

/* Block states (default storage) */
extern DW_SteeringWheelSTM32_T SteeringWheelSTM32_DW;
extern const ConstB_SteeringWheelSTM32_T SteeringWheelSTM32_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_SteeringWheelSTM32_T SteeringWheelSTM32_ConstP;

/* Model entry point functions */
extern void SteeringWheelSTM32_initialize(void);
extern void SteeringWheelSTM32_step(void);
extern void SteeringWheelSTM32_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SteeringWheelSTM32_T *const SteeringWheelSTM32_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Duplicate1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SteeringWheelSTM32'
 * '<S1>'   : 'SteeringWheelSTM32/Analog to Digital Converter'
 * '<S2>'   : 'SteeringWheelSTM32/CAN Tx'
 * '<S3>'   : 'SteeringWheelSTM32/Digital Port Read'
 * '<S4>'   : 'SteeringWheelSTM32/Subsystem'
 * '<S5>'   : 'SteeringWheelSTM32/Voltage To Position'
 * '<S6>'   : 'SteeringWheelSTM32/Analog to Digital Converter/ECSoC'
 * '<S7>'   : 'SteeringWheelSTM32/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S8>'   : 'SteeringWheelSTM32/CAN Tx/CAN Message Period'
 * '<S9>'   : 'SteeringWheelSTM32/CAN Tx/CAN TX'
 * '<S10>'  : 'SteeringWheelSTM32/CAN Tx/Compare To Constant'
 * '<S11>'  : 'SteeringWheelSTM32/CAN Tx/CAN Message Period/Increment Real World'
 * '<S12>'  : 'SteeringWheelSTM32/CAN Tx/CAN Message Period/Wrap To Zero'
 * '<S13>'  : 'SteeringWheelSTM32/CAN Tx/CAN TX/MATLAB Function'
 * '<S14>'  : 'SteeringWheelSTM32/Digital Port Read/ECSoC'
 * '<S15>'  : 'SteeringWheelSTM32/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S16>'  : 'SteeringWheelSTM32/Subsystem/Detect Increase'
 * '<S17>'  : 'SteeringWheelSTM32/Subsystem/Detect Increase1'
 * '<S18>'  : 'SteeringWheelSTM32/Subsystem/Initialize'
 * '<S19>'  : 'SteeringWheelSTM32/Subsystem/MCPInit'
 * '<S20>'  : 'SteeringWheelSTM32/Voltage To Position/MATLAB Function'
 * '<S21>'  : 'SteeringWheelSTM32/Voltage To Position/MATLAB Function1'
 * '<S22>'  : 'SteeringWheelSTM32/Voltage To Position/MATLAB Function2'
 */
#endif                                 /* SteeringWheelSTM32_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
