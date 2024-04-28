#ifndef __ne_dae_construct_h__
#define __ne_dae_construct_h__
#include "pm_std.h"
#include "mc_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
const McLinearAlgebraFactory*mc_get_csparse_linear_algebra(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "mc_std.h"
#include "pm_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef enum StateModelInputsModeTag{STATE_MODEL_INPUTS_UNSET= -1,
STATE_MODEL_INPUTS_NOINPUTS,STATE_MODEL_INPUTS_INPUTS,STATE_MODEL_INPUTS_NUM}
StateModelInputsMode;const char*state_model_inputs_mode_to_string(
StateModelInputsMode);StateModelInputsMode to_state_model_inputs_mode(const
char*);typedef enum StateModelModeTag{STATE_MODEL_MODE_UNSET= -1,
STATE_MODEL_MODE_NORMAL,STATE_MODEL_MODE_IMPORTED,STATE_MODEL_MODE_NUM}
StateModelMode;const char*state_model_mode_to_string(StateModelMode);
StateModelMode to_state_model_mode(const char*);typedef struct CStateManagerTag
CStateManager;typedef struct CStateManagerDataTag CStateManagerData;struct
CStateManagerTag{const char*(*mModel)(const CStateManager*);size_t(*mSize)(
const CStateManager*,int);void(*mAllocate)(const CStateManager*);int32_T*(*
mInteger)(const CStateManager*);size_t*(*mIndex)(const CStateManager*);double*
(*mReal)(const CStateManager*);double*(*mRealTarget)(const CStateManager*);
void(*mEliminated)(const CStateManager*,const char*);boolean_T(*mIsEliminated)
(const CStateManager*,const char*);void(*mSatisfied)(const CStateManager*,
const char*,boolean_T);boolean_T(*mIsSatisfied)(const CStateManager*,const char
*);void(*mInputDependent)(const CStateManager*,const char*);boolean_T(*
mIsInputDependent)(const CStateManager*,const char*);void(*mAlgebraic)(const
CStateManager*,const char*);boolean_T(*mIsAlgebraic)(const CStateManager*,
const char*);void(*mErrorAll)(const CStateManager*,boolean_T);void(*mError)(
const CStateManager*,const char*,boolean_T);boolean_T(*mHasError)(const
CStateManager*,const char*);boolean_T(*mIsHideValue)(const CStateManager*,
const char*);void(*mSteadyStateAll)(const CStateManager*);void(*mSteadyState)(
const CStateManager*,const char*);boolean_T(*mIsSteadyState)(const
CStateManager*,const char*);StateModelMode(*mGetModelMode)(const CStateManager
*);void(*mSetModelMode)(const CStateManager*,StateModelMode);
StateModelInputsMode(*mGetModelInputsMode)(const CStateManager*);void(*
mSetModelInputsMode)(const CStateManager*,StateModelInputsMode);int(*
mGetModelModifiedTimeStamp)(const CStateManager*);void(*
mSetModelModifiedTimeStamp)(const CStateManager*,int);const char*(*
mGetModelLastUpdatedDateTime)(const CStateManager*);void(*
mSetModelLastUpdatedDateTime)(const CStateManager*,const char*);void(*mUpdate)
(const CStateManager*);void(*mUpdateMode)(const CStateManager*);void(*
mUpdateViewer)(const CStateManager*);void(*mUpdateTarget)(const CStateManager*
);void(*mUpdateISI)(const CStateManager*,void*);void(*mUpdateModeISI)(const
CStateManager*,void*);void(*mUpdateViewerISI)(const CStateManager*,void*);void
(*mUpdateTargetISI)(const CStateManager*,void*);void(*mApplyISI)(const
CStateManager*,const void*);CStateManager*(*mClone)(const CStateManager*);void
(*mDestroy)(CStateManager*);CStateManagerData*mData;};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_dae_fwd.h"
#include "pm_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef enum SscDiagnosticSettingTag{SSC_DIAGNOSTIC_INVALID= -1,
SSC_DIAGNOSTIC_ERROR,SSC_DIAGNOSTIC_WARNING,SSC_DIAGNOSTIC_NONE,
SSC_DIAGNOSTIC_NUM}SscDiagnosticSetting;typedef enum SscLoggingSettingTag{
SSC_LOGGING_INVALID= -1,SSC_LOGGING_OFF,SSC_LOGGING_ON,SSC_LOGGING_LOCAL,
SSC_LOGGING_NUM}SscLoggingSetting;typedef struct NeModelParametersTag
NeModelParameters;typedef enum NeSolverTypeTag{NE_SOLVER_TYPE_INVALID= -1,
NE_SOLVER_TYPE_DAE,NE_SOLVER_TYPE_ODE,NE_SOLVER_TYPE_DISCRETE,
NE_SOLVER_TYPE_NUM}NeSolverType;typedef enum NeModifyAbsTolTag{
NE_MODIFY_ABS_TOL_INVALID= -1,NE_MODIFY_ABS_TOL_NO,NE_MODIFY_ABS_TOL_YES,
NE_MODIFY_ABS_TOL_MAYBE,NE_MODIFY_ABS_TOL_NUM}NeModifyAbsTol;struct
NeModelParametersTag{NeSolverType mSolverType;real_T mSolverTolerance;real_T
mSolverAbsTol;real_T mSolverRelTol;boolean_T mVariableStepSolver;boolean_T
mIsUsingODEN;NeModifyAbsTol mSolverModifyAbsTol;real_T mFixedStepSize;real_T
mStartTime;boolean_T mLoadInitialState;boolean_T mUseSimState;boolean_T
mLinTrimCompile;SscLoggingSetting mLoggingMode;real_T mRTWModifiedTimeStamp;
boolean_T mZcDisabled;boolean_T mUseModelRefSolver;boolean_T mTargetFPGAHIL;};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_profiler_fwd.h"
#include "pm_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct NeSolverParametersTag NeSolverParameters;typedef enum
NeLocalSolverChoiceTag{NE_INVALID_ADVANCER_CHOICE= -1,
NE_BACKWARD_EULER_ADVANCER,NE_TRAPEZOIDAL_ADVANCER,NE_NDF2_ADVANCER,
NE_VARIABLE_STEP_ADVANCER,NE_PARTITIONING_ADVANCER,NE_NUM_ADVANCER_CHOICES}
NeLocalSolverChoice;typedef enum NeIndexReductionMethodTag{
NE_INVALID_IR_METHOD= -1,NE_NONE_IR,NE_DERIVATIVE_REPLACEMENT_IR,
NE_PROJECTION_IR,NE_NUM_IR_METHOD}NeIndexReductionMethod;typedef enum
NeLinearAlgebraChoiceTag{NE_INVALID_LA_CHOICE= -1,NE_AUTO_LA,NE_SPARSE_LA,
NE_FULL_LA,NE_NUM_LA_CHOICES}NeLinearAlgebraChoice;typedef enum
NeEquationFormulationChoiceTag{NE_INVALID_EF_CHOICE= -1,NE_TIME_EF,
NE_FREQUENCY_TIME_EF,NE_NUM_EF_CHOICES}NeEquationFormulationChoice;typedef enum
NePartitionStorageMethodTag{NE_PARTITIONING_INVALID= -1,
NE_PARTITIONING_AS_NEEDED,NE_PARTITIONING_EXHAUSTIVE,NE_PARTITIONING_NUM}
NePartitionStorageMethod;typedef enum NePartitionMethodTag{
NE_PARTITIONING_METHOD_INVALID= -1,NE_PARTITIONING_METHOD_ROBUST,
NE_PARTITIONING_METHOD_FAST,NE_PARTITIONING_METHOD_ALG_EQS,
NE_PARTITIONING_METHOD_ALL_EQS,NE_PARTITIONING_METHOD_MERGE,
NE_PARTITIONING_METHOD_MULTICORE,NE_PARTITIONING_METHOD_NUM}NePartitionMethod;
typedef enum NeConsistencySolverTag{NE_CONSISTENCY_SOLVER_INVALID= -1,
NE_CS_NEWTON_FTOL,NE_CS_NEWTON_XTOL,NE_CS_NEWTON_XTOL_AFTER_FTOL,
NE_CONSISTENCY_SOLVER_NUM}NeConsistencySolver;typedef enum NeToleranceSourceTag
{NE_TOLERANCE_SOURCE_INVALID= -1,NE_TOLERANCE_SOURCE_LOCAL,
NE_TOLERANCE_SOURCE_GLOBAL,NE_TOLERANCE_SOURCE_NUM}NeToleranceSource;typedef
enum NeMultibodyLocalSolverChoiceTag{NE_MULTIBODY_LOCAL_SOLVER_INVALID= -1,
NE_MULTIBODY_LOCAL_SOLVER_ODE1,NE_MULTIBODY_LOCAL_SOLVER_ODE2,
NE_MULTIBODY_LOCAL_SOLVER_ODE3,NE_MULTIBODY_LOCAL_SOLVER_ODE4,
NE_MULTIBODY_LOCAL_SOLVER_ODE5,NE_MULTIBODY_LOCAL_SOLVER_ODE8,
NE_MULTIBODY_LOCAL_SOLVER_NUM}NeMultibodyLocalSolverChoice;struct
NeSolverParametersTag{boolean_T mProfile;boolean_T mUseLocalSampling;boolean_T
mEnableSwitchedLinearOptims;boolean_T mFrequencyDomain;boolean_T mUseCCode;
real_T mRelTol;real_T mAbsTol;real_T mMinStep;boolean_T mToWorkspace;boolean_T
mRevertToSquareIcSolve;size_t mNumHomotopyIterations;boolean_T mPhasorMode;
size_t mPhasorModeNumHarmonics;NeConsistencySolver mConsistencySolver;
NeIndexReductionMethod mIndexReductionMethod;boolean_T mDoDC;real_T
mResidualTolerance;NeToleranceSource mConsistencyTolSource;real_T
mConsistencyAbsTol;real_T mConsistencyRelTol;real_T mConsistencyTolFactor;
boolean_T mUseLocalSolver;NeLocalSolverChoice mLocalSolverChoice;boolean_T
mResolveIndetEquations;size_t mFunctionEvalNumThread;real_T
mLocalSolverSampleTime;boolean_T mDoFixedCost;size_t mMaxNonlinIter;size_t
mMaxModeIter;boolean_T mComputeImpulses;size_t mImpulseIterations;
NeLinearAlgebraChoice mLinearAlgebra;size_t mLinearAlgebraNumThread;
NeEquationFormulationChoice mEquationFormulation;size_t mDelaysMemoryBudget;
boolean_T mAutomaticFiltering;real_T mFilteringTimeConstant;
NePartitionStorageMethod mPartitionStorageMethod;size_t mPartitionMemoryBudget
;NePartitionMethod mPartitionMethod;boolean_T mMultibodyUseLocalSolver;
NeMultibodyLocalSolverChoice mMultibodyLocalSolverChoice;real_T
mMultibodyLocalSolverSampleTime;};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_ds.h"
#include "pm_std.h"
#include "pm_std.h"
#include "mc_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef enum{MC_SOLVER_STATUS_INVALID= -1,MC_SOLVER_SUCCESS,MC_SOLVER_FAILURE,
MC_SOLVER_SINGULAR_MATRIX,MC_SOLVER_NO_CONVERGENCE,MC_SOLVER_TOLERANCE_UNMET,
MC_SOLVER_LINEAR_INCONSISTENT,MC_SOLVER_STATUS_COUNT}McSolverStatus;typedef
struct McRealFunctionPrivateDataTag McRealFunctionPrivateData;struct
McRealFunctionTag{McRealFunctionPrivateData*mPrivateDataPtr;McSolverStatus(*
mFunctionPtr)(const void*input,const PmRealVector*output,
McRealFunctionPrivateData*data);const void*(*mGetDefaultInput)(const
McRealFunction*function);void(*mDestroy)(McRealFunction*function);};typedef
struct McIntFunctionPrivateDataTag McIntFunctionPrivateData;struct
McIntFunctionTag{McIntFunctionPrivateData*mPrivateDataPtr;void(*mFunctionPtr)(
const void*input,const PmIntVector*output,McIntFunctionPrivateData*data);const
void*(*mGetDefaultInput)(const McIntFunction*function);void(*mDestroy)(
McIntFunction*function);};typedef struct McMatrixFunctionPrivateDataTag
McMatrixFunctionPrivateData;struct McMatrixFunctionTag{
McMatrixFunctionPrivateData*mPrivateDataPtr;const PmSparsityPattern*
mPatternPtr;void(*mFunctionPtr)(const void*input,const PmRealVector*output,
McMatrixFunctionPrivateData*data);const void*(*mGetDefaultInput)(const
McMatrixFunction*function);void(*mDestroy)(McMatrixFunction*function);};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "pm_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct NeParameterBundleTag{PmIntVector mLogicalParameters;PmIntVector
mIntegerParameters;PmIntVector mIndexParameters;PmRealVector mRealParameters;}
NeParameterBundle;typedef struct NeDerivedParameterBundleTag{PmIntVector
mLogicalDerivedParameters;PmIntVector mIntegerDerivedParameters;PmIntVector
mIndexDerivedParameters;PmRealVector mRealDerivedParameters;}
NeDerivedParameterBundle;
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct DDIWrapperPrivateDataTag DDIWrapperPrivateData;typedef struct
DaeDynamicInfoWrapperTag DaeDynamicInfoWrapper;struct DaeDynamicInfoWrapperTag
{DDIWrapperPrivateData*mPrivateData;void(*mReportIC)(const
DaeDynamicInfoWrapper*,const NeSystemInput*,const NeParameterBundle*,const
NeDerivedParameterBundle*,size_t,boolean_T,boolean_T);void(*mReportMode)(const
DaeDynamicInfoWrapper*,const NeSystemInput*,boolean_T,boolean_T,boolean_T,
int16_T);void(*mPushInfo)(const DaeDynamicInfoWrapper*,size_t);void(*
mInitializeState)(DaeDynamicInfoWrapper*,McMatrixFunction*,McMatrixFunction*,
McMatrixFunction*,McMatrixFunction*,McMatrixFunction*,McRealFunction*,
McRealFunction*,size_t,size_t,size_t,size_t);void(*mDestroy)(
DaeDynamicInfoWrapper*);};DaeDynamicInfoWrapper*ddi_wrapper_create(void);
typedef enum{DAEMON_CHOICE_INVALID= -1,DAEMON_CHOICE_NONE,
DAEMON_CHOICE_LOG_NUM_ITERATIONS,DAEMON_CHOICE_SSC2HDL,NUM_DAEMON_CHOICES}
DaemonChoice;typedef struct NeRtpValuesTag NeRtpValues;struct NeRtpValuesTag{
void(*mSetRtpValues)(NeRtpValues*rtpValues,void*ss);void*mData;};NeRtpValues*
make_rtw_rtp_values(NeParameterBundle*pb);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef struct NeConstraintStatTag NeConstraintStat;struct NeConstraintStatTag
{void(*mVariable)(const NeConstraintStat*,const NeVariableData*);struct
NeConstraintStatData*mData;};typedef struct NeCompStatsTag NeCompStats;struct
NeCompStatsTag{const NeConstraintStat*(*mConstraint)(const NeCompStats*);
struct NeCompStatsData*mData;};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "ne_initer_fwd.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
PmfMessageId ne_dae_create(NeDae**dae,NeDynamicSystem*dynamicsystemPtr,
SscIniter*initer,boolean_T isIniter,NeRtpValues*rtpValues,NeSolverParameters
solverParameters,NeModelParameters modelParameters,const McLinearAlgebraFactory
*linearAlgebraPtr,NeProfiler*profiler,const NeCompStats*compStats,
CStateManager*csm,PmAllocator*allocatorPtr,DaeDynamicInfoWrapper*ddiWrapper,
const DaemonChoice dc);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __ne_dae_construct_h__ */
