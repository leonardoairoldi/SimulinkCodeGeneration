/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'CircuitInterface/Model/Solver Configuration'.
 */

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "nesl_rtw.h"
#include "CircuitInterface_dcd86948_1.h"
#include "CircuitInterface_dcd86948_1_gateway.h"

void CircuitInterface_dcd86948_1_gateway(void)
{
  NeModelParameters modelparams = { (NeSolverType) 2, 0.001, 0.001, 0.001, 0, 0,
    (NeModifyAbsTol) 0, 0.001, 0, 0, 0, 0, (SscLoggingSetting) 0, 636217375, 1,
    0, 0, };

  NeSolverParameters solverparams = { 0, 0, 1, 0, 0, 0.001, 0.001, 1e-09, 0, 0,
    100, 0, 1, (NeConsistencySolver) 2, (NeIndexReductionMethod) 1, 0, 1e-09,
    (NeToleranceSource) 1, 0.001, 0.001, 0.001, 1, (NeLocalSolverChoice) 0, 1, 1,
    0.005, 1, 3, 2, 0, 2, (NeLinearAlgebraChoice) 0, 0,
    (NeEquationFormulationChoice) 0, 1024, 1, 0.001, (NePartitionStorageMethod)
    0, 1024, (NePartitionMethod) 0, 0, (NeMultibodyLocalSolverChoice) 0, 0.001,
  };

  const NeOutputParameters* outputparameters = NULL;
  NeDae* dae;
  size_t numOutputs = 0;
  int rtpDaes[1] = { 0 };

  int* rtwLogDaes = NULL;
  int* solverHitDaes = NULL;

  {
    static const NeOutputParameters outputparameters_init[] = { { 0, 0, }, };

    outputparameters = outputparameters_init;
    numOutputs = sizeof(outputparameters_init)/sizeof(outputparameters_init[0]);
  }

  CircuitInterface_dcd86948_1_dae(&dae,
    &modelparams,
    &solverparams);
  nesl_register_simulator_group("CircuitInterface/Model/Solver Configuration_1",
    1,
    &dae,
    &solverparams,
    &modelparams,
    numOutputs,
    outputparameters,
    1,
    rtpDaes,
    0,
    rtwLogDaes,
    0,
    solverHitDaes);
}
