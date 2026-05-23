/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SteeringWheelSTM32.c
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

#include "SteeringWheelSTM32.h"
#include "rtwtypes.h"
#include "SteeringWheelSTM32_types.h"
#include "SteeringWheelSTM32_private.h"
#include "mw_stm32_spi_ll.h"
#include "stm_adc_ll.h"

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

  /* Start for MATLABSystem: '<S2>/SPI Controller Transfer1' */
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

  /* MATLABSystem: '<S2>/SPI Controller Transfer1' */
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

  /* End of MATLABSystem: '<S2>/SPI Controller Transfer1' */
}

/* Termination for atomic system: */
void Ste_SPIControllerTransfer1_Term(DW_SPIControllerTransfer1_Ste_T *localDW)
{
  /* Terminate for MATLABSystem: '<S2>/SPI Controller Transfer1' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/SPI Controller Transfer1' */
}

/* System initialize for atomic system: */
void S_SPIControllerTransfer1_d_Init(DW_SPIControllerTransfer1_S_f_T *localDW)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S11>/SPI Controller Transfer1' */
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

  /* MATLABSystem: '<S11>/SPI Controller Transfer1' */
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

  /* End of MATLABSystem: '<S11>/SPI Controller Transfer1' */
}

/* Termination for atomic system: */
void S_SPIControllerTransfer1_o_Term(DW_SPIControllerTransfer1_S_f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S11>/SPI Controller Transfer1' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/SPI Controller Transfer1' */
}

static void SteeringWheelS_SystemCore_setup(stm32cube_blocks_AnalogInputF_T *obj)
{
  ADC_Type_T adcStructLoc;

  /* Start for MATLABSystem: '<S15>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  obj->ADCInternalBuffer = GET_ADC1_DMA_BUFFER();
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.InternalBufferPtr = obj->ADCInternalBuffer;
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = DMA1;
  adcStructLoc.dmastream = LL_DMA_STREAM_0;
  adcStructLoc.DataTransferMode = ADC_DMA_CIRCULAR;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 5U;
  adcStructLoc.RegularNoOfConversion = 5U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_DMA_INTERRUPT_MODE, 1,
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
  uint8_T status;
  boolean_T rtb_Step1_tmp;

  /* MATLABSystem: '<S20>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

  /* Logic: '<Root>/NOT2' incorporates:
   *  MATLABSystem: '<S20>/Digital Port Read'
   * */
  SteeringWheelSTM32_B.NOT2 = ((pinReadLoc & 2048U) == 0U);

  /* Logic: '<Root>/NOT3' incorporates:
   *  MATLABSystem: '<S20>/Digital Port Read'
   * */
  SteeringWheelSTM32_B.NOT3 = ((pinReadLoc & 4096U) == 0U);

  /* Logic: '<Root>/NOT1' incorporates:
   *  MATLABSystem: '<S20>/Digital Port Read'
   * */
  SteeringWheelSTM32_B.NOT1 = ((pinReadLoc & 1024U) == 0U);

  /* Logic: '<Root>/NOT' incorporates:
   *  MATLABSystem: '<S20>/Digital Port Read'
   * */
  SteeringWheelSTM32_B.NOT = ((pinReadLoc & 512U) == 0U);

  /* Lookup_n-D: '<S13>/1-D Lookup Table2' incorporates:
   *  Memory: '<S13>/Memory2'
   */
  SteeringWheelSTM32_B.uDLookupTable2 =
    SteeringWheelSTM32_ConstP.pooled6[plook_u32f_binckan
    (SteeringWheelSTM32_DW.Memory2_PreviousInput,
     SteeringWheelSTM32_ConstP.pooled4, 15U)];

  /* Lookup_n-D: '<S13>/1-D Lookup Table' incorporates:
   *  Memory: '<S13>/Memory'
   */
  SteeringWheelSTM32_B.uDLookupTable =
    SteeringWheelSTM32_ConstP.pooled6[plook_u32f_binckan
    (SteeringWheelSTM32_DW.Memory_PreviousInput,
     SteeringWheelSTM32_ConstP.pooled4, 15U)];

  /* Lookup_n-D: '<S13>/1-D Lookup Table1' incorporates:
   *  Memory: '<S13>/Memory1'
   */
  SteeringWheelSTM32_B.uDLookupTable1 =
    SteeringWheelSTM32_ConstP.pooled6[plook_u32f_binckan
    (SteeringWheelSTM32_DW.Memory1_PreviousInput,
     SteeringWheelSTM32_ConstP.pooled4, 15U)];

  /* MATLABSystem: '<S15>/Analog to Digital Converter' */
  regularReadADCDMA(SteeringWheelSTM32_DW.obj.ADCHandle, ADC_READ,
                    &rtb_AnalogtoDigitalConverter_0[0]);
  for (i = 0; i < 5; i++) {
    /* Gain: '<Root>/Gain4' incorporates:
     *  MATLABSystem: '<S15>/Analog to Digital Converter'
     */
    SteeringWheelSTM32_B.Gain4[i] = 5.03547708E-5F * (real32_T)
      rtb_AnalogtoDigitalConverter_0[i];
  }

  /* S-Function (scanpack): '<Root>/CAN Pack' */
  /* S-Function (scanpack): '<Root>/CAN Pack' */
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
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (SteeringWheelSTM32_B.uDLookupTable2);

        /* no scaling required */
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
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (SteeringWheelSTM32_B.uDLookupTable);

        /* no scaling required */
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
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (SteeringWheelSTM32_B.uDLookupTable1);

        /* no scaling required */
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
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = SteeringWheelSTM32_B.Gain4[3];

        /* no scaling required */
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
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = SteeringWheelSTM32_B.Gain4[4];

        /* no scaling required */
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

  /* Outputs for Enabled SubSystem: '<Root>/CAN TX' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* DataStoreRead: '<Root>/Data Store Read' incorporates:
   *  Constant: '<S2>/RTS'
   *  Constant: '<S2>/TX Buffer 0'
   *  Constant: '<S2>/WRITE Instruction'
   */
  if (SteeringWheelSTM32_DW.MCPInitialized) {
    /* MATLAB Function: '<S2>/MATLAB Function' */
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

    /* End of MATLAB Function: '<S2>/MATLAB Function' */
    rtb_VectorConcatenate[0] = 2U;
    rtb_VectorConcatenate[1] = 49U;

    /* MATLABSystem: '<S2>/SPI Controller Transfer' incorporates:
     *  Concatenate: '<S2>/Vector Concatenate'
     *  Constant: '<S2>/TX Buffer 0'
     *  Constant: '<S2>/WRITE Instruction'
     */
    status = MW_STM32_SPI_SetFormat(SteeringWheelSTM32_DW.obj_d.MW_SPI_HANDLE,
      0U, 1792U, MW_SPI_MODE_2);
    if (status == 0) {
      portNameLoc = GPIOA;
      LL_GPIO_ResetOutputPin(portNameLoc, 16U);
      MW_SPI_MasterWriteRead_Databits(SteeringWheelSTM32_DW.obj_d.MW_SPI_HANDLE,
        &rtb_VectorConcatenate[0], &tmp[0], 0, 15U, 1, 10U);
      LL_GPIO_SetOutputPin(portNameLoc, 16U);
    }

    /* End of MATLABSystem: '<S2>/SPI Controller Transfer' */
    Steering_SPIControllerTransfer1(129,
      &SteeringWheelSTM32_DW.SPIControllerTransfer1);
  }

  /* End of DataStoreRead: '<Root>/Data Store Read' */
  /* End of Outputs for SubSystem: '<Root>/CAN TX' */

  /* MATLABSystem: '<S22>/Digital Port Write' */
  portNameLoc = GPIOB;
  if (SteeringWheelSTM32_B.NOT) {
    i = 4;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 4U);

  /* End of MATLABSystem: '<S22>/Digital Port Write' */

  /* MATLABSystem: '<S24>/Digital Port Write' incorporates:
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  portNameLoc = GPIOB;
  if (SteeringWheelSTM32_B.Gain4[0] <= 1.5F) {
    i = 2;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 2U);

  /* End of MATLABSystem: '<S24>/Digital Port Write' */

  /* Step: '<Root>/Step1' */
  rtb_Step1_tmp = !(((SteeringWheelSTM32_M->Timing.clockTick0) * 0.001) < 1.0);

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  /* RelationalOperator: '<S6>/FixPt Relational Operator' incorporates:
   *  Constant: '<S11>/ 000: normal mode, 0: don't abort pending transmit buffers, 0: one-shot disabled, 0: CLKOUT disabled, 00: sysclk//1 | 0000 0000 | 0x00'
   *  Constant: '<S11>/CNF1'
   *  Constant: '<S11>/CNF2'
   *  Constant: '<S11>/CNF3'
   *  Constant: '<S11>/Enter Configuration Mode'
   *  UnitDelay: '<S6>/Delay Input1'
   *
   * Block description for '<S6>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((real_T)rtb_Step1_tmp > SteeringWheelSTM32_DW.DelayInput1_DSTATE) {
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

  /* End of RelationalOperator: '<S6>/FixPt Relational Operator' */
  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem1' */

  /* UnitDelay: '<Root>/Unit Delay' */
  rtb_UnitDelay = SteeringWheelSTM32_DW.UnitDelay_DSTATE;

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem2' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  /* DataStoreWrite: '<S12>/Data Store Write' incorporates:
   *  RelationalOperator: '<S7>/FixPt Relational Operator'
   *  UnitDelay: '<Root>/Unit Delay'
   *  UnitDelay: '<S7>/Delay Input1'
   *
   * Block description for '<S7>/Delay Input1':
   *
   *  Store in Global RAM
   */
  SteeringWheelSTM32_DW.MCPInitialized =
    ((SteeringWheelSTM32_DW.UnitDelay_DSTATE >
      SteeringWheelSTM32_DW.DelayInput1_DSTATE_l) ||
     SteeringWheelSTM32_DW.MCPInitialized);

  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem2' */

  /* Switch: '<S13>/Switch2' */
  if (SteeringWheelSTM32_B.Gain4[2] > 0.2F) {
    /* Update for Memory: '<S13>/Memory2' */
    SteeringWheelSTM32_DW.Memory2_PreviousInput = SteeringWheelSTM32_B.Gain4[2];
  }

  /* End of Switch: '<S13>/Switch2' */

  /* Switch: '<S13>/Switch' */
  if (SteeringWheelSTM32_B.Gain4[0] > 0.2F) {
    /* Update for Memory: '<S13>/Memory' */
    SteeringWheelSTM32_DW.Memory_PreviousInput = SteeringWheelSTM32_B.Gain4[0];
  }

  /* End of Switch: '<S13>/Switch' */

  /* Switch: '<S13>/Switch1' */
  if (SteeringWheelSTM32_B.Gain4[1] > 0.2F) {
    /* Update for Memory: '<S13>/Memory1' */
    SteeringWheelSTM32_DW.Memory1_PreviousInput = SteeringWheelSTM32_B.Gain4[1];
  }

  /* End of Switch: '<S13>/Switch1' */

  /* Update for UnitDelay: '<S6>/Delay Input1'
   *
   * Block description for '<S6>/Delay Input1':
   *
   *  Store in Global RAM
   */
  SteeringWheelSTM32_DW.DelayInput1_DSTATE = rtb_Step1_tmp;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  SteeringWheelSTM32_DW.UnitDelay_DSTATE = rtb_Step1_tmp;

  /* Update for UnitDelay: '<S7>/Delay Input1'
   *
   * Block description for '<S7>/Delay Input1':
   *
   *  Store in Global RAM
   */
  SteeringWheelSTM32_DW.DelayInput1_DSTATE_l = rtb_UnitDelay;

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

    /* InitializeConditions for Memory: '<S13>/Memory2' */
    SteeringWheelSTM32_DW.Memory2_PreviousInput = 1.9F;

    /* InitializeConditions for Memory: '<S13>/Memory' */
    SteeringWheelSTM32_DW.Memory_PreviousInput = 1.9F;

    /* InitializeConditions for Memory: '<S13>/Memory1' */
    SteeringWheelSTM32_DW.Memory1_PreviousInput = 1.9F;

    /* SystemInitialize for Enabled SubSystem: '<Root>/CAN TX' */
    /* Start for MATLABSystem: '<S2>/SPI Controller Transfer' */
    SteeringWheelSTM32_DW.obj_d.matlabCodegenIsDeleted = false;
    SteeringWheelSTM32_DW.obj_d.isInitialized = 1;
    b.PeripheralPtr = SPI1;
    SteeringWheelSTM32_DW.obj_d.MW_SPI_HANDLE = SPI_STM32_Init(&b);
    MW_STM32_SPI_SetFormat(SteeringWheelSTM32_DW.obj_d.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    SteeringWheelSTM32_DW.obj_d.isSetupComplete = true;
    Ste_SPIControllerTransfer1_Init
      (&SteeringWheelSTM32_DW.SPIControllerTransfer1);

    /* End of SystemInitialize for SubSystem: '<Root>/CAN TX' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem1' */
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

    /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem1' */

    /* Start for MATLABSystem: '<S15>/Analog to Digital Converter' */
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

  /* Terminate for MATLABSystem: '<S15>/Analog to Digital Converter' */
  if (!SteeringWheelSTM32_DW.obj.matlabCodegenIsDeleted) {
    SteeringWheelSTM32_DW.obj.matlabCodegenIsDeleted = true;
    if ((SteeringWheelSTM32_DW.obj.isInitialized == 1) &&
        SteeringWheelSTM32_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(SteeringWheelSTM32_DW.obj.ADCHandle,
                        ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/Analog to Digital Converter' */

  /* Terminate for Enabled SubSystem: '<Root>/CAN TX' */
  /* Terminate for MATLABSystem: '<S2>/SPI Controller Transfer' */
  if (!SteeringWheelSTM32_DW.obj_d.matlabCodegenIsDeleted) {
    SteeringWheelSTM32_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((SteeringWheelSTM32_DW.obj_d.isInitialized == 1) &&
        SteeringWheelSTM32_DW.obj_d.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(SteeringWheelSTM32_DW.obj_d.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/SPI Controller Transfer' */
  Ste_SPIControllerTransfer1_Term(&SteeringWheelSTM32_DW.SPIControllerTransfer1);

  /* End of Terminate for SubSystem: '<Root>/CAN TX' */

  /* Terminate for Enabled SubSystem: '<Root>/Enabled Subsystem1' */
  Ste_SPIControllerTransfer1_Term(&SteeringWheelSTM32_DW.SPIControllerTransfer_p);
  S_SPIControllerTransfer1_o_Term
    (&SteeringWheelSTM32_DW.SPIControllerTransfer1_p);
  S_SPIControllerTransfer1_o_Term(&SteeringWheelSTM32_DW.SPIControllerTransfer2);
  S_SPIControllerTransfer1_o_Term(&SteeringWheelSTM32_DW.SPIControllerTransfer3);
  S_SPIControllerTransfer1_o_Term(&SteeringWheelSTM32_DW.SPIControllerTransfer4);

  /* End of Terminate for SubSystem: '<Root>/Enabled Subsystem1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
