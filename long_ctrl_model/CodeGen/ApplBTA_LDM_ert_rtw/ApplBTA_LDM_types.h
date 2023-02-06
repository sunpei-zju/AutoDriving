/*
 * File: ApplBTA_LDM_types.h
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

#ifndef RTW_HEADER_ApplBTA_LDM_types_h_
#define RTW_HEADER_ApplBTA_LDM_types_h_
#include "rtwtypes.h"
#include "ApplBTA_DBREBR_enum_def.h"
#include "ApplBTA_LDM_DataType.h"
#ifndef DEFINED_TYPEDEF_FOR_LDMCtrlMode_en_t_
#define DEFINED_TYPEDEF_FOR_LDMCtrlMode_en_t_

typedef enum {
  DecelCtrl = 0,                       /* Default value */
  OLCtrl,
  SpeedCtrl
} LDMCtrlMode_en_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_LDMBrkArbMode_en_t_
#define DEFINED_TYPEDEF_FOR_LDMBrkArbMode_en_t_

typedef enum {
  Standby = 0,                         /* Default value */
  EBR_Standby,
  EBR_NormCtrl,
  EBR_SelfBrake,
  EBR_HldPres,
  EBR_Error,
  DBR_Init,
  DBR_NormCtrl,
  DBR_EmergCtrl,
  DBR_CST,
  DBR_HldPres,
  DBR_Error
} LDMBrkArbMode_en_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_LDMVehFwBw_en_t_
#define DEFINED_TYPEDEF_FOR_LDMVehFwBw_en_t_

typedef enum {
  Backward = -1,
  Park,                                /* Default value */
  Forward,
  Null,
  Error
} LDMVehFwBw_en_t;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_ApplBTA_LDM_T RT_MODEL_ApplBTA_LDM_T;

#endif                                 /* RTW_HEADER_ApplBTA_LDM_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
