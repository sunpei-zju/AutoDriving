/*
 * File: ApplBTA_LDM_DataType.h
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

#ifndef RTW_HEADER_ApplBTA_LDM_DataType_h_
#define RTW_HEADER_ApplBTA_LDM_DataType_h_
#include "rtwtypes.h"

typedef enum {
  VALID = 0,                           /* Default value */
  INVALID
} LDM_VLD_EN_T;

typedef enum {
  BTA_EXTERNAL_BRAKE = 0,              /* Default value */
  BTA_PEDAL_APPLIED,
  BTA_PEDAL_BRAKE_NONE
} LDM_BRK_SRC_MODE_EN_T;

#endif                                 /* RTW_HEADER_ApplBTA_LDM_DataType_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
