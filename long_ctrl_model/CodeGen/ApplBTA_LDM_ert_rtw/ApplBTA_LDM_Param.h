/*
 * File: ApplBTA_LDM_Param.h
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

#ifndef RTW_HEADER_ApplBTA_LDM_Param_h_
#define RTW_HEADER_ApplBTA_LDM_Param_h_
#include "rtwtypes.h"
#include "ApplBTA_LDM_types.h"

/* Exported data declaration */

/* Declaration for custom storage class: ExportToFile */
extern real32_T K10_LDM_aOLCtrlerTableX[10];/* Input breakpoints of table for open loop controller (from decel request to brake torq) */
extern real32_T K10_LDM_torqOLCtrlerTableY[10];/* Output breakpoints of table for open loop controller (from decel request to brake torq) */
extern boolean_T K_LDM_blClsLoopCtrlEnable_bl;
extern real32_T K_LDM_coDecelCtrlCl2OlLim;
extern real32_T K_LDM_coDecelCtrlHigh2LowLim;
extern real32_T K_LDM_coDecelCtrlLow2HighLim;
extern real32_T K_LDM_coDecelCtrlOl2ClLim;
extern real32_T K_LDM_coDecelParalCtrlCST_I;
extern real32_T K_LDM_coDecelParalCtrlCST_P;
extern real32_T K_LDM_coDecelParalCtrlEbrSB_I;
extern real32_T K_LDM_coDecelParalCtrlEbrSB_P;
extern real32_T K_LDM_coDecelParalCtrlHighSpd_I;
extern real32_T K_LDM_coDecelParalCtrlHighSpd_P;
extern real32_T K_LDM_coDecelParalCtrlLowSpd_I;
extern real32_T K_LDM_coDecelParalCtrlLowSpd_P;
extern real32_T K_LDM_torqDecelClsCtrlerLowLim;
extern real32_T K_LDM_torqDecelClsCtrlerUpLim;
extern real32_T K_LDM_torqDecelCtrlerLowLim;
extern real32_T K_LDM_torqDecelCtrlerUpLim;
extern real32_T K_LDM_torqOLCtrlerLowLim;
extern real32_T K_LDM_torqOLCtrlerUpLim;

#endif                                 /* RTW_HEADER_ApplBTA_LDM_Param_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
