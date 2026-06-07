/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SteeringWheelSTM32.c
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

#include "SteeringWheelSTM32.h"
#include "rtwtypes.h"
#include "SteeringWheelSTM32_types.h"
#include "SteeringWheelSTM32_private.h"
#include "mw_stm32_spi_ll.h"
#include "stm_adc_ll.h"
#include <stddef.h>

/* Block signals (default storage) */
B_SteeringWheelSTM32_T SteeringWheelSTM32_B;

/* Block states (default storage) */
DW_SteeringWheelSTM32_T SteeringWheelSTM32_DW;

/* Real-time model */
static RT_MODEL_SteeringWheelSTM32_T SteeringWheelSTM32_M_;
RT_MODEL_SteeringWheelSTM32_T *const SteeringWheelSTM32_M =
  &SteeringWheelSTM32_M_;

/* Forward declaration for local functions */
static void SteeringWheelS_SystemCore_setup(stm32cube_blocks_AnalogInputF_T *obj);
uint32_T plook_u32f_binckan(real32_T u, const real32_T bp[], uint32_T maxIndex)
{
  uint32_T bpIndex;

  /* Prelookup - Index only
     Index Search method: 'binary'
     Interpolation method: 'Use nearest'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32f(u, bp, maxIndex >> 1U, maxIndex);
    if ((bpIndex < maxIndex) && (bp[bpIndex + 1U] - u <= u - bp[bpIndex])) {
      bpIndex++;
    }
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

uint32_T binsearch_u32f(real32_T u, const real32_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T bpIndex;
  uint32_T iRght;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

/* System initialize for atomic system: */
void Ste_SPIControllerTransfer1_Init(DW_SPIControllerTransfer1_Ste_T *localDW)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S9>/SPI Controller Transfer1' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  b.PeripheralPtr = SPI1;
  localDW->obj.MW_SPI_HANDLE = SPI_STM32_Init(&b);
  MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U, MW_SPI_MODE_2);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void Steering_SPIControllerTransfer1(uint8_T rtu_0,
  DW_SPIControllerTransfer1_Ste_T *localDW)
{
  uint8_T rdDataRaw;

  /* MATLABSystem: '<S9>/SPI Controller Transfer1' */
  rdDataRaw = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (rdDataRaw == 0) {
    GPIO_TypeDef * portNameLoc;
    portNameLoc = GPIOA;
    LL_GPIO_ResetOutputPin(portNameLoc, 16U);
    MW_SPI_MasterWriteRead_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0,
      &rdDataRaw, 0, 1U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 16U);
  }

  /* End of MATLABSystem: '<S9>/SPI Controller Transfer1' */
}

/* Termination for atomic system: */
void Ste_SPIControllerTransfer1_Term(DW_SPIControllerTransfer1_Ste_T *localDW)
{
  /* Terminate for MATLABSystem: '<S9>/SPI Controller Transfer1' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/SPI Controller Transfer1' */
}

/* System initialize for atomic system: */
void S_SPIControllerTransfer1_d_Init(DW_SPIControllerTransfer1_S_f_T *localDW)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S19>/SPI Controller Transfer1' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  b.PeripheralPtr = SPI1;
  localDW->obj.MW_SPI_HANDLE = SPI_STM32_Init(&b);
  MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U, MW_SPI_MODE_2);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void Steeri_SPIControllerTransfer1_p(const uint8_T rtu_0[3],
  DW_SPIControllerTransfer1_S_f_T *localDW)
{
  uint8_T tmp[3];
  uint8_T status;

  /* MATLABSystem: '<S19>/SPI Controller Transfer1' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (status == 0) {
    GPIO_TypeDef * portNameLoc;
    portNameLoc = GPIOA;
    LL_GPIO_ResetOutputPin(portNameLoc, 16U);
    MW_SPI_MasterWriteRead_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0[0], &tmp
      [0], 0, 3U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 16U);
  }

  /* End of MATLABSystem: '<S19>/SPI Controller Transfer1' */
}

/* Termination for atomic system: */
void S_SPIControllerTransfer1_o_Term(DW_SPIControllerTransfer1_S_f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S19>/SPI Controller Transfer1' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S19>/SPI Controller Transfer1' */
}

/*
 * Output and update for atomic system:
 *    '<S5>/MATLAB Function1'
 *    '<S5>/MATLAB Function2'
 */
void SteeringWheelST_MATLABFunction1(real32_T rtu_Voltage, uint8_T rtu_In,
  real_T rtu_N, uint8_T *rty_Position, DW_MATLABFunction1_SteeringWh_T *localDW)
{
  if (!localDW->current_not_empty) {
    localDW->current = rtu_In;
    localDW->current_not_empty = true;
    localDW->candidate = rtu_In;
  }

  if (rtu_Voltage < 0.15) {
    *rty_Position = localDW->current;
  } else {
    if (rtu_In == localDW->candidate) {
      localDW->count++;
    } else {
      localDW->candidate = rtu_In;
      localDW->count = 0.0;
    }

    if (localDW->count >= rtu_N) {
      localDW->current = localDW->candidate;
    }

    *rty_Position = localDW->current;
  }
}

static void SteeringWheelS_SystemCore_setup(stm32cube_blocks_AnalogInputF_T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S7>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S7>/Analog to Digital Converter' */
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 5U;
  adcStructLoc.RegularNoOfConversion = 5U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_INTERRUPT_MODE, 1,
    ADC_READ, LL_ADC_REG_SEQ_SCAN_ENABLE_5RANKS);
  enableADCAutomaticCalibration(obj->ADCHandle, (uint32_T)LL_ADC_CALIB_OFFSET, 2);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
}

/* Model step function */
void SteeringWheelSTM32_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_UnitDelay;
  int32_T i;
  uint32_T rtb_AnalogtoDigitalConverter_0[5];
  uint32_T pinReadLoc;
  uint8_T rtb_VectorConcatenate[15];
  uint8_T tmp[15];
  uint8_T rtb_uDLookupTable2;
  boolean_T rtb_Step1_tmp;

  /* MATLABSystem: '<S7>/Analog to Digital Converter' */
  regularReadADCIntr(SteeringWheelSTM32_DW.obj.ADCHandle, ADC_READ,
                     &rtb_AnalogtoDigitalConverter_0[0]);
  for (i = 0; i < 5; i++) {
    /* Gain: '<Root>/Gain4' incorporates:
     *  MATLABSystem: '<S7>/Analog to Digital Converter'
     */
    SteeringWheelSTM32_B.Gain4[i] = 5.03547708E-5F * (real32_T)
      rtb_AnalogtoDigitalConverter_0[i];
  }

  /* MATLABSystem: '<S15>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

  /* Logic: '<Root>/NOT2' incorporates:
   *  MATLABSystem: '<S15>/Digital Port Read'
   * */
  SteeringWheelSTM32_B.NOT2 = ((pinReadLoc & 2048U) == 0U);

  /* Logic: '<Root>/NOT3' incorporates:
   *  MATLABSystem: '<S15>/Digital Port Read'
   * */
  SteeringWheelSTM32_B.NOT3 = ((pinReadLoc & 4096U) == 0U);

  /* Logic: '<Root>/NOT1' incorporates:
   *  MATLABSystem: '<S15>/Digital Port Read'
   * */
  SteeringWheelSTM32_B.NOT1 = ((pinReadLoc & 1024U) == 0U);

  /* Logic: '<Root>/NOT' incorporates:
   *  MATLABSystem: '<S15>/Digital Port Read'
   * */
  SteeringWheelSTM32_B.NOT = ((pinReadLoc & 512U) == 0U);

  /* Lookup_n-D: '<S5>/1-D Lookup Table2' */
  rtb_uDLookupTable2 = SteeringWheelSTM32_ConstP.pooled5[plook_u32f_binckan
    (SteeringWheelSTM32_B.Gain4[2], SteeringWheelSTM32_ConstP.pooled4, 15U)];

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (!SteeringWheelSTM32_DW.current_not_empty) {
    SteeringWheelSTM32_DW.current = rtb_uDLookupTable2;
    SteeringWheelSTM32_DW.current_not_empty = true;
    SteeringWheelSTM32_DW.candidate = rtb_uDLookupTable2;
  }

  if (SteeringWheelSTM32_B.Gain4[2] < 0.15) {
    SteeringWheelSTM32_B.Position_n = SteeringWheelSTM32_DW.current;
  } else {
    if (rtb_uDLookupTable2 == SteeringWheelSTM32_DW.candidate) {
      SteeringWheelSTM32_DW.count++;
    } else {
      SteeringWheelSTM32_DW.candidate = rtb_uDLookupTable2;
      SteeringWheelSTM32_DW.count = 0.0;
    }

    if (SteeringWheelSTM32_DW.count >= 50.0) {
      SteeringWheelSTM32_DW.current = SteeringWheelSTM32_DW.candidate;
    }

    SteeringWheelSTM32_B.Position_n = SteeringWheelSTM32_DW.current;
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function' */

  /* MATLAB Function: '<S5>/MATLAB Function2' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Lookup_n-D: '<S5>/1-D Lookup Table3'
   */
  SteeringWheelST_MATLABFunction1(SteeringWheelSTM32_B.Gain4[0],
    SteeringWheelSTM32_ConstP.pooled5[plook_u32f_binckan
    (SteeringWheelSTM32_B.Gain4[0], SteeringWheelSTM32_ConstP.pooled4, 15U)],
    50.0, &SteeringWheelSTM32_B.Position,
    &SteeringWheelSTM32_DW.sf_MATLABFunction2);

  /* MATLAB Function: '<S5>/MATLAB Function1' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Lookup_n-D: '<S5>/1-D Lookup Table1'
   */
  SteeringWheelST_MATLABFunction1(SteeringWheelSTM32_B.Gain4[1],
    SteeringWheelSTM32_ConstP.pooled5[plook_u32f_binckan
    (SteeringWheelSTM32_B.Gain4[1], SteeringWheelSTM32_ConstP.pooled4, 15U)],
    50.0, &SteeringWheelSTM32_B.Position_e,
    &SteeringWheelSTM32_DW.sf_MATLABFunction1);

  /* S-Function (scanpack): '<S2>/CAN Pack' */
  /* S-Function (scanpack): '<S2>/CAN Pack' */
  SteeringWheelSTM32_B.CANPack.ID = 507U;
  SteeringWheelSTM32_B.CANPack.Length = 6U;
  SteeringWheelSTM32_B.CANPack.Extended = 0U;
  SteeringWheelSTM32_B.CANPack.Remote = 0;
  SteeringWheelSTM32_B.CANPack.Data[0] = 0;
  SteeringWheelSTM32_B.CANPack.Data[1] = 0;
  SteeringWheelSTM32_B.CANPack.Data[2] = 0;
  SteeringWheelSTM32_B.CANPack.Data[3] = 0;
  SteeringWheelSTM32_B.CANPack.Data[4] = 0;
  SteeringWheelSTM32_B.CANPack.Data[5] = 0;
  SteeringWheelSTM32_B.CANPack.Data[6] = 0;
  SteeringWheelSTM32_B.CANPack.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (SteeringWheelSTM32_B.NOT2);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            SteeringWheelSTM32_B.CANPack.Data[0] =
              SteeringWheelSTM32_B.CANPack.Data[0] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x1U));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 1
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (SteeringWheelSTM32_B.NOT3);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            SteeringWheelSTM32_B.CANPack.Data[0] =
              SteeringWheelSTM32_B.CANPack.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 1));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 2
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (SteeringWheelSTM32_B.NOT1);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            SteeringWheelSTM32_B.CANPack.Data[0] =
              SteeringWheelSTM32_B.CANPack.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 3
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (SteeringWheelSTM32_B.NOT);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            SteeringWheelSTM32_B.CANPack.Data[0] =
              SteeringWheelSTM32_B.CANPack.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 3));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 12
     *  length                  = 4
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 1.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (SteeringWheelSTM32_B.Position_n);

        /* no factor to apply */
        result = (uint32_T) (result - 1U);
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(15)) {
          packedValue = (uint8_T) 15;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            SteeringWheelSTM32_B.CANPack.Data[1] =
              SteeringWheelSTM32_B.CANPack.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0xFU) << 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 4
     *  length                  = 4
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 1.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (SteeringWheelSTM32_B.Position);

        /* no factor to apply */
        result = (uint32_T) (result - 1U);
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(15)) {
          packedValue = (uint8_T) 15;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            SteeringWheelSTM32_B.CANPack.Data[0] =
              SteeringWheelSTM32_B.CANPack.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0xFU) << 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 8
     *  length                  = 4
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 1.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (SteeringWheelSTM32_B.Position_e);

        /* no factor to apply */
        result = (uint32_T) (result - 1U);
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(15)) {
          packedValue = (uint8_T) 15;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            SteeringWheelSTM32_B.CANPack.Data[1] =
              SteeringWheelSTM32_B.CANPack.Data[1] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0xFU));
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.0129
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = SteeringWheelSTM32_B.Gain4[3];

        /* no offset to apply */
        result = result * (1 / 0.0129F);

        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        uint8_T packedValue;
        if (outValue > (real32_T)(255)) {
          packedValue = (uint8_T) 255;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (outValue);
        }

        {
          {
            SteeringWheelSTM32_B.CANPack.Data[2] =
              SteeringWheelSTM32_B.CANPack.Data[2] | (uint8_T)(packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 8 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.0129
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = SteeringWheelSTM32_B.Gain4[4];

        /* no offset to apply */
        result = result * (1 / 0.0129F);

        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        uint8_T packedValue;
        if (outValue > (real32_T)(255)) {
          packedValue = (uint8_T) 255;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (outValue);
        }

        {
          {
            SteeringWheelSTM32_B.CANPack.Data[3] =
              SteeringWheelSTM32_B.CANPack.Data[3] | (uint8_T)(packedValue);
          }
        }
      }
    }
  }

  /* UnitDelay: '<S4>/Unit Delay' */
  rtb_UnitDelay = SteeringWheelSTM32_DW.UnitDelay_DSTATE;

  /* Outputs for Enabled SubSystem: '<S4>/Initialize' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  /* RelationalOperator: '<S17>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S17>/Delay Input1'
   *  UnitDelay: '<S4>/Unit Delay'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (SteeringWheelSTM32_DW.UnitDelay_DSTATE >
      SteeringWheelSTM32_DW.DelayInput1_DSTATE) {
    /* SignalConversion generated from: '<S18>/MCPInitialized' */
    SteeringWheelSTM32_B.OutportBufferForMCPInitialized =
      SteeringWheelSTM32_ConstB.Constant;
  }

  /* End of RelationalOperator: '<S17>/FixPt Relational Operator' */
  /* End of Outputs for SubSystem: '<S4>/Initialize' */

  /* Outputs for Enabled SubSystem: '<S2>/CAN TX' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  /* Logic: '<S2>/AND' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S9>/RTS'
   *  Constant: '<S9>/TX Buffer 0'
   *  Constant: '<S9>/WRITE Instruction'
   *  RelationalOperator: '<S10>/Compare'
   *  UnitDelay: '<S8>/Output'
   */
  if (SteeringWheelSTM32_B.OutportBufferForMCPInitialized &&
      (SteeringWheelSTM32_DW.Output_DSTATE == 0)) {
    /* MATLAB Function: '<S9>/MATLAB Function' */
    pinReadLoc = SteeringWheelSTM32_B.CANPack.ID;
    if (SteeringWheelSTM32_B.CANPack.ID > 65535U) {
      pinReadLoc = 65535U;
    }

    for (i = 0; i < 13; i++) {
      rtb_VectorConcatenate[i + 2] = 0U;
    }

    i = (uint16_T)pinReadLoc >> 3;
    if (i > 255) {
      i = 255;
    }

    rtb_VectorConcatenate[2] = (uint8_T)i;
    rtb_VectorConcatenate[3] = (uint8_T)((int32_T)((uint16_T)pinReadLoc & 7U) <<
      5);
    rtb_VectorConcatenate[4] = 0U;
    rtb_VectorConcatenate[5] = 0U;
    rtb_VectorConcatenate[6] = (uint8_T)(SteeringWheelSTM32_B.CANPack.Length &
      15);
    for (i = 0; i < 8; i++) {
      rtb_VectorConcatenate[i + 7] = SteeringWheelSTM32_B.CANPack.Data[i];
    }

    /* End of MATLAB Function: '<S9>/MATLAB Function' */
    rtb_VectorConcatenate[0] = 2U;
    rtb_VectorConcatenate[1] = 49U;

    /* MATLABSystem: '<S9>/SPI Controller Transfer' incorporates:
     *  Concatenate: '<S9>/Vector Concatenate'
     *  Constant: '<S9>/TX Buffer 0'
     *  Constant: '<S9>/WRITE Instruction'
     */
    rtb_uDLookupTable2 = MW_STM32_SPI_SetFormat
      (SteeringWheelSTM32_DW.obj_d.MW_SPI_HANDLE, 0U, 1792U, MW_SPI_MODE_2);
    if (rtb_uDLookupTable2 == 0) {
      portNameLoc = GPIOA;
      LL_GPIO_ResetOutputPin(portNameLoc, 16U);
      MW_SPI_MasterWriteRead_Databits(SteeringWheelSTM32_DW.obj_d.MW_SPI_HANDLE,
        &rtb_VectorConcatenate[0], &tmp[0], 0, 15U, 1, 10U);
      LL_GPIO_SetOutputPin(portNameLoc, 16U);
    }

    /* End of MATLABSystem: '<S9>/SPI Controller Transfer' */
    Steering_SPIControllerTransfer1(129,
      &SteeringWheelSTM32_DW.SPIControllerTransfer1);
  }

  /* End of Logic: '<S2>/AND' */
  /* End of Outputs for SubSystem: '<S2>/CAN TX' */

  /* Switch: '<S12>/FixPt Switch' incorporates:
   *  Constant: '<S11>/FixPt Constant'
   *  Constant: '<S12>/Constant'
   *  Sum: '<S11>/FixPt Sum1'
   *  UnitDelay: '<S8>/Output'
   */
  if ((uint8_T)(SteeringWheelSTM32_DW.Output_DSTATE + 1) > 10) {
    SteeringWheelSTM32_DW.Output_DSTATE = 0U;
  } else {
    SteeringWheelSTM32_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S12>/FixPt Switch' */

  /* Step: '<S4>/Step1' */
  rtb_Step1_tmp = !(((SteeringWheelSTM32_M->Timing.clockTick0) * 0.001) < 1.0);

  /* Outputs for Enabled SubSystem: '<S4>/MCPInit' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  /* RelationalOperator: '<S16>/FixPt Relational Operator' incorporates:
   *  Constant: '<S19>/ 000: normal mode, 0: don't abort pending transmit buffers, 0: one-shot disabled, 0: CLKOUT disabled, 00: sysclk//1 | 0000 0000 | 0x00'
   *  Constant: '<S19>/CNF1'
   *  Constant: '<S19>/CNF2'
   *  Constant: '<S19>/CNF3'
   *  Constant: '<S19>/Enter Configuration Mode'
   *  UnitDelay: '<S16>/Delay Input1'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((real_T)rtb_Step1_tmp > SteeringWheelSTM32_DW.DelayInput1_DSTATE_f) {
    Steering_SPIControllerTransfer1(192,
      &SteeringWheelSTM32_DW.SPIControllerTransfer_p);
    Steeri_SPIControllerTransfer1_p(SteeringWheelSTM32_ConstP.CNF1_Value,
      &SteeringWheelSTM32_DW.SPIControllerTransfer1_p);
    Steeri_SPIControllerTransfer1_p(SteeringWheelSTM32_ConstP.CNF2_Value,
      &SteeringWheelSTM32_DW.SPIControllerTransfer2);
    Steeri_SPIControllerTransfer1_p(SteeringWheelSTM32_ConstP.CNF3_Value,
      &SteeringWheelSTM32_DW.SPIControllerTransfer3);
    Steeri_SPIControllerTransfer1_p
      (SteeringWheelSTM32_ConstP.u00normalmode0dontabortpendingt,
       &SteeringWheelSTM32_DW.SPIControllerTransfer4);
  }

  /* End of RelationalOperator: '<S16>/FixPt Relational Operator' */
  /* End of Outputs for SubSystem: '<S4>/MCPInit' */

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  SteeringWheelSTM32_DW.UnitDelay_DSTATE = rtb_Step1_tmp;

  /* Update for UnitDelay: '<S17>/Delay Input1'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  SteeringWheelSTM32_DW.DelayInput1_DSTATE = rtb_UnitDelay;

  /* Update for UnitDelay: '<S16>/Delay Input1'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  SteeringWheelSTM32_DW.DelayInput1_DSTATE_f = rtb_Step1_tmp;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  SteeringWheelSTM32_M->Timing.clockTick0++;
}

/* Model initialize function */
void SteeringWheelSTM32_initialize(void)
{
  {
    STM32_SPI_ModuleStruct_T b;

    /* SystemInitialize for Enabled SubSystem: '<S4>/Initialize' */
    /* SystemInitialize for SignalConversion generated from: '<S18>/MCPInitialized' */
    SteeringWheelSTM32_B.OutportBufferForMCPInitialized =
      SteeringWheelSTM32_ConstB.Constant;

    /* End of SystemInitialize for SubSystem: '<S4>/Initialize' */

    /* SystemInitialize for Enabled SubSystem: '<S2>/CAN TX' */
    /* Start for MATLABSystem: '<S9>/SPI Controller Transfer' */
    SteeringWheelSTM32_DW.obj_d.matlabCodegenIsDeleted = false;
    SteeringWheelSTM32_DW.obj_d.isInitialized = 1;
    b.PeripheralPtr = SPI1;
    SteeringWheelSTM32_DW.obj_d.MW_SPI_HANDLE = SPI_STM32_Init(&b);
    MW_STM32_SPI_SetFormat(SteeringWheelSTM32_DW.obj_d.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    SteeringWheelSTM32_DW.obj_d.isSetupComplete = true;
    Ste_SPIControllerTransfer1_Init
      (&SteeringWheelSTM32_DW.SPIControllerTransfer1);

    /* End of SystemInitialize for SubSystem: '<S2>/CAN TX' */

    /* SystemInitialize for Enabled SubSystem: '<S4>/MCPInit' */
    Ste_SPIControllerTransfer1_Init
      (&SteeringWheelSTM32_DW.SPIControllerTransfer_p);
    S_SPIControllerTransfer1_d_Init
      (&SteeringWheelSTM32_DW.SPIControllerTransfer1_p);
    S_SPIControllerTransfer1_d_Init
      (&SteeringWheelSTM32_DW.SPIControllerTransfer2);
    S_SPIControllerTransfer1_d_Init
      (&SteeringWheelSTM32_DW.SPIControllerTransfer3);
    S_SPIControllerTransfer1_d_Init
      (&SteeringWheelSTM32_DW.SPIControllerTransfer4);

    /* End of SystemInitialize for SubSystem: '<S4>/MCPInit' */

    /* Start for MATLABSystem: '<S7>/Analog to Digital Converter' */
    SteeringWheelSTM32_DW.obj.isInitialized = 0;
    SteeringWheelSTM32_DW.obj.matlabCodegenIsDeleted = false;
    SteeringWheelS_SystemCore_setup(&SteeringWheelSTM32_DW.obj);
  }

  /* user code (Initialize function Body) */
  LL_TIM_EnableCounter(TIM2);
}

/* Model terminate function */
void SteeringWheelSTM32_terminate(void)
{
  uint32_T SPIPinsLoc;

  /* Terminate for MATLABSystem: '<S7>/Analog to Digital Converter' */
  if (!SteeringWheelSTM32_DW.obj.matlabCodegenIsDeleted) {
    SteeringWheelSTM32_DW.obj.matlabCodegenIsDeleted = true;
    if ((SteeringWheelSTM32_DW.obj.isInitialized == 1) &&
        SteeringWheelSTM32_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(SteeringWheelSTM32_DW.obj.ADCHandle, ADC_INTERRUPT_MODE,
                        1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Analog to Digital Converter' */

  /* Terminate for Enabled SubSystem: '<S2>/CAN TX' */
  /* Terminate for MATLABSystem: '<S9>/SPI Controller Transfer' */
  if (!SteeringWheelSTM32_DW.obj_d.matlabCodegenIsDeleted) {
    SteeringWheelSTM32_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((SteeringWheelSTM32_DW.obj_d.isInitialized == 1) &&
        SteeringWheelSTM32_DW.obj_d.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(SteeringWheelSTM32_DW.obj_d.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/SPI Controller Transfer' */
  Ste_SPIControllerTransfer1_Term(&SteeringWheelSTM32_DW.SPIControllerTransfer1);

  /* End of Terminate for SubSystem: '<S2>/CAN TX' */

  /* Terminate for Enabled SubSystem: '<S4>/MCPInit' */
  Ste_SPIControllerTransfer1_Term(&SteeringWheelSTM32_DW.SPIControllerTransfer_p);
  S_SPIControllerTransfer1_o_Term
    (&SteeringWheelSTM32_DW.SPIControllerTransfer1_p);
  S_SPIControllerTransfer1_o_Term(&SteeringWheelSTM32_DW.SPIControllerTransfer2);
  S_SPIControllerTransfer1_o_Term(&SteeringWheelSTM32_DW.SPIControllerTransfer3);
  S_SPIControllerTransfer1_o_Term(&SteeringWheelSTM32_DW.SPIControllerTransfer4);

  /* End of Terminate for SubSystem: '<S4>/MCPInit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
