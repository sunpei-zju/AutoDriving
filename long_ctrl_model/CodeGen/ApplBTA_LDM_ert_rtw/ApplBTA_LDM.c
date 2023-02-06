/*
 * File: ApplBTA_LDM.c
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

#include "ApplBTA_LDM.h"
#include "ApplBTA_LDM_private.h"

/* Named constants for Chart: '<S1>/LDM_Arbitrator' */
#define ApplBTA_IN_DecelCtrl_CL_HighSpd ((uint8_T)1U)
#define ApplBTA_LDM_IN_CST_OL          ((uint8_T)1U)
#define ApplBTA_LDM_IN_CST_follow      ((uint8_T)2U)
#define ApplBTA_LDM_IN_DBR_CST         ((uint8_T)1U)
#define ApplBTA_LDM_IN_DBR_DecelCtrl   ((uint8_T)2U)
#define ApplBTA_LDM_IN_DBR_control     ((uint8_T)1U)
#define ApplBTA_LDM_IN_DecelCtrl_OL    ((uint8_T)3U)
#define ApplBTA_LDM_IN_EBR_DecelCtrl   ((uint8_T)1U)
#define ApplBTA_LDM_IN_EBR_Standby     ((uint8_T)2U)
#define ApplBTA_LDM_IN_EBR_control     ((uint8_T)2U)
#define ApplBTA_LDM_IN_HoldPressure    ((uint8_T)3U)
#define ApplBTA_LDM_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define ApplBTA_LDM_IN_SelfBrake       ((uint8_T)4U)
#define ApplBTA_LDM_IN_SelfBrake_OL    ((uint8_T)1U)
#define ApplBTA_LDM_IN_SelfBrake_follow ((uint8_T)2U)
#define ApplBTA_LDM_IN_Standby         ((uint8_T)3U)
#define ApplBTA_LDM_IN_initial         ((uint8_T)4U)
#define ApplBTA__IN_DecelCtrl_CL_LowSpd ((uint8_T)2U)

/* Named constants for Chart: '<S1>/VehOritArb' */
#define ApplBTA_LDM_IN_Backward        ((uint8_T)1U)
#define ApplBTA_LDM_IN_Error           ((uint8_T)1U)
#define ApplBTA_LDM_IN_Forward         ((uint8_T)2U)
#define ApplBTA_LDM_IN_Normal          ((uint8_T)2U)
#define ApplBTA_LDM_IN_Null            ((uint8_T)3U)
#define ApplBTA_LDM_IN_Park            ((uint8_T)4U)

/* Exported data definition */

/* Definition for custom storage class: ExportToFile */
real32_T K10_LDM_aOLCtrlerTableX[10] = { 0.0F, 0.5F, 1.0F, 2.0F, 3.0F, 4.0F,
  5.0F, 6.0F, 7.0F, 8.0F } ;           /* Input breakpoints of table for open loop controller (from decel request to brake torq) */

real32_T K10_LDM_torqOLCtrlerTableY[10] = { 0.0F, 241.5F, 667.0F, 1552.5F,
  2311.5F, 3277.5F, 4025.0F, 4772.5F, 5865.0F, 7245.0F } ;/* Output breakpoints of table for open loop controller (from decel request to brake torq) */

boolean_T K_LDM_blClsLoopCtrlEnable_bl = 0;
real32_T K_LDM_coDecelCtrlCl2OlLim = 2.0F;
real32_T K_LDM_coDecelCtrlHigh2LowLim = 20.0F;
real32_T K_LDM_coDecelCtrlLow2HighLim = 22.0F;
real32_T K_LDM_coDecelCtrlOl2ClLim = 3.0F;
real32_T K_LDM_coDecelParalCtrlCST_I = 500.0F;
real32_T K_LDM_coDecelParalCtrlCST_P = 150.0F;
real32_T K_LDM_coDecelParalCtrlEbrSB_I = 500.0F;
real32_T K_LDM_coDecelParalCtrlEbrSB_P = 150.0F;
real32_T K_LDM_coDecelParalCtrlHighSpd_I = 2000.0F;
real32_T K_LDM_coDecelParalCtrlHighSpd_P = 300.0F;
real32_T K_LDM_coDecelParalCtrlLowSpd_I = 500.0F;
real32_T K_LDM_coDecelParalCtrlLowSpd_P = 150.0F;
real32_T K_LDM_torqDecelClsCtrlerLowLim = -1000.0F;
real32_T K_LDM_torqDecelClsCtrlerUpLim = 1000.0F;
real32_T K_LDM_torqDecelCtrlerLowLim = 0.0F;
real32_T K_LDM_torqDecelCtrlerUpLim = 20000.0F;
real32_T K_LDM_torqOLCtrlerLowLim = 0.0F;
real32_T K_LDM_torqOLCtrlerUpLim = 20000.0F;
real32_T V_LDM_aCtrlErr_f32;           /* Feedback error of Decel Controller. */
real32_T V_LDM_aCtrlerSetpoint_f32;
real32_T V_LDM_coCtrlerICoeff_f32;
real32_T V_LDM_coCtrlerPCoeff_f32;     /* current P coefficience of Decel PID controller */
LDMBrkArbMode_en_t V_LDM_stBrkArbMode_en;
LDM_BRK_SRC_MODE_EN_T V_LDM_stBrkSrcMode_en;
LDMCtrlMode_en_t V_LDM_stCtrlMode_en;
real32_T V_LDM_torqDecelCtrlerOut_f32;
LDM_VLD_EN_T V_LDM_vldDecelCtrlerOutVD_bl;

/* Block signals (default storage) */
B_ApplBTA_LDM_T ApplBTA_LDM_B;

/* Block states (default storage) */
DW_ApplBTA_LDM_T ApplBTA_LDM_DW;

/* External inputs (root inport signals with default storage) */
ExtU_ApplBTA_LDM_T ApplBTA_LDM_U;

/* Real-time model */
RT_MODEL_ApplBTA_LDM_T ApplBTA_LDM_M_;
RT_MODEL_ApplBTA_LDM_T *const ApplBTA_LDM_M = &ApplBTA_LDM_M_;

/* Forward declaration for local functions */
static void ApplBTA_L_enter_internal_Normal(LDMVehFwBw_en_t *V_LDM_stVehFwBw_en);
static void Appl_enter_internal_EBR_control(void);
static void Appl_enter_internal_DBR_control(void);
static void ApplBTA_LDM_DBR_control(void);
static void ApplBTA_LDM_EBR_control(void);
real32_T look1_iflf_binlxpw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/* Function for Chart: '<S1>/VehOritArb' */
static void ApplBTA_L_enter_internal_Normal(LDMVehFwBw_en_t *V_LDM_stVehFwBw_en)
{
  /* Inport: '<Root>/V_DBR_stTrShftLvrPos_en' */
  switch (ApplBTA_LDM_U.V_DBR_stTrShftLvrPos_en) {
   case ParkRange:
    ApplBTA_LDM_DW.is_Normal = ApplBTA_LDM_IN_Park;
    *V_LDM_stVehFwBw_en = Park;
    break;

   case ReverseRange:
    ApplBTA_LDM_DW.is_Normal = ApplBTA_LDM_IN_Backward;
    *V_LDM_stVehFwBw_en = Backward;
    break;

   default:
    if ((ApplBTA_LDM_U.V_DBR_stTrShftLvrPos_en == BetweenRange) ||
        (ApplBTA_LDM_U.V_DBR_stTrShftLvrPos_en == NeutralRange) ||
        (ApplBTA_LDM_U.V_DBR_stTrShftLvrPos_en == Unknown)) {
      ApplBTA_LDM_DW.is_Normal = ApplBTA_LDM_IN_Null;
      *V_LDM_stVehFwBw_en = Null;
    } else {
      ApplBTA_LDM_DW.is_Normal = ApplBTA_LDM_IN_Forward;
      *V_LDM_stVehFwBw_en = Forward;
    }
    break;
  }

  /* End of Inport: '<Root>/V_DBR_stTrShftLvrPos_en' */
}

/* Function for Chart: '<S1>/LDM_Arbitrator' */
static void Appl_enter_internal_EBR_control(void)
{
  real32_T tmp;
  boolean_T guard1 = false;

  /* Inport: '<Root>/V_EBR_stCHACCRunbleSts_en' */
  guard1 = false;
  if (ApplBTA_LDM_U.V_EBR_stCHACCRunbleSts_en == ACC_standby) {
    guard1 = true;
  } else if (ApplBTA_LDM_U.V_EBR_stCHACCRunbleSts_en == ACC_CB) {
    V_LDM_stBrkArbMode_en = EBR_NormCtrl;
    ApplBTA_LDM_DW.is_EBR_control = ApplBTA_LDM_IN_EBR_DecelCtrl;

    /* Inport: '<Root>/V_VDS_velVehSpd_f32' */
    if ((fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) <= K_LDM_coDecelCtrlCl2OlLim) ||
        ((!(fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) <=
            K_LDM_coDecelCtrlCl2OlLim)) && (!K_LDM_blClsLoopCtrlEnable_bl))) {
      ApplBTA_LDM_DW.is_EBR_DecelCtrl = ApplBTA_LDM_IN_DecelCtrl_OL;

      /* Delay: '<S1>/Delay' */
      ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE;
      ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
      V_LDM_coCtrlerPCoeff_f32 = 0.0F;
      V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdI /
        ApplBTA_LDM_DW.V_LDM_coLowSpdP;
    } else if (fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) <=
               K_LDM_coDecelCtrlHigh2LowLim) {
      ApplBTA_LDM_DW.is_EBR_DecelCtrl = ApplBTA__IN_DecelCtrl_CL_LowSpd;
      V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
      V_LDM_stCtrlMode_en = DecelCtrl;
      V_LDM_coCtrlerPCoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdP;
      V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdI;

      /* Delay: '<S1>/Delay' */
      ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE -
        V_LDM_coCtrlerPCoeff_f32 * V_LDM_aCtrlErr_f32;
      ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
    } else {
      ApplBTA_LDM_DW.is_EBR_DecelCtrl = ApplBTA_IN_DecelCtrl_CL_HighSpd;
      V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
      V_LDM_stCtrlMode_en = DecelCtrl;
      V_LDM_coCtrlerPCoeff_f32 = ApplBTA_LDM_DW.V_LDM_coHighSpdP;
      V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coHighSpdI;

      /* Delay: '<S1>/Delay' */
      ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE -
        V_LDM_coCtrlerPCoeff_f32 * V_LDM_aCtrlErr_f32;
      ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
    }
  } else if (ApplBTA_LDM_U.V_EBR_stCHACCRunbleSts_en == ACC_SB) {
    V_LDM_stBrkArbMode_en = EBR_SelfBrake;
    ApplBTA_LDM_DW.is_EBR_control = ApplBTA_LDM_IN_SelfBrake;

    /* Inport: '<Root>/V_VDS_velVehSpd_f32' */
    tmp = fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32);
    if ((tmp <= K_LDM_coDecelCtrlCl2OlLim) || ((!(tmp <=
           K_LDM_coDecelCtrlCl2OlLim)) && (!K_LDM_blClsLoopCtrlEnable_bl))) {
      ApplBTA_LDM_DW.is_SelfBrake = ApplBTA_LDM_IN_SelfBrake_OL;

      /* Delay: '<S1>/Delay' */
      ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE;
      ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
      V_LDM_coCtrlerPCoeff_f32 = 0.0F;
      V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coEbrSlfBrkI /
        ApplBTA_LDM_DW.V_LDM_coEbrSlfBrkP;
    } else {
      ApplBTA_LDM_DW.is_SelfBrake = ApplBTA_LDM_IN_SelfBrake_follow;
      V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
      V_LDM_stCtrlMode_en = DecelCtrl;
      V_LDM_coCtrlerPCoeff_f32 = ApplBTA_LDM_DW.V_LDM_coEbrSlfBrkP;
      V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coEbrSlfBrkI;

      /* Delay: '<S1>/Delay' */
      ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE -
        V_LDM_coCtrlerPCoeff_f32 * V_LDM_aCtrlErr_f32;
      ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
    }
  } else if (ApplBTA_LDM_U.V_EBR_stCHACCRunbleSts_en == ACC_HOLD) {
    ApplBTA_LDM_DW.is_EBR_control = ApplBTA_LDM_IN_HoldPressure;
    V_LDM_stCtrlMode_en = OLCtrl;
    V_LDM_coCtrlerPCoeff_f32 = 0.0F;
    V_LDM_coCtrlerICoeff_f32 = 0.0F;
    ApplBTA_LDM_B.V_LDM_resetCtrlerVal = 0.0F;
    ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
  } else {
    V_LDM_stBrkArbMode_en = EBR_Error;
    guard1 = true;
  }

  if (guard1) {
    ApplBTA_LDM_DW.is_EBR_control = ApplBTA_LDM_IN_EBR_Standby;
    V_LDM_stBrkArbMode_en = EBR_Standby;
    V_LDM_stCtrlMode_en = OLCtrl;
    V_LDM_aCtrlerSetpoint_f32 = 0.0F;
    V_LDM_coCtrlerPCoeff_f32 = 0.0F;
    V_LDM_coCtrlerICoeff_f32 = 0.0F;
    V_LDM_aCtrlErr_f32 = 0.0F;
    ApplBTA_LDM_B.V_LDM_resetCtrlerVal = 0.0F;
    ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
  }

  /* End of Inport: '<Root>/V_EBR_stCHACCRunbleSts_en' */
}

/* Function for Chart: '<S1>/LDM_Arbitrator' */
static void Appl_enter_internal_DBR_control(void)
{
  real32_T tmp;
  boolean_T guard1 = false;

  /* Inport: '<Root>/V_DBR_stDBRCSTRunbleSts_en' */
  if (ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en == initial) {
    ApplBTA_LDM_DW.is_DBR_control = ApplBTA_LDM_IN_initial;
    V_LDM_stBrkArbMode_en = DBR_Init;
    V_LDM_stCtrlMode_en = OLCtrl;
  } else {
    guard1 = false;
    if (ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en == CST_emergency_control) {
      V_LDM_stBrkArbMode_en = DBR_EmergCtrl;
      guard1 = true;
    } else if ((ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en == dynamic_control) ||
               (ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en ==
                CST_standby_dynamic_control)) {
      V_LDM_stBrkArbMode_en = DBR_NormCtrl;
      guard1 = true;
    } else if (ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en == CST_active) {
      V_LDM_stBrkArbMode_en = DBR_CST;
      ApplBTA_LDM_DW.is_DBR_control = ApplBTA_LDM_IN_DBR_CST;

      /* Inport: '<Root>/V_VDS_velVehSpd_f32' */
      tmp = fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32);
      if ((tmp <= K_LDM_coDecelCtrlCl2OlLim) || ((!(tmp <=
             K_LDM_coDecelCtrlCl2OlLim)) &&
           (!ApplBTA_LDM_DW.V_LDM_stClsLoopEnable))) {
        ApplBTA_LDM_DW.is_DBR_CST = ApplBTA_LDM_IN_CST_OL;

        /* Delay: '<S1>/Delay' */
        ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE;
        ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
        V_LDM_coCtrlerPCoeff_f32 = 0.0F;
        V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coCSTI /
          ApplBTA_LDM_DW.V_LDM_coCSTP;
      } else {
        ApplBTA_LDM_DW.is_DBR_CST = ApplBTA_LDM_IN_CST_follow;
        V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
        V_LDM_stCtrlMode_en = DecelCtrl;
        V_LDM_coCtrlerPCoeff_f32 = ApplBTA_LDM_DW.V_LDM_coCSTP;
        V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coCSTI;

        /* Delay: '<S1>/Delay' */
        ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE -
          V_LDM_coCtrlerPCoeff_f32 * V_LDM_aCtrlErr_f32;
        ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
      }
    } else if ((ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en == CST_off) ||
               (ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en ==
                CST_standby_standstill_control) ||
               (ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en == standstill_control))
    {
      ApplBTA_LDM_DW.is_DBR_control = ApplBTA_LDM_IN_HoldPressure;
      V_LDM_stBrkArbMode_en = DBR_HldPres;
      V_LDM_stCtrlMode_en = OLCtrl;
      V_LDM_coCtrlerPCoeff_f32 = 0.0F;
      V_LDM_coCtrlerICoeff_f32 = 0.0F;
      ApplBTA_LDM_B.V_LDM_resetCtrlerVal = 0.0F;
      ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
    } else {
      V_LDM_stBrkArbMode_en = DBR_Error;
      guard1 = true;
    }

    if (guard1) {
      ApplBTA_LDM_DW.is_DBR_control = ApplBTA_LDM_IN_DBR_DecelCtrl;

      /* Inport: '<Root>/V_VDS_velVehSpd_f32' */
      if ((fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) <= K_LDM_coDecelCtrlCl2OlLim)
          || ((!(fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) <=
                 K_LDM_coDecelCtrlCl2OlLim)) &&
              (!ApplBTA_LDM_DW.V_LDM_stClsLoopEnable))) {
        ApplBTA_LDM_DW.is_DBR_DecelCtrl = ApplBTA_LDM_IN_DecelCtrl_OL;
        V_LDM_coCtrlerPCoeff_f32 = 0.0F;
        V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdI /
          ApplBTA_LDM_DW.V_LDM_coLowSpdP;

        /* Delay: '<S1>/Delay' */
        ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE;
        ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
      } else if (fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) <=
                 K_LDM_coDecelCtrlHigh2LowLim) {
        ApplBTA_LDM_DW.is_DBR_DecelCtrl = ApplBTA__IN_DecelCtrl_CL_LowSpd;
        V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
        V_LDM_stCtrlMode_en = DecelCtrl;
        V_LDM_coCtrlerPCoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdP;
        V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdI;

        /* Delay: '<S1>/Delay' */
        ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE -
          V_LDM_coCtrlerPCoeff_f32 * V_LDM_aCtrlErr_f32;
        ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
      } else {
        ApplBTA_LDM_DW.is_DBR_DecelCtrl = ApplBTA_IN_DecelCtrl_CL_HighSpd;
        V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
        V_LDM_stCtrlMode_en = DecelCtrl;
        V_LDM_coCtrlerPCoeff_f32 = ApplBTA_LDM_DW.V_LDM_coHighSpdP;
        V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coHighSpdI;

        /* Delay: '<S1>/Delay' */
        ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE -
          V_LDM_coCtrlerPCoeff_f32 * V_LDM_aCtrlErr_f32;
        ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
      }
    }
  }

  /* End of Inport: '<Root>/V_DBR_stDBRCSTRunbleSts_en' */
}

/* Function for Chart: '<S1>/LDM_Arbitrator' */
static void ApplBTA_LDM_DBR_control(void)
{
  /* Inport: '<Root>/V_DBR_EBR_stBrkArbMode_en' */
  switch (ApplBTA_LDM_U.V_DBR_EBR_stBrkArbMode_en) {
   case brake_no_request:
    ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
    ApplBTA_LDM_DW.is_DBR_CST = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
    ApplBTA_LDM_DW.is_DBR_DecelCtrl = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
    ApplBTA_LDM_DW.is_DBR_control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
    ApplBTA_LDM_DW.is_Decel_Control = ApplBTA_LDM_IN_Standby;
    V_LDM_stBrkSrcMode_en = BTA_PEDAL_BRAKE_NONE;
    V_LDM_aCtrlerSetpoint_f32 = 0.0F;
    V_LDM_coCtrlerPCoeff_f32 = 0.0F;
    V_LDM_coCtrlerICoeff_f32 = 0.0F;
    V_LDM_aCtrlErr_f32 = 0.0F;
    V_LDM_stBrkArbMode_en = Standby;
    ApplBTA_LDM_B.V_LDM_resetCtrlerVal = 0.0F;
    ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
    break;

   case ACC_arbitration:
    ApplBTA_LDM_DW.is_DBR_CST = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
    ApplBTA_LDM_DW.is_DBR_DecelCtrl = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
    ApplBTA_LDM_DW.is_DBR_control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
    ApplBTA_LDM_DW.is_Decel_Control = ApplBTA_LDM_IN_EBR_control;
    V_LDM_stBrkSrcMode_en = BTA_EXTERNAL_BRAKE;

    /* Inport: '<Root>/V_EBR_aCHACCDecelReq_f32' */
    V_LDM_aCtrlerSetpoint_f32 = ApplBTA_LDM_U.V_EBR_aCHACCDecelReq_f32;
    Appl_enter_internal_EBR_control();
    break;

   default:
    V_LDM_stBrkSrcMode_en = BTA_PEDAL_APPLIED;

    /* Inport: '<Root>/V_DBR_aDBRDecelReq_f32' */
    V_LDM_aCtrlerSetpoint_f32 = ApplBTA_LDM_U.V_DBR_aDBRDecelReq_f32;
    switch (ApplBTA_LDM_DW.is_DBR_control) {
     case ApplBTA_LDM_IN_DBR_CST:
      /* Inport: '<Root>/V_DBR_stDBRCSTRunbleSts_en' incorporates:
       *  Inport: '<Root>/V_VDS_velVehSpd_f32'
       */
      if (ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en != CST_active) {
        ApplBTA_LDM_DW.is_DBR_CST = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        ApplBTA_LDM_DW.is_DBR_control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        Appl_enter_internal_DBR_control();
      } else if (ApplBTA_LDM_DW.is_DBR_CST == ApplBTA_LDM_IN_CST_OL) {
        /* Inport: '<Root>/V_VDS_velVehSpd_f32' */
        if ((fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) >=
             K_LDM_coDecelCtrlOl2ClLim) && ApplBTA_LDM_DW.V_LDM_stClsLoopEnable)
        {
          ApplBTA_LDM_DW.is_DBR_CST = ApplBTA_LDM_IN_CST_follow;
          V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
          V_LDM_stCtrlMode_en = DecelCtrl;
          V_LDM_coCtrlerPCoeff_f32 = ApplBTA_LDM_DW.V_LDM_coCSTP;
          V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coCSTI;

          /* Delay: '<S1>/Delay' */
          ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE -
            V_LDM_coCtrlerPCoeff_f32 * V_LDM_aCtrlErr_f32;
          ApplBTA_LDM_B.V_LDM_resetCtrler_bl =
            !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
        } else {
          /* Delay: '<S1>/Delay' */
          V_LDM_aCtrlErr_f32 = -ApplBTA_LDM_DW.Delay_DSTATE;
          if (fabsf(ApplBTA_LDM_DW.Delay_DSTATE) <= 0.1) {
            V_LDM_stCtrlMode_en = OLCtrl;
            V_LDM_coCtrlerICoeff_f32 = 0.0F;
            ApplBTA_LDM_B.V_LDM_resetCtrlerVal = 0.0F;
            ApplBTA_LDM_B.V_LDM_resetCtrler_bl =
              !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
          }
        }
      } else if (fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) <=
                 K_LDM_coDecelCtrlCl2OlLim) {
        ApplBTA_LDM_DW.is_DBR_CST = ApplBTA_LDM_IN_CST_OL;

        /* Delay: '<S1>/Delay' */
        ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE;
        ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
        V_LDM_coCtrlerPCoeff_f32 = 0.0F;
        V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coCSTI /
          ApplBTA_LDM_DW.V_LDM_coCSTP;
      } else {
        V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
      }
      break;

     case ApplBTA_LDM_IN_DBR_DecelCtrl:
      /* Inport: '<Root>/V_DBR_stDBRCSTRunbleSts_en' */
      if ((ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en != dynamic_control) &&
          (ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en !=
           CST_standby_dynamic_control) &&
          (ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en != CST_emergency_control)) {
        ApplBTA_LDM_DW.is_DBR_DecelCtrl = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        ApplBTA_LDM_DW.is_DBR_control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        Appl_enter_internal_DBR_control();
      } else {
        switch (ApplBTA_LDM_DW.is_DBR_DecelCtrl) {
         case ApplBTA_IN_DecelCtrl_CL_HighSpd:
          /* Inport: '<Root>/V_VDS_velVehSpd_f32' */
          if (fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) <=
              K_LDM_coDecelCtrlHigh2LowLim) {
            ApplBTA_LDM_DW.is_DBR_DecelCtrl = ApplBTA__IN_DecelCtrl_CL_LowSpd;
            V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
            V_LDM_stCtrlMode_en = DecelCtrl;
            V_LDM_coCtrlerPCoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdP;
            V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdI;

            /* Delay: '<S1>/Delay' */
            ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE -
              V_LDM_coCtrlerPCoeff_f32 * V_LDM_aCtrlErr_f32;
            ApplBTA_LDM_B.V_LDM_resetCtrler_bl =
              !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
          } else {
            V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
          }
          break;

         case ApplBTA__IN_DecelCtrl_CL_LowSpd:
          /* Inport: '<Root>/V_VDS_velVehSpd_f32' */
          if (fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) <=
              K_LDM_coDecelCtrlCl2OlLim) {
            ApplBTA_LDM_DW.is_DBR_DecelCtrl = ApplBTA_LDM_IN_DecelCtrl_OL;
            V_LDM_coCtrlerPCoeff_f32 = 0.0F;
            V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdI /
              ApplBTA_LDM_DW.V_LDM_coLowSpdP;

            /* Delay: '<S1>/Delay' */
            ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE;
            ApplBTA_LDM_B.V_LDM_resetCtrler_bl =
              !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
          } else if (fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) >
                     K_LDM_coDecelCtrlLow2HighLim) {
            ApplBTA_LDM_DW.is_DBR_DecelCtrl = ApplBTA_IN_DecelCtrl_CL_HighSpd;
            V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
            V_LDM_stCtrlMode_en = DecelCtrl;
            V_LDM_coCtrlerPCoeff_f32 = ApplBTA_LDM_DW.V_LDM_coHighSpdP;
            V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coHighSpdI;

            /* Delay: '<S1>/Delay' */
            ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE -
              V_LDM_coCtrlerPCoeff_f32 * V_LDM_aCtrlErr_f32;
            ApplBTA_LDM_B.V_LDM_resetCtrler_bl =
              !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
          } else {
            V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
          }
          break;

         default:
          /* Inport: '<Root>/V_VDS_velVehSpd_f32' */
          if ((fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) >
               K_LDM_coDecelCtrlOl2ClLim) &&
              ApplBTA_LDM_DW.V_LDM_stClsLoopEnable) {
            ApplBTA_LDM_DW.is_DBR_DecelCtrl = ApplBTA__IN_DecelCtrl_CL_LowSpd;
            V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
            V_LDM_stCtrlMode_en = DecelCtrl;
            V_LDM_coCtrlerPCoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdP;
            V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdI;

            /* Delay: '<S1>/Delay' */
            ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE -
              V_LDM_coCtrlerPCoeff_f32 * V_LDM_aCtrlErr_f32;
            ApplBTA_LDM_B.V_LDM_resetCtrler_bl =
              !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
          } else {
            /* Delay: '<S1>/Delay' */
            V_LDM_aCtrlErr_f32 = -ApplBTA_LDM_DW.Delay_DSTATE;
            if (fabsf(ApplBTA_LDM_DW.Delay_DSTATE) <= 0.1) {
              V_LDM_stCtrlMode_en = OLCtrl;
              V_LDM_coCtrlerICoeff_f32 = 0.0F;
              ApplBTA_LDM_B.V_LDM_resetCtrlerVal = 0.0F;
              ApplBTA_LDM_B.V_LDM_resetCtrler_bl =
                !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
            }
          }
          break;
        }
      }
      break;

     case ApplBTA_LDM_IN_HoldPressure:
      /* Inport: '<Root>/V_DBR_stDBRCSTRunbleSts_en' */
      if ((ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en != CST_off) &&
          (ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en !=
           CST_standby_standstill_control) &&
          (ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en != standstill_control)) {
        ApplBTA_LDM_DW.is_DBR_control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        Appl_enter_internal_DBR_control();
      }
      break;

     default:
      /* Inport: '<Root>/V_DBR_stDBRCSTRunbleSts_en' */
      if (ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en != initial) {
        ApplBTA_LDM_DW.is_DBR_control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        Appl_enter_internal_DBR_control();
      } else {
        V_LDM_stBrkArbMode_en = DBR_Init;
        V_LDM_stCtrlMode_en = OLCtrl;
      }
      break;
    }
    break;
  }

  /* End of Inport: '<Root>/V_DBR_EBR_stBrkArbMode_en' */
}

/* Function for Chart: '<S1>/LDM_Arbitrator' */
static void ApplBTA_LDM_EBR_control(void)
{
  /* Inport: '<Root>/V_DBR_EBR_stBrkArbMode_en' */
  switch (ApplBTA_LDM_U.V_DBR_EBR_stBrkArbMode_en) {
   case brake_no_request:
    ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
    ApplBTA_LDM_DW.is_EBR_DecelCtrl = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
    ApplBTA_LDM_DW.is_SelfBrake = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
    ApplBTA_LDM_DW.is_EBR_control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
    ApplBTA_LDM_DW.is_Decel_Control = ApplBTA_LDM_IN_Standby;
    V_LDM_stBrkSrcMode_en = BTA_PEDAL_BRAKE_NONE;
    V_LDM_aCtrlerSetpoint_f32 = 0.0F;
    V_LDM_coCtrlerPCoeff_f32 = 0.0F;
    V_LDM_coCtrlerICoeff_f32 = 0.0F;
    V_LDM_aCtrlErr_f32 = 0.0F;
    V_LDM_stBrkArbMode_en = Standby;
    ApplBTA_LDM_B.V_LDM_resetCtrlerVal = 0.0F;
    ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
    break;

   case DBR_arbitration:
    ApplBTA_LDM_DW.is_EBR_DecelCtrl = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
    ApplBTA_LDM_DW.is_SelfBrake = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
    ApplBTA_LDM_DW.is_EBR_control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
    ApplBTA_LDM_DW.is_Decel_Control = ApplBTA_LDM_IN_DBR_control;
    V_LDM_stBrkSrcMode_en = BTA_PEDAL_APPLIED;

    /* Inport: '<Root>/V_DBR_aDBRDecelReq_f32' */
    V_LDM_aCtrlerSetpoint_f32 = ApplBTA_LDM_U.V_DBR_aDBRDecelReq_f32;
    Appl_enter_internal_DBR_control();
    break;

   default:
    V_LDM_stBrkSrcMode_en = BTA_EXTERNAL_BRAKE;

    /* Inport: '<Root>/V_EBR_aCHACCDecelReq_f32' */
    V_LDM_aCtrlerSetpoint_f32 = ApplBTA_LDM_U.V_EBR_aCHACCDecelReq_f32;
    switch (ApplBTA_LDM_DW.is_EBR_control) {
     case ApplBTA_LDM_IN_EBR_DecelCtrl:
      /* Inport: '<Root>/V_EBR_stCHACCRunbleSts_en' */
      if (ApplBTA_LDM_U.V_EBR_stCHACCRunbleSts_en != ACC_CB) {
        ApplBTA_LDM_DW.is_EBR_DecelCtrl = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        ApplBTA_LDM_DW.is_EBR_control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        Appl_enter_internal_EBR_control();
      } else {
        switch (ApplBTA_LDM_DW.is_EBR_DecelCtrl) {
         case ApplBTA_IN_DecelCtrl_CL_HighSpd:
          /* Inport: '<Root>/V_VDS_velVehSpd_f32' */
          if (fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) <=
              K_LDM_coDecelCtrlHigh2LowLim) {
            ApplBTA_LDM_DW.is_EBR_DecelCtrl = ApplBTA__IN_DecelCtrl_CL_LowSpd;
            V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
            V_LDM_stCtrlMode_en = DecelCtrl;
            V_LDM_coCtrlerPCoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdP;
            V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdI;

            /* Delay: '<S1>/Delay' */
            ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE -
              V_LDM_coCtrlerPCoeff_f32 * V_LDM_aCtrlErr_f32;
            ApplBTA_LDM_B.V_LDM_resetCtrler_bl =
              !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
          } else {
            V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
          }
          break;

         case ApplBTA__IN_DecelCtrl_CL_LowSpd:
          /* Inport: '<Root>/V_VDS_velVehSpd_f32' */
          if (fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) <=
              K_LDM_coDecelCtrlCl2OlLim) {
            ApplBTA_LDM_DW.is_EBR_DecelCtrl = ApplBTA_LDM_IN_DecelCtrl_OL;

            /* Delay: '<S1>/Delay' */
            ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE;
            ApplBTA_LDM_B.V_LDM_resetCtrler_bl =
              !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
            V_LDM_coCtrlerPCoeff_f32 = 0.0F;
            V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdI /
              ApplBTA_LDM_DW.V_LDM_coLowSpdP;
          } else if (fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) >
                     K_LDM_coDecelCtrlLow2HighLim) {
            ApplBTA_LDM_DW.is_EBR_DecelCtrl = ApplBTA_IN_DecelCtrl_CL_HighSpd;
            V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
            V_LDM_stCtrlMode_en = DecelCtrl;
            V_LDM_coCtrlerPCoeff_f32 = ApplBTA_LDM_DW.V_LDM_coHighSpdP;
            V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coHighSpdI;

            /* Delay: '<S1>/Delay' */
            ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE -
              V_LDM_coCtrlerPCoeff_f32 * V_LDM_aCtrlErr_f32;
            ApplBTA_LDM_B.V_LDM_resetCtrler_bl =
              !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
          } else {
            V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
          }
          break;

         default:
          /* Inport: '<Root>/V_VDS_velVehSpd_f32' */
          if ((fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) >
               K_LDM_coDecelCtrlOl2ClLim) && K_LDM_blClsLoopCtrlEnable_bl) {
            ApplBTA_LDM_DW.is_EBR_DecelCtrl = ApplBTA__IN_DecelCtrl_CL_LowSpd;
            V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
            V_LDM_stCtrlMode_en = DecelCtrl;
            V_LDM_coCtrlerPCoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdP;
            V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coLowSpdI;

            /* Delay: '<S1>/Delay' */
            ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE -
              V_LDM_coCtrlerPCoeff_f32 * V_LDM_aCtrlErr_f32;
            ApplBTA_LDM_B.V_LDM_resetCtrler_bl =
              !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
          } else {
            /* Delay: '<S1>/Delay' */
            V_LDM_aCtrlErr_f32 = -ApplBTA_LDM_DW.Delay_DSTATE;
            if (fabsf(ApplBTA_LDM_DW.Delay_DSTATE) <= 0.1) {
              V_LDM_stCtrlMode_en = OLCtrl;
              V_LDM_coCtrlerICoeff_f32 = 0.0F;
              ApplBTA_LDM_B.V_LDM_resetCtrlerVal = 0.0F;
              ApplBTA_LDM_B.V_LDM_resetCtrler_bl =
                !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
            }
          }
          break;
        }
      }
      break;

     case ApplBTA_LDM_IN_EBR_Standby:
      /* Inport: '<Root>/V_EBR_stCHACCRunbleSts_en' */
      if (ApplBTA_LDM_U.V_EBR_stCHACCRunbleSts_en != ACC_standby) {
        ApplBTA_LDM_DW.is_EBR_control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        Appl_enter_internal_EBR_control();
      } else {
        V_LDM_stBrkArbMode_en = EBR_Standby;
        V_LDM_stCtrlMode_en = OLCtrl;
        V_LDM_aCtrlerSetpoint_f32 = 0.0F;
        V_LDM_coCtrlerPCoeff_f32 = 0.0F;
        V_LDM_coCtrlerICoeff_f32 = 0.0F;
        V_LDM_aCtrlErr_f32 = 0.0F;
        ApplBTA_LDM_B.V_LDM_resetCtrlerVal = 0.0F;
        ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
      }
      break;

     case ApplBTA_LDM_IN_HoldPressure:
      /* Inport: '<Root>/V_EBR_stCHACCRunbleSts_en' */
      if (ApplBTA_LDM_U.V_EBR_stCHACCRunbleSts_en != ACC_HOLD) {
        ApplBTA_LDM_DW.is_EBR_control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        Appl_enter_internal_EBR_control();
      }
      break;

     default:
      /* Inport: '<Root>/V_EBR_stCHACCRunbleSts_en' incorporates:
       *  Inport: '<Root>/V_VDS_velVehSpd_f32'
       */
      if (ApplBTA_LDM_U.V_EBR_stCHACCRunbleSts_en != ACC_SB) {
        ApplBTA_LDM_DW.is_SelfBrake = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        ApplBTA_LDM_DW.is_EBR_control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        Appl_enter_internal_EBR_control();
      } else if (ApplBTA_LDM_DW.is_SelfBrake == ApplBTA_LDM_IN_SelfBrake_OL) {
        /* Inport: '<Root>/V_VDS_velVehSpd_f32' */
        if ((fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) >
             K_LDM_coDecelCtrlOl2ClLim) && K_LDM_blClsLoopCtrlEnable_bl) {
          ApplBTA_LDM_DW.is_SelfBrake = ApplBTA_LDM_IN_SelfBrake_follow;
          V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
          V_LDM_stCtrlMode_en = DecelCtrl;
          V_LDM_coCtrlerPCoeff_f32 = ApplBTA_LDM_DW.V_LDM_coEbrSlfBrkP;
          V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coEbrSlfBrkI;

          /* Delay: '<S1>/Delay' */
          ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE -
            V_LDM_coCtrlerPCoeff_f32 * V_LDM_aCtrlErr_f32;
          ApplBTA_LDM_B.V_LDM_resetCtrler_bl =
            !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
        } else {
          /* Delay: '<S1>/Delay' */
          V_LDM_aCtrlErr_f32 = -ApplBTA_LDM_DW.Delay_DSTATE;
          if (fabsf(ApplBTA_LDM_DW.Delay_DSTATE) <= 0.1) {
            V_LDM_stCtrlMode_en = OLCtrl;
            V_LDM_coCtrlerICoeff_f32 = 0.0F;
            ApplBTA_LDM_B.V_LDM_resetCtrlerVal = 0.0F;
            ApplBTA_LDM_B.V_LDM_resetCtrler_bl =
              !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
          }
        }
      } else if (fabsf(ApplBTA_LDM_U.V_VDS_velVehSpd_f32) <=
                 K_LDM_coDecelCtrlCl2OlLim) {
        ApplBTA_LDM_DW.is_SelfBrake = ApplBTA_LDM_IN_SelfBrake_OL;

        /* Delay: '<S1>/Delay' */
        ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE;
        ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
        V_LDM_coCtrlerPCoeff_f32 = 0.0F;
        V_LDM_coCtrlerICoeff_f32 = ApplBTA_LDM_DW.V_LDM_coEbrSlfBrkI /
          ApplBTA_LDM_DW.V_LDM_coEbrSlfBrkP;
      } else {
        V_LDM_aCtrlErr_f32 = ApplBTA_LDM_DW.V_LDM_aVehAccErr;
      }
      break;
    }
    break;
  }

  /* End of Inport: '<Root>/V_DBR_EBR_stBrkArbMode_en' */
}

/* Model step function */
void ApplBTA_LDM_step(void)
{
  real32_T rtb_uDLookupTable1;
  LDMVehFwBw_en_t V_LDM_stVehFwBw_en;
  int32_T tmp;

  /* Chart: '<S1>/VehOritArb' incorporates:
   *  Inport: '<Root>/V_DBR_stTrShftLvrPos_en'
   *  Inport: '<Root>/V_DBR_vldTrShftLvrPosVD_bl'
   */
  if (ApplBTA_LDM_DW.is_active_c11_LDM_Controller == 0U) {
    ApplBTA_LDM_DW.is_active_c11_LDM_Controller = 1U;
    if (!ApplBTA_LDM_U.V_DBR_vldTrShftLvrPosVD_bl) {
      ApplBTA_LDM_DW.is_c11_LDM_Controller = ApplBTA_LDM_IN_Normal;
      ApplBTA_L_enter_internal_Normal(&V_LDM_stVehFwBw_en);
    } else {
      ApplBTA_LDM_DW.is_c11_LDM_Controller = ApplBTA_LDM_IN_Error;
      V_LDM_stVehFwBw_en = Error;
    }
  } else if (ApplBTA_LDM_DW.is_c11_LDM_Controller == ApplBTA_LDM_IN_Error) {
    if (!ApplBTA_LDM_U.V_DBR_vldTrShftLvrPosVD_bl) {
      ApplBTA_LDM_DW.is_c11_LDM_Controller = ApplBTA_LDM_IN_Normal;
      ApplBTA_L_enter_internal_Normal(&V_LDM_stVehFwBw_en);
    } else {
      V_LDM_stVehFwBw_en = Error;
    }
  } else if (ApplBTA_LDM_U.V_DBR_vldTrShftLvrPosVD_bl) {
    ApplBTA_LDM_DW.is_Normal = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
    ApplBTA_LDM_DW.is_c11_LDM_Controller = ApplBTA_LDM_IN_Error;
    V_LDM_stVehFwBw_en = Error;
  } else {
    switch (ApplBTA_LDM_DW.is_Normal) {
     case ApplBTA_LDM_IN_Backward:
      if (ApplBTA_LDM_U.V_DBR_stTrShftLvrPos_en != ReverseRange) {
        ApplBTA_LDM_DW.is_Normal = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        ApplBTA_L_enter_internal_Normal(&V_LDM_stVehFwBw_en);
      } else {
        V_LDM_stVehFwBw_en = Backward;
      }
      break;

     case ApplBTA_LDM_IN_Forward:
      tmp = ApplBTA_LDM_U.V_DBR_stTrShftLvrPos_en;
      if ((tmp < 4) || (tmp > 11)) {
        ApplBTA_LDM_DW.is_Normal = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        ApplBTA_L_enter_internal_Normal(&V_LDM_stVehFwBw_en);
      } else {
        V_LDM_stVehFwBw_en = Forward;
      }
      break;

     case ApplBTA_LDM_IN_Null:
      if ((ApplBTA_LDM_U.V_DBR_stTrShftLvrPos_en != BetweenRange) &&
          (ApplBTA_LDM_U.V_DBR_stTrShftLvrPos_en != NeutralRange) &&
          (ApplBTA_LDM_U.V_DBR_stTrShftLvrPos_en != Unknown)) {
        ApplBTA_LDM_DW.is_Normal = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        ApplBTA_L_enter_internal_Normal(&V_LDM_stVehFwBw_en);
      } else {
        V_LDM_stVehFwBw_en = Null;
      }
      break;

     default:
      if (ApplBTA_LDM_U.V_DBR_stTrShftLvrPos_en != ParkRange) {
        ApplBTA_LDM_DW.is_Normal = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
        ApplBTA_L_enter_internal_Normal(&V_LDM_stVehFwBw_en);
      } else {
        V_LDM_stVehFwBw_en = Park;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/VehOritArb' */

  /* Chart: '<S1>/LDM_Arbitrator' incorporates:
   *  Delay: '<S1>/Delay'
   *  Inport: '<Root>/V_DBR_EBR_stBrkArbMode_en'
   *  Inport: '<Root>/V_DBR_aDBRDecelReq_f32'
   *  Inport: '<Root>/V_EBR_aCHACCDecelReq_f32'
   *  Inport: '<Root>/V_EBR_stCHACCRunbleSts_en'
   *  Inport: '<Root>/V_VDS_aVehAccLong_f32'
   */
  if (ApplBTA_LDM_DW.is_active_c10_LDM_Controller == 0U) {
    ApplBTA_LDM_DW.is_active_c10_LDM_Controller = 1U;
    ApplBTA_LDM_B.V_LDM_resetCtrler_bl = false;
    ApplBTA_LDM_DW.V_LDM_coHighSpdP = K_LDM_coDecelParalCtrlHighSpd_P;
    ApplBTA_LDM_DW.V_LDM_coHighSpdI = K_LDM_coDecelParalCtrlHighSpd_I;
    ApplBTA_LDM_DW.V_LDM_coLowSpdP = K_LDM_coDecelParalCtrlLowSpd_P;
    ApplBTA_LDM_DW.V_LDM_coLowSpdI = K_LDM_coDecelParalCtrlLowSpd_I;
    ApplBTA_LDM_DW.V_LDM_coCSTP = K_LDM_coDecelParalCtrlCST_P;
    ApplBTA_LDM_DW.V_LDM_coCSTI = K_LDM_coDecelParalCtrlCST_I;
    ApplBTA_LDM_DW.V_LDM_coEbrSlfBrkP = K_LDM_coDecelParalCtrlEbrSB_P;
    ApplBTA_LDM_DW.V_LDM_coEbrSlfBrkI = K_LDM_coDecelParalCtrlEbrSB_I;
    switch (ApplBTA_LDM_U.V_DBR_EBR_stBrkArbMode_en) {
     case DBR_arbitration:
      ApplBTA_LDM_DW.is_Decel_Control = ApplBTA_LDM_IN_DBR_control;
      V_LDM_stBrkSrcMode_en = BTA_PEDAL_APPLIED;
      V_LDM_aCtrlerSetpoint_f32 = ApplBTA_LDM_U.V_DBR_aDBRDecelReq_f32;
      Appl_enter_internal_DBR_control();
      break;

     case ACC_arbitration:
      ApplBTA_LDM_DW.is_Decel_Control = ApplBTA_LDM_IN_EBR_control;
      V_LDM_stBrkSrcMode_en = BTA_EXTERNAL_BRAKE;
      V_LDM_aCtrlerSetpoint_f32 = ApplBTA_LDM_U.V_EBR_aCHACCDecelReq_f32;
      Appl_enter_internal_EBR_control();
      break;

     default:
      ApplBTA_LDM_DW.is_Decel_Control = ApplBTA_LDM_IN_Standby;
      V_LDM_stBrkSrcMode_en = BTA_PEDAL_BRAKE_NONE;
      V_LDM_aCtrlerSetpoint_f32 = 0.0F;
      V_LDM_coCtrlerPCoeff_f32 = 0.0F;
      V_LDM_coCtrlerICoeff_f32 = 0.0F;
      V_LDM_aCtrlErr_f32 = 0.0F;
      V_LDM_stBrkArbMode_en = Standby;
      ApplBTA_LDM_B.V_LDM_resetCtrlerVal = 0.0F;
      ApplBTA_LDM_B.V_LDM_resetCtrler_bl = !ApplBTA_LDM_B.V_LDM_resetCtrler_bl;
      break;
    }
  } else {
    ApplBTA_LDM_DW.V_LDM_stClsLoopEnable = (K_LDM_blClsLoopCtrlEnable_bl &&
      ((V_LDM_stVehFwBw_en == Forward) || (V_LDM_stVehFwBw_en == Backward)));
    switch (V_LDM_stVehFwBw_en) {
     case Forward:
      ApplBTA_LDM_B.V_LDM_aVehAccDecLong = -ApplBTA_LDM_U.V_VDS_aVehAccLong_f32;
      break;

     case Backward:
      ApplBTA_LDM_B.V_LDM_aVehAccDecLong = ApplBTA_LDM_U.V_VDS_aVehAccLong_f32;
      break;

     default:
      ApplBTA_LDM_B.V_LDM_aVehAccDecLong = ApplBTA_LDM_U.V_VDS_aVehAccLong_f32;
      break;
    }

    ApplBTA_LDM_DW.V_LDM_aVehAccErr = V_LDM_aCtrlerSetpoint_f32 -
      ApplBTA_LDM_B.V_LDM_aVehAccDecLong;
    switch (ApplBTA_LDM_DW.is_Decel_Control) {
     case ApplBTA_LDM_IN_DBR_control:
      ApplBTA_LDM_DBR_control();
      break;

     case ApplBTA_LDM_IN_EBR_control:
      ApplBTA_LDM_EBR_control();
      break;

     default:
      if (ApplBTA_LDM_U.V_DBR_EBR_stBrkArbMode_en == DBR_arbitration) {
        ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE;
        ApplBTA_LDM_DW.is_Decel_Control = ApplBTA_LDM_IN_DBR_control;
        V_LDM_stBrkSrcMode_en = BTA_PEDAL_APPLIED;
        V_LDM_aCtrlerSetpoint_f32 = ApplBTA_LDM_U.V_DBR_aDBRDecelReq_f32;
        Appl_enter_internal_DBR_control();
      } else if ((ApplBTA_LDM_U.V_DBR_EBR_stBrkArbMode_en == ACC_arbitration) &&
                 (ApplBTA_LDM_U.V_EBR_stCHACCRunbleSts_en != ACC_off)) {
        ApplBTA_LDM_B.V_LDM_resetCtrlerVal = ApplBTA_LDM_DW.Delay_DSTATE;
        ApplBTA_LDM_DW.is_Decel_Control = ApplBTA_LDM_IN_EBR_control;
        V_LDM_stBrkSrcMode_en = BTA_EXTERNAL_BRAKE;
        V_LDM_aCtrlerSetpoint_f32 = ApplBTA_LDM_U.V_EBR_aCHACCDecelReq_f32;
        Appl_enter_internal_EBR_control();
      } else {
        V_LDM_stBrkSrcMode_en = BTA_PEDAL_BRAKE_NONE;
        V_LDM_aCtrlerSetpoint_f32 = 0.0F;
        V_LDM_coCtrlerPCoeff_f32 = 0.0F;
        V_LDM_coCtrlerICoeff_f32 = 0.0F;
        V_LDM_aCtrlErr_f32 = 0.0F;
        V_LDM_stBrkArbMode_en = Standby;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/LDM_Arbitrator' */

  /* Lookup_n-D: '<S5>/2-D Lookup Table1' */
  rtb_uDLookupTable1 = look1_iflf_binlxpw(V_LDM_aCtrlerSetpoint_f32,
    (&(K10_LDM_aOLCtrlerTableX[0])), (&(K10_LDM_torqOLCtrlerTableY[0])), 9U);

  /* Switch: '<S16>/Switch2' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  RelationalOperator: '<S16>/LowerRelop1'
   *  RelationalOperator: '<S16>/UpperRelop'
   *  Switch: '<S16>/Switch'
   */
  if (rtb_uDLookupTable1 > K_LDM_torqOLCtrlerUpLim) {
    rtb_uDLookupTable1 = K_LDM_torqOLCtrlerUpLim;
  } else {
    if (rtb_uDLookupTable1 < K_LDM_torqOLCtrlerLowLim) {
      /* Switch: '<S16>/Switch' incorporates:
       *  Constant: '<S1>/Constant2'
       */
      rtb_uDLookupTable1 = K_LDM_torqOLCtrlerLowLim;
    }
  }

  /* End of Switch: '<S16>/Switch2' */

  /* Sum: '<S8>/Add' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant2'
   *  Product: '<S8>/Multiply'
   *  Product: '<S8>/Multiply1'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  ApplBTA_LDM_DW.UnitDelay_DSTATE = rtb_uDLookupTable1 * 0.3F + 0.7F *
    ApplBTA_LDM_DW.UnitDelay_DSTATE;

  /* DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
  if (ApplBTA_LDM_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    ApplBTA_LDM_DW.DiscreteTimeIntegrator_DSTATE =
      ApplBTA_LDM_B.V_LDM_resetCtrlerVal;
  }

  if ((ApplBTA_LDM_B.V_LDM_resetCtrler_bl &&
       (ApplBTA_LDM_DW.DiscreteTimeIntegrator_PrevRese <= 0)) ||
      ((!ApplBTA_LDM_B.V_LDM_resetCtrler_bl) &&
       (ApplBTA_LDM_DW.DiscreteTimeIntegrator_PrevRese == 1))) {
    ApplBTA_LDM_DW.DiscreteTimeIntegrator_DSTATE =
      ApplBTA_LDM_B.V_LDM_resetCtrlerVal;
  }

  /* Sum: '<S13>/Add' incorporates:
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator'
   *  Product: '<S13>/Product'
   */
  rtb_uDLookupTable1 = V_LDM_aCtrlErr_f32 * V_LDM_coCtrlerPCoeff_f32 +
    ApplBTA_LDM_DW.DiscreteTimeIntegrator_DSTATE;

  /* Switch: '<S15>/Switch2' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Constant7'
   *  Delay: '<S1>/Delay'
   *  RelationalOperator: '<S15>/LowerRelop1'
   *  RelationalOperator: '<S15>/UpperRelop'
   *  Switch: '<S15>/Switch'
   */
  if (rtb_uDLookupTable1 > K_LDM_torqDecelClsCtrlerUpLim) {
    ApplBTA_LDM_DW.Delay_DSTATE = K_LDM_torqDecelClsCtrlerUpLim;
  } else if (rtb_uDLookupTable1 < K_LDM_torqDecelClsCtrlerLowLim) {
    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S1>/Constant7'
     *  Delay: '<S1>/Delay'
     */
    ApplBTA_LDM_DW.Delay_DSTATE = K_LDM_torqDecelClsCtrlerLowLim;
  } else {
    ApplBTA_LDM_DW.Delay_DSTATE = rtb_uDLookupTable1;
  }

  /* End of Switch: '<S15>/Switch2' */

  /* Sum: '<S1>/Add' incorporates:
   *  Delay: '<S1>/Delay'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  V_LDM_torqDecelCtrlerOut_f32 = ApplBTA_LDM_DW.UnitDelay_DSTATE +
    ApplBTA_LDM_DW.Delay_DSTATE;

  /* Switch: '<S10>/Switch2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant9'
   *  RelationalOperator: '<S10>/LowerRelop1'
   *  RelationalOperator: '<S10>/UpperRelop'
   *  Switch: '<S10>/Switch'
   */
  if (V_LDM_torqDecelCtrlerOut_f32 > K_LDM_torqDecelCtrlerUpLim) {
    V_LDM_torqDecelCtrlerOut_f32 = K_LDM_torqDecelCtrlerUpLim;
  } else {
    if (V_LDM_torqDecelCtrlerOut_f32 < K_LDM_torqDecelCtrlerLowLim) {
      /* Switch: '<S10>/Switch' incorporates:
       *  Constant: '<S1>/Constant1'
       */
      V_LDM_torqDecelCtrlerOut_f32 = K_LDM_torqDecelCtrlerLowLim;
    }
  }

  /* End of Switch: '<S10>/Switch2' */

  /* Abs: '<S1>/Abs' incorporates:
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  ApplBTA_LDM_DW.UnitDelay3_DSTATE = fabsf(ApplBTA_LDM_DW.UnitDelay3_DSTATE);

  /* Product: '<S13>/Product1' incorporates:
   *  Constant: '<S3>/Constant'
   *  Logic: '<S1>/AND'
   *  Logic: '<S1>/NOT'
   *  RelationalOperator: '<S1>/Relational Operator'
   *  RelationalOperator: '<S3>/Compare'
   *  Sum: '<S1>/Minus'
   *  UnitDelay: '<S1>/Unit Delay1'
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  ApplBTA_LDM_DW.UnitDelay3_DSTATE = (real32_T)((!(V_LDM_aCtrlerSetpoint_f32 -
    ApplBTA_LDM_B.V_LDM_aVehAccDecLong <= 0.0F)) ||
    (!(ApplBTA_LDM_DW.UnitDelay3_DSTATE >= ApplBTA_LDM_DW.UnitDelay1_DSTATE))) *
    (V_LDM_aCtrlErr_f32 * V_LDM_coCtrlerICoeff_f32);

  /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S1>/Delay'
   *  Gain: '<S14>/Gain'
   *  Sum: '<S14>/Minus'
   *  Sum: '<S14>/Minus1'
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  ApplBTA_LDM_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
  ApplBTA_LDM_DW.DiscreteTimeIntegrator_DSTATE += ((ApplBTA_LDM_DW.Delay_DSTATE
    - rtb_uDLookupTable1) * 3.0F + ApplBTA_LDM_DW.UnitDelay3_DSTATE) * 0.002F;
  ApplBTA_LDM_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    ApplBTA_LDM_B.V_LDM_resetCtrler_bl;

  /* Update for UnitDelay: '<S1>/Unit Delay3' incorporates:
   *  Delay: '<S1>/Delay'
   */
  ApplBTA_LDM_DW.UnitDelay3_DSTATE = ApplBTA_LDM_DW.Delay_DSTATE;

  /* Update for UnitDelay: '<S1>/Unit Delay1' incorporates:
   *  UnitDelay: '<S8>/Unit Delay'
   */
  ApplBTA_LDM_DW.UnitDelay1_DSTATE = ApplBTA_LDM_DW.UnitDelay_DSTATE;
}

/* Model initialize function */
void ApplBTA_LDM_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(ApplBTA_LDM_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &ApplBTA_LDM_B), 0,
                sizeof(B_ApplBTA_LDM_T));

  /* custom signals */
  V_LDM_torqDecelCtrlerOut_f32 = 0.0F;
  V_LDM_aCtrlErr_f32 = 0.0F;
  V_LDM_coCtrlerPCoeff_f32 = 0.0F;
  V_LDM_coCtrlerICoeff_f32 = 0.0F;
  V_LDM_aCtrlerSetpoint_f32 = 0.0F;
  V_LDM_stBrkSrcMode_en = BTA_EXTERNAL_BRAKE;
  V_LDM_stCtrlMode_en = DecelCtrl;
  V_LDM_stBrkArbMode_en = Standby;

  /* states (dwork) */
  (void) memset((void *)&ApplBTA_LDM_DW, 0,
                sizeof(DW_ApplBTA_LDM_T));

  /* external inputs */
  (void)memset(&ApplBTA_LDM_U, 0, sizeof(ExtU_ApplBTA_LDM_T));
  ApplBTA_LDM_U.V_DBR_EBR_stBrkArbMode_en = brake_no_request;
  ApplBTA_LDM_U.V_DBR_stTrShftLvrPos_en = BetweenRange;
  ApplBTA_LDM_U.V_DBR_stDBRCSTRunbleSts_en = initial;
  ApplBTA_LDM_U.V_EBR_stCHACCRunbleSts_en = ACC_off;

  /* ConstCode for Constant: '<S1>/Constant' */
  V_LDM_vldDecelCtrlerOutVD_bl = VALID;

  /* InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
  ApplBTA_LDM_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
  ApplBTA_LDM_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* SystemInitialize for Chart: '<S1>/VehOritArb' */
  ApplBTA_LDM_DW.is_Normal = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
  ApplBTA_LDM_DW.is_active_c11_LDM_Controller = 0U;
  ApplBTA_LDM_DW.is_c11_LDM_Controller = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S1>/LDM_Arbitrator' */
  ApplBTA_LDM_DW.is_Decel_Control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
  ApplBTA_LDM_DW.is_DBR_control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
  ApplBTA_LDM_DW.is_DBR_CST = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
  ApplBTA_LDM_DW.is_DBR_DecelCtrl = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
  ApplBTA_LDM_DW.is_EBR_control = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
  ApplBTA_LDM_DW.is_EBR_DecelCtrl = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
  ApplBTA_LDM_DW.is_SelfBrake = ApplBTA_LDM_IN_NO_ACTIVE_CHILD;
  ApplBTA_LDM_DW.is_active_c10_LDM_Controller = 0U;
}

/* Model terminate function */
void ApplBTA_LDM_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
