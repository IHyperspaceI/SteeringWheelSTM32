/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SteeringWheelSTM32.h
 *
 * Code generated for Simulink model 'SteeringWheelSTM32'.
 *
 * Model version                  : 13.121
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sat May 23 22:25:23 2026
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

/* Block states (default storage) for system '<S2>/SPI Controller Transfer1' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S2>/SPI Controller Transfer1' */
  boolean_T objisempty;                /* '<S2>/SPI Controller Transfer1' */
} DW_SPIControllerTransfer1_Ste_T;

/* Block states (default storage) for system '<S11>/SPI Controller Transfer1' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S11>/SPI Controller Transfer1' */
  boolean_T objisempty;                /* '<S11>/SPI Controller Transfer1' */
} DW_SPIControllerTransfer1_S_f_T;

/* Block signals (default storage) */
typedef struct {
  CAN_MESSAGE_BUS CANPack;             /* '<Root>/CAN Pack' */
  real32_T Gain4[5];                   /* '<Root>/Gain4' */
  uint8_T uDLookupTable2;              /* '<S13>/1-D Lookup Table2' */
  uint8_T uDLookupTable;               /* '<S13>/1-D Lookup Table' */
  uint8_T uDLookupTable1;              /* '<S13>/1-D Lookup Table1' */
  boolean_T NOT2;                      /* '<Root>/NOT2' */
  boolean_T NOT3;                      /* '<Root>/NOT3' */
  boolean_T NOT1;                      /* '<Root>/NOT1' */
  boolean_T NOT;                       /* '<Root>/NOT' */
} B_SteeringWheelSTM32_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInputF_T obj; /* '<S15>/Analog to Digital Converter' */
  stm32cube_blocks_SPIControlle_T obj_d;/* '<S2>/SPI Controller Transfer' */
  real_T DelayInput1_DSTATE;           /* '<S6>/Delay Input1' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T DelayInput1_DSTATE_l;         /* '<S7>/Delay Input1' */
  real32_T Memory2_PreviousInput;      /* '<S13>/Memory2' */
  real32_T Memory_PreviousInput;       /* '<S13>/Memory' */
  real32_T Memory1_PreviousInput;      /* '<S13>/Memory1' */
  int_T CANPack_ModeSignalID;          /* '<Root>/CAN Pack' */
  boolean_T MCPInitialized;            /* '<Root>/Data Store Memory1' */
  DW_SPIControllerTransfer1_S_f_T SPIControllerTransfer4;/* '<S11>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_S_f_T SPIControllerTransfer3;/* '<S11>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_S_f_T SPIControllerTransfer2;/* '<S11>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_S_f_T SPIControllerTransfer1_p;/* '<S11>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_Ste_T SPIControllerTransfer_p;/* '<S2>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_Ste_T SPIControllerTransfer1;/* '<S2>/SPI Controller Transfer1' */
} DW_SteeringWheelSTM32_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [0.38, 0.58, 0.78, 0.97, 1.16, 1.35, 1.53, 1.73, 1.90, 2.08, 2.27, 2.44, 2.62, 2.80, 2.97, 3.14])
   * Referenced by:
   *   '<S13>/1-D Lookup Table'
   *   '<S13>/1-D Lookup Table1'
   *   '<S13>/1-D Lookup Table2'
   */
  real32_T pooled4[16];

  /* Expression: [0x02, 0x2A, 0xC0]
   * Referenced by: '<S11>/CNF1'
   */
  uint8_T CNF1_Value[3];

  /* Expression: [0x02, 0x29, 0x99]
   * Referenced by: '<S11>/CNF2'
   */
  uint8_T CNF2_Value[3];

  /* Expression: [0x02, 0x28, 0x02]
   * Referenced by: '<S11>/CNF3'
   */
  uint8_T CNF3_Value[3];

  /* Expression: [0x02, 0x0F, 0x00]
   * Referenced by: '<S11>/ 000: normal mode, 0: don't abort pending transmit buffers, 0: one-shot disabled, 0: CLKOUT disabled, 00: sysclk//1 | 0000 0000 | 0x00'
   */
  uint8_T u00normalmode0dontabortpendingt[3];

  /* Pooled Parameter (Expression: [15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0])
   * Referenced by:
   *   '<S13>/1-D Lookup Table'
   *   '<S13>/1-D Lookup Table1'
   *   '<S13>/1-D Lookup Table2'
   */
  uint8_T pooled6[16];
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
 * Block '<Root>/AND' : Unused code path elimination
 * Block '<S3>/Compare' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S5>/Data Type Propagation' : Unused code path elimination
 * Block '<S17>/FixPt Constant' : Unused code path elimination
 * Block '<S17>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/FixPt Sum1' : Unused code path elimination
 * Block '<S5>/Output' : Unused code path elimination
 * Block '<S18>/Constant' : Unused code path elimination
 * Block '<S18>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S18>/FixPt Switch' : Unused code path elimination
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
 * '<S2>'   : 'SteeringWheelSTM32/CAN TX'
 * '<S3>'   : 'SteeringWheelSTM32/Compare To Constant'
 * '<S4>'   : 'SteeringWheelSTM32/Compare To Constant1'
 * '<S5>'   : 'SteeringWheelSTM32/Counter Limited'
 * '<S6>'   : 'SteeringWheelSTM32/Detect Increase'
 * '<S7>'   : 'SteeringWheelSTM32/Detect Increase1'
 * '<S8>'   : 'SteeringWheelSTM32/Digital Port Read'
 * '<S9>'   : 'SteeringWheelSTM32/Digital Port Write'
 * '<S10>'  : 'SteeringWheelSTM32/Digital Port Write1'
 * '<S11>'  : 'SteeringWheelSTM32/Enabled Subsystem1'
 * '<S12>'  : 'SteeringWheelSTM32/Enabled Subsystem2'
 * '<S13>'  : 'SteeringWheelSTM32/Voltage To Position'
 * '<S14>'  : 'SteeringWheelSTM32/Analog to Digital Converter/ECSoC'
 * '<S15>'  : 'SteeringWheelSTM32/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S16>'  : 'SteeringWheelSTM32/CAN TX/MATLAB Function'
 * '<S17>'  : 'SteeringWheelSTM32/Counter Limited/Increment Real World'
 * '<S18>'  : 'SteeringWheelSTM32/Counter Limited/Wrap To Zero'
 * '<S19>'  : 'SteeringWheelSTM32/Digital Port Read/ECSoC'
 * '<S20>'  : 'SteeringWheelSTM32/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S21>'  : 'SteeringWheelSTM32/Digital Port Write/ECSoC'
 * '<S22>'  : 'SteeringWheelSTM32/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S23>'  : 'SteeringWheelSTM32/Digital Port Write1/ECSoC'
 * '<S24>'  : 'SteeringWheelSTM32/Digital Port Write1/ECSoC/ECSimCodegen'
 */
#endif                                 /* SteeringWheelSTM32_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
