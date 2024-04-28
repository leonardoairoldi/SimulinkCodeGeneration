/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'CircuitInterface/Model/Solver Configuration'.
 */

#include "ne_ds.h"
#include "CircuitInterface_dcd86948_1_ds_sys_struct.h"
#include "CircuitInterface_dcd86948_1_ds_obs_act.h"
#include "CircuitInterface_dcd86948_1_ds.h"
#include "CircuitInterface_dcd86948_1_ds_externals.h"
#include "CircuitInterface_dcd86948_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T CircuitInterface_dcd86948_1_ds_obs_act(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t4, NeDsMethodOutput *t5)
{
  PmRealVector out;
  real_T Model_C_p_v;
  real_T Model_Current_Sensor_I;
  real_T Model_R2_i;
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_1;
  real_T X_idx_2;
  U_idx_0 = t4->mU.mX[0];
  X_idx_0 = t4->mX.mX[0];
  X_idx_1 = t4->mX.mX[1];
  X_idx_2 = t4->mX.mX[2];
  out = t5->mOBS_ACT;
  Model_C_p_v = X_idx_1 * 1.0E-6 + X_idx_0;
  Model_Current_Sensor_I = X_idx_0 * 0.001 + X_idx_1 * 1.000000001;
  Model_R2_i = X_idx_0 * 0.001 + X_idx_1 * 1.0E-9;
  out.mX[0] = X_idx_1;
  out.mX[1] = 0.0;
  out.mX[2] = Model_C_p_v;
  out.mX[3] = Model_C_p_v;
  out.mX[4] = X_idx_0;
  out.mX[5] = Model_Current_Sensor_I;
  out.mX[6] = Model_Current_Sensor_I;
  out.mX[7] = 5.0;
  out.mX[8] = 5.0;
  out.mX[9] = Model_Current_Sensor_I;
  out.mX[10] = 0.0;
  out.mX[11] = 0.0;
  out.mX[12] = 0.0;
  out.mX[13] = 0.0;
  out.mX[14] = 0.0;
  out.mX[15] = Model_Current_Sensor_I;
  out.mX[16] = Model_C_p_v;
  out.mX[17] = -X_idx_2 + 5.0;
  out.mX[18] = Model_Current_Sensor_I * 1000.0;
  out.mX[19] = Model_R2_i;
  out.mX[20] = 0.0;
  out.mX[21] = Model_C_p_v;
  out.mX[22] = Model_R2_i * 1000.0;
  out.mX[23] = Model_Current_Sensor_I;
  out.mX[24] = -X_idx_2 + 5.0;
  out.mX[25] = 5.0;
  out.mX[26] = Model_Current_Sensor_I * X_idx_2 * 0.001 * 1000.0;
  out.mX[27] = X_idx_2;
  out.mX[28] = U_idx_0;
  out.mX[29] = U_idx_0;
  out.mX[30] = Model_C_p_v;
  out.mX[31] = 0.0;
  out.mX[32] = Model_C_p_v;
  out.mX[33] = -X_idx_2 + 5.0;
  out.mX[34] = 0.0;
  out.mX[35] = -X_idx_2 + 5.0;
  out.mX[36] = -X_idx_2 + 5.0;
  out.mX[37] = Model_C_p_v;
  out.mX[38] = -Model_Current_Sensor_I;
  out.mX[39] = 0.0;
  out.mX[40] = 5.0;
  out.mX[41] = 5.0;
  (void)sys;
  (void)t5;
  return 0;
}
