/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'CircuitInterface/Model/Solver Configuration'.
 */

#include "ne_ds.h"
#include "CircuitInterface_dcd86948_1_ds_sys_struct.h"
#include "CircuitInterface_dcd86948_1_ds_log.h"
#include "CircuitInterface_dcd86948_1_ds.h"
#include "CircuitInterface_dcd86948_1_ds_externals.h"
#include "CircuitInterface_dcd86948_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T CircuitInterface_dcd86948_1_ds_log(const NeDynamicSystem *sys, const
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
  out = t5->mLOG;
  Model_C_p_v = X_idx_1 * 1.0E-6 + X_idx_0;
  Model_Current_Sensor_I = X_idx_0 * 0.001 + X_idx_1 * 1.000000001;
  Model_R2_i = X_idx_0 * 0.001 + X_idx_1 * 1.0E-9;
  out.mX[0] = X_idx_1;
  out.mX[1] = Model_C_p_v;
  out.mX[2] = Model_C_p_v;
  out.mX[3] = X_idx_0;
  out.mX[4] = X_idx_1 * X_idx_1 * 1.0E-9;
  out.mX[5] = Model_Current_Sensor_I;
  out.mX[6] = Model_Current_Sensor_I;
  out.mX[7] = Model_Current_Sensor_I;
  out.mX[8] = Model_Current_Sensor_I;
  out.mX[9] = Model_C_p_v;
  out.mX[10] = -X_idx_2 + 5.0;
  out.mX[11] = Model_Current_Sensor_I * 1000.0;
  out.mX[12] = Model_Current_Sensor_I * Model_Current_Sensor_I * 1000.0;
  out.mX[13] = Model_R2_i;
  out.mX[14] = Model_C_p_v;
  out.mX[15] = Model_R2_i * 1000.0;
  out.mX[16] = Model_R2_i * Model_R2_i * 1000.0;
  out.mX[17] = Model_Current_Sensor_I;
  out.mX[18] = -X_idx_2 + 5.0;
  out.mX[19] = Model_Current_Sensor_I * X_idx_2 * 0.001 * 1000.0;
  out.mX[20] = X_idx_2;
  out.mX[21] = U_idx_0;
  out.mX[22] = U_idx_0;
  out.mX[23] = Model_C_p_v;
  out.mX[24] = Model_C_p_v;
  out.mX[25] = -X_idx_2 + 5.0;
  out.mX[26] = -X_idx_2 + 5.0;
  out.mX[27] = -X_idx_2 + 5.0;
  out.mX[28] = Model_C_p_v;
  out.mX[29] = -Model_Current_Sensor_I;
  (void)sys;
  (void)t5;
  return 0;
}
