/*
 * File: ApplBTA_LDM.h
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

#ifndef RTW_HEADER_ApplBTA_LDM_h_
#define RTW_HEADER_ApplBTA_LDM_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ApplBTA_LDM_COMMON_INCLUDES_
# define ApplBTA_LDM_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ApplBTA_LDM_COMMON_INCLUDES_ */

#include "ApplBTA_LDM_types.h"

/* Includes for objects with custom storage classes. */
#include "ApplBTA_LDM_Param.h"
#include "ApplBTA_LDM_Signal.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T V_LDM_resetCtrlerVal;       /* '<S1>/LDM_Arbitrator' */
  real32_T V_LDM_aVehAccDecLong;       /* '<S1>/LDM_Arbitrator' */
  boolean_T V_LDM_resetCtrler_bl;      /* '<S1>/LDM_Arbitrator' */
} B_ApplBTA_LDM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S1>/Delay' */
  real32_T UnitDelay_DSTATE;           /* '<S8>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S13>/Discrete-Time Integrator' */
  real32_T UnitDelay3_DSTATE;          /* '<S1>/Unit Delay3' */
  real32_T UnitDelay1_DSTATE;          /* '<S1>/Unit Delay1' */
  real32_T V_LDM_coHighSpdI;           /* '<S1>/LDM_Arbitrator' */
  real32_T V_LDM_coHighSpdP;           /* '<S1>/LDM_Arbitrator' */
  real32_T V_LDM_coCSTI;               /* '<S1>/LDM_Arbitrator' */
  real32_T V_LDM_coCSTP;               /* '<S1>/LDM_Arbitrator' */
  real32_T V_LDM_coEbrSlfBrkP;         /* '<S1>/LDM_Arbitrator' */
  real32_T V_LDM_coEbrSlfBrkI;         /* '<S1>/LDM_Arbitrator' */
  real32_T V_LDM_coLowSpdI;            /* '<S1>/LDM_Arbitrator' */
  real32_T V_LDM_coLowSpdP;            /* '<S1>/LDM_Arbitrator' */
  real32_T V_LDM_aVehAccErr;           /* '<S1>/LDM_Arbitrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S13>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S13>/Discrete-Time Integrator' */
  uint8_T is_active_c11_LDM_Controller;/* '<S1>/VehOritArb' */
  uint8_T is_c11_LDM_Controller;       /* '<S1>/VehOritArb' */
  uint8_T is_Normal;                   /* '<S1>/VehOritArb' */
  uint8_T is_active_c10_LDM_Controller;/* '<S1>/LDM_Arbitrator' */
  uint8_T is_Decel_Control;            /* '<S1>/LDM_Arbitrator' */
  uint8_T is_DBR_control;              /* '<S1>/LDM_Arbitrator' */
  uint8_T is_DBR_DecelCtrl;            /* '<S1>/LDM_Arbitrator' */
  uint8_T is_DBR_CST;                  /* '<S1>/LDM_Arbitrator' */
  uint8_T is_EBR_control;              /* '<S1>/LDM_Arbitrator' */
  uint8_T is_EBR_DecelCtrl;            /* '<S1>/LDM_Arbitrator' */
  uint8_T is_SelfBrake;                /* '<S1>/LDM_Arbitrator' */
  boolean_T V_LDM_stClsLoopEnable;     /* '<S1>/LDM_Arbitrator' */
} DW_ApplBTA_LDM_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  BrkArbMode_en_t V_DBR_EBR_stBrkArbMode_en;/* '<Root>/V_DBR_EBR_stBrkArbMode_en' */
  boolean_T V_DBR_vldTrShftLvrPosVD_bl;/* '<Root>/V_DBR_vldTrShftLvrPosVD_bl' */
  TrShftLvrPos_en_t V_DBR_stTrShftLvrPos_en;/* '<Root>/V_DBR_stTrShftLvrPos_en' */
  real32_T V_DBR_aDBRDecelReq_f32;     /* '<Root>/V_DBR_aDBRDecelReq_f32' */
  real32_T V_EBR_aCHACCDecelReq_f32;   /* '<Root>/V_EBR_aCHACCDecelReq_f32' */
  DBRCSTRunbleSts_en_t V_DBR_stDBRCSTRunbleSts_en;/* '<Root>/V_DBR_stDBRCSTRunbleSts_en' */
  CHACCRunbleSts_en_t V_EBR_stCHACCRunbleSts_en;/* '<Root>/V_EBR_stCHACCRunbleSts_en' */
  real32_T V_VDS_aVehAccLong_f32;      /* '<Root>/V_VDS_aVehAccLong_f32' */
  real32_T V_VDS_velVehSpd_f32;        /* '<Root>/V_VDS_velVehSpd_f32' */
} ExtU_ApplBTA_LDM_T;

/* Real-time Model Data Structure */
struct tag_RTM_ApplBTA_LDM_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_ApplBTA_LDM_T ApplBTA_LDM_B;

/* Block states (default storage) */
extern DW_ApplBTA_LDM_T ApplBTA_LDM_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_ApplBTA_LDM_T ApplBTA_LDM_U;

/* Model entry point functions */
extern void ApplBTA_LDM_initialize(void);
extern void ApplBTA_LDM_step(void);
extern void ApplBTA_LDM_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ApplBTA_LDM_T *const ApplBTA_LDM_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Propagation' : Unused code path elimination
 * Block '<S13>/Scope' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Propagation' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S13>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S5>/Signal Conversion' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'ApplBTA_LDM'
 * '<S1>'   : 'ApplBTA_LDM/Parallel-Hybird Controller'
 * '<S2>'   : 'ApplBTA_LDM/Parallel-Hybird Controller/Compare To Constant1'
 * '<S3>'   : 'ApplBTA_LDM/Parallel-Hybird Controller/Compare To Zero'
 * '<S4>'   : 'ApplBTA_LDM/Parallel-Hybird Controller/Decel PI controler'
 * '<S5>'   : 'ApplBTA_LDM/Parallel-Hybird Controller/Decel open-loop controler'
 * '<S6>'   : 'ApplBTA_LDM/Parallel-Hybird Controller/Decel open-loop controler1'
 * '<S7>'   : 'ApplBTA_LDM/Parallel-Hybird Controller/Filter'
 * '<S8>'   : 'ApplBTA_LDM/Parallel-Hybird Controller/Filter1'
 * '<S9>'   : 'ApplBTA_LDM/Parallel-Hybird Controller/LDM_Arbitrator'
 * '<S10>'  : 'ApplBTA_LDM/Parallel-Hybird Controller/Saturation Dynamic'
 * '<S11>'  : 'ApplBTA_LDM/Parallel-Hybird Controller/VehOritArb'
 * '<S12>'  : 'ApplBTA_LDM/Parallel-Hybird Controller/dynamic dead zone'
 * '<S13>'  : 'ApplBTA_LDM/Parallel-Hybird Controller/Decel PI controler/PI controller'
 * '<S14>'  : 'ApplBTA_LDM/Parallel-Hybird Controller/Decel PI controler/PI controller/Anti-windup'
 * '<S15>'  : 'ApplBTA_LDM/Parallel-Hybird Controller/Decel PI controler/PI controller/Saturation Dynamic'
 * '<S16>'  : 'ApplBTA_LDM/Parallel-Hybird Controller/Decel open-loop controler/Saturation Dynamic'
 * '<S17>'  : 'ApplBTA_LDM/Parallel-Hybird Controller/Decel open-loop controler1/Saturation Dynamic'
 * '<S18>'  : 'ApplBTA_LDM/Parallel-Hybird Controller/Decel open-loop controler1/reset'
 */
#endif                                 /* RTW_HEADER_ApplBTA_LDM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
