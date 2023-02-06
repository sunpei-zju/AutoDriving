/*
 * File: ApplBTA_DBREBR_enum_def.h
 *
 * Code generated for Simulink model 'ApplBTA_LDM'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Feb  6 09:53:17 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ApplBTA_DBREBR_enum_def_h_
#define RTW_HEADER_ApplBTA_DBREBR_enum_def_h_
#include "rtwtypes.h"

typedef enum {
  brake_no_request = 0,                /* Default value */
  ACC_arbitration,
  DBR_arbitration
} BrkArbMode_en_t;

typedef enum {
  BetweenRange = 0,                    /* Default value */
  ParkRange,
  ReverseRange,
  NeutralRange,
  ForwardA,
  ForwardB,
  ForwardC,
  ForwardD,
  ForwardE,
  ForwardF,
  ForwardG,
  ForwardH,
  Unknown
} TrShftLvrPos_en_t;

typedef enum {
  initial = 0,                         /* Default value */
  standstill_control,
  dynamic_control,
  CST_standby_standstill_control,
  CST_standby_dynamic_control,
  CST_active,
  CST_off,
  CST_emergency_control
} DBRCSTRunbleSts_en_t;

typedef enum {
  ACC_off = 0,                         /* Default value */
  ACC_standby,
  ACC_CB,
  ACC_SB,
  ACC_HOLD,
  ACC_EPB
} CHACCRunbleSts_en_t;

#endif                                 /* RTW_HEADER_ApplBTA_DBREBR_enum_def_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
