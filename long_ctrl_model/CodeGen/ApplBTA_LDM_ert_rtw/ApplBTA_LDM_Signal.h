/*
 * File: ApplBTA_LDM_Signal.h
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

#ifndef RTW_HEADER_ApplBTA_LDM_Signal_h_
#define RTW_HEADER_ApplBTA_LDM_Signal_h_
#include "rtwtypes.h"
#include "ApplBTA_LDM_types.h"

/* Exported data declaration */

/* Declaration for custom storage class: ExportToFile */
extern real32_T V_LDM_aCtrlErr_f32;    /* Feedback error of Decel Controller. */
extern real32_T V_LDM_aCtrlerSetpoint_f32;
extern real32_T V_LDM_coCtrlerICoeff_f32;
extern real32_T V_LDM_coCtrlerPCoeff_f32;/* current P coefficience of Decel PID controller */
extern LDMBrkArbMode_en_t V_LDM_stBrkArbMode_en;
extern LDM_BRK_SRC_MODE_EN_T V_LDM_stBrkSrcMode_en;
extern LDMCtrlMode_en_t V_LDM_stCtrlMode_en;
extern real32_T V_LDM_torqDecelCtrlerOut_f32;
extern LDM_VLD_EN_T V_LDM_vldDecelCtrlerOutVD_bl;

#endif                                 /* RTW_HEADER_ApplBTA_LDM_Signal_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
