#include "binder.h"

namespace huadb {

std::string Binder::NodeTagToString(duckdb_libpgquery::PGNodeTag tag) {
  switch (tag) {
    case duckdb_libpgquery::T_PGInvalid:
      return "T_PGInvalid";
    case duckdb_libpgquery::T_PGIndexInfo:
      return "T_PGIndexInfo";
    case duckdb_libpgquery::T_PGExprContext:
      return "T_PGExprContext";
    case duckdb_libpgquery::T_PGProjectionInfo:
      return "T_PGProjectionInfo";
    case duckdb_libpgquery::T_PGJunkFilter:
      return "T_PGJunkFilter";
    case duckdb_libpgquery::T_PGResultRelInfo:
      return "T_PGResultRelInfo";
    case duckdb_libpgquery::T_PGEState:
      return "T_PGEState";
    case duckdb_libpgquery::T_PGTupleTableSlot:
      return "T_PGTupleTableSlot";
    case duckdb_libpgquery::T_PGPlan:
      return "T_PGPlan";
    case duckdb_libpgquery::T_PGResult:
      return "T_PGResult";
    case duckdb_libpgquery::T_PGProjectSet:
      return "T_PGProjectSet";
    case duckdb_libpgquery::T_PGModifyTable:
      return "T_PGModifyTable";
    case duckdb_libpgquery::T_PGAppend:
      return "T_PGAppend";
    case duckdb_libpgquery::T_PGMergeAppend:
      return "T_PGMergeAppend";
    case duckdb_libpgquery::T_PGRecursiveUnion:
      return "T_PGRecursiveUnion";
    case duckdb_libpgquery::T_PGBitmapAnd:
      return "T_PGBitmapAnd";
    case duckdb_libpgquery::T_PGBitmapOr:
      return "T_PGBitmapOr";
    case duckdb_libpgquery::T_PGScan:
      return "T_PGScan";
    case duckdb_libpgquery::T_PGSeqScan:
      return "T_PGSeqScan";
    case duckdb_libpgquery::T_PGSampleScan:
      return "T_PGSampleScan";
    case duckdb_libpgquery::T_PGIndexScan:
      return "T_PGIndexScan";
    case duckdb_libpgquery::T_PGIndexOnlyScan:
      return "T_PGIndexOnlyScan";
    case duckdb_libpgquery::T_PGBitmapIndexScan:
      return "T_PGBitmapIndexScan";
    case duckdb_libpgquery::T_PGBitmapHeapScan:
      return "T_PGBitmapHeapScan";
    case duckdb_libpgquery::T_PGTidScan:
      return "T_PGTidScan";
    case duckdb_libpgquery::T_PGSubqueryScan:
      return "T_PGSubqueryScan";
    case duckdb_libpgquery::T_PGFunctionScan:
      return "T_PGFunctionScan";
    case duckdb_libpgquery::T_PGValuesScan:
      return "T_PGValuesScan";
    case duckdb_libpgquery::T_PGTableFuncScan:
      return "T_PGTableFuncScan";
    case duckdb_libpgquery::T_PGCteScan:
      return "T_PGCteScan";
    case duckdb_libpgquery::T_PGNamedTuplestoreScan:
      return "T_PGNamedTuplestoreScan";
    case duckdb_libpgquery::T_PGWorkTableScan:
      return "T_PGWorkTableScan";
    case duckdb_libpgquery::T_PGForeignScan:
      return "T_PGForeignScan";
    case duckdb_libpgquery::T_PGCustomScan:
      return "T_PGCustomScan";
    case duckdb_libpgquery::T_PGJoin:
      return "T_PGJoin";
    case duckdb_libpgquery::T_PGNestLoop:
      return "T_PGNestLoop";
    case duckdb_libpgquery::T_PGMergeJoin:
      return "T_PGMergeJoin";
    case duckdb_libpgquery::T_PGHashJoin:
      return "T_PGHashJoin";
    case duckdb_libpgquery::T_PGMaterial:
      return "T_PGMaterial";
    case duckdb_libpgquery::T_PGSort:
      return "T_PGSort";
    case duckdb_libpgquery::T_PGGroup:
      return "T_PGGroup";
    case duckdb_libpgquery::T_PGAgg:
      return "T_PGAgg";
    case duckdb_libpgquery::T_PGWindowAgg:
      return "T_PGWindowAgg";
    case duckdb_libpgquery::T_PGUnique:
      return "T_PGUnique";
    case duckdb_libpgquery::T_PGGather:
      return "T_PGGather";
    case duckdb_libpgquery::T_PGGatherMerge:
      return "T_PGGatherMerge";
    case duckdb_libpgquery::T_PGHash:
      return "T_PGHash";
    case duckdb_libpgquery::T_PGSetOp:
      return "T_PGSetOp";
    case duckdb_libpgquery::T_PGLockRows:
      return "T_PGLockRows";
    case duckdb_libpgquery::T_PGLimit:
      return "T_PGLimit";
    case duckdb_libpgquery::T_PGNestLoopParam:
      return "T_PGNestLoopParam";
    case duckdb_libpgquery::T_PGPlanRowMark:
      return "T_PGPlanRowMark";
    case duckdb_libpgquery::T_PGPlanInvalItem:
      return "T_PGPlanInvalItem";
    case duckdb_libpgquery::T_PGPlanState:
      return "T_PGPlanState";
    case duckdb_libpgquery::T_PGResultState:
      return "T_PGResultState";
    case duckdb_libpgquery::T_PGProjectSetState:
      return "T_PGProjectSetState";
    case duckdb_libpgquery::T_PGModifyTableState:
      return "T_PGModifyTableState";
    case duckdb_libpgquery::T_PGAppendState:
      return "T_PGAppendState";
    case duckdb_libpgquery::T_PGMergeAppendState:
      return "T_PGMergeAppendState";
    case duckdb_libpgquery::T_PGRecursiveUnionState:
      return "T_PGRecursiveUnionState";
    case duckdb_libpgquery::T_PGBitmapAndState:
      return "T_PGBitmapAndState";
    case duckdb_libpgquery::T_PGBitmapOrState:
      return "T_PGBitmapOrState";
    case duckdb_libpgquery::T_PGScanState:
      return "T_PGScanState";
    case duckdb_libpgquery::T_PGSeqScanState:
      return "T_PGSeqScanState";
    case duckdb_libpgquery::T_PGSampleScanState:
      return "T_PGSampleScanState";
    case duckdb_libpgquery::T_PGIndexScanState:
      return "T_PGIndexScanState";
    case duckdb_libpgquery::T_PGIndexOnlyScanState:
      return "T_PGIndexOnlyScanState";
    case duckdb_libpgquery::T_PGBitmapIndexScanState:
      return "T_PGBitmapIndexScanState";
    case duckdb_libpgquery::T_PGBitmapHeapScanState:
      return "T_PGBitmapHeapScanState";
    case duckdb_libpgquery::T_PGTidScanState:
      return "T_PGTidScanState";
    case duckdb_libpgquery::T_PGSubqueryScanState:
      return "T_PGSubqueryScanState";
    case duckdb_libpgquery::T_PGFunctionScanState:
      return "T_PGFunctionScanState";
    case duckdb_libpgquery::T_PGTableFuncScanState:
      return "T_PGTableFuncScanState";
    case duckdb_libpgquery::T_PGValuesScanState:
      return "T_PGValuesScanState";
    case duckdb_libpgquery::T_PGCteScanState:
      return "T_PGCteScanState";
    case duckdb_libpgquery::T_PGNamedTuplestoreScanState:
      return "T_PGNamedTuplestoreScanState";
    case duckdb_libpgquery::T_PGWorkTableScanState:
      return "T_PGWorkTableScanState";
    case duckdb_libpgquery::T_PGForeignScanState:
      return "T_PGForeignScanState";
    case duckdb_libpgquery::T_PGCustomScanState:
      return "T_PGCustomScanState";
    case duckdb_libpgquery::T_PGJoinState:
      return "T_PGJoinState";
    case duckdb_libpgquery::T_PGNestLoopState:
      return "T_PGNestLoopState";
    case duckdb_libpgquery::T_PGMergeJoinState:
      return "T_PGMergeJoinState";
    case duckdb_libpgquery::T_PGHashJoinState:
      return "T_PGHashJoinState";
    case duckdb_libpgquery::T_PGMaterialState:
      return "T_PGMaterialState";
    case duckdb_libpgquery::T_PGSortState:
      return "T_PGSortState";
    case duckdb_libpgquery::T_PGGroupState:
      return "T_PGGroupState";
    case duckdb_libpgquery::T_PGAggState:
      return "T_PGAggState";
    case duckdb_libpgquery::T_PGWindowAggState:
      return "T_PGWindowAggState";
    case duckdb_libpgquery::T_PGUniqueState:
      return "T_PGUniqueState";
    case duckdb_libpgquery::T_PGGatherState:
      return "T_PGGatherState";
    case duckdb_libpgquery::T_PGGatherMergeState:
      return "T_PGGatherMergeState";
    case duckdb_libpgquery::T_PGHashState:
      return "T_PGHashState";
    case duckdb_libpgquery::T_PGSetOpState:
      return "T_PGSetOpState";
    case duckdb_libpgquery::T_PGLockRowsState:
      return "T_PGLockRowsState";
    case duckdb_libpgquery::T_PGLimitState:
      return "T_PGLimitState";
    case duckdb_libpgquery::T_PGAlias:
      return "T_PGAlias";
    case duckdb_libpgquery::T_PGRangeVar:
      return "T_PGRangeVar";
    case duckdb_libpgquery::T_PGTableFunc:
      return "T_PGTableFunc";
    case duckdb_libpgquery::T_PGExpr:
      return "T_PGExpr";
    case duckdb_libpgquery::T_PGVar:
      return "T_PGVar";
    case duckdb_libpgquery::T_PGConst:
      return "T_PGConst";
    case duckdb_libpgquery::T_PGParam:
      return "T_PGParam";
    case duckdb_libpgquery::T_PGAggref:
      return "T_PGAggref";
    case duckdb_libpgquery::T_PGGroupingFunc:
      return "T_PGGroupingFunc";
    case duckdb_libpgquery::T_PGWindowFunc:
      return "T_PGWindowFunc";
    case duckdb_libpgquery::T_PGArrayRef:
      return "T_PGArrayRef";
    case duckdb_libpgquery::T_PGFuncExpr:
      return "T_PGFuncExpr";
    case duckdb_libpgquery::T_PGNamedArgExpr:
      return "T_PGNamedArgExpr";
    case duckdb_libpgquery::T_PGOpExpr:
      return "T_PGOpExpr";
    case duckdb_libpgquery::T_PGDistinctExpr:
      return "T_PGDistinctExpr";
    case duckdb_libpgquery::T_PGNullIfExpr:
      return "T_PGNullIfExpr";
    case duckdb_libpgquery::T_PGScalarArrayOpExpr:
      return "T_PGScalarArrayOpExpr";
    case duckdb_libpgquery::T_PGBoolExpr:
      return "T_PGBoolExpr";
    case duckdb_libpgquery::T_PGSubLink:
      return "T_PGSubLink";
    case duckdb_libpgquery::T_PGSubPlan:
      return "T_PGSubPlan";
    case duckdb_libpgquery::T_PGAlternativeSubPlan:
      return "T_PGAlternativeSubPlan";
    case duckdb_libpgquery::T_PGFieldSelect:
      return "T_PGFieldSelect";
    case duckdb_libpgquery::T_PGFieldStore:
      return "T_PGFieldStore";
    case duckdb_libpgquery::T_PGRelabelType:
      return "T_PGRelabelType";
    case duckdb_libpgquery::T_PGCoerceViaIO:
      return "T_PGCoerceViaIO";
    case duckdb_libpgquery::T_PGArrayCoerceExpr:
      return "T_PGArrayCoerceExpr";
    case duckdb_libpgquery::T_PGConvertRowtypeExpr:
      return "T_PGConvertRowtypeExpr";
    case duckdb_libpgquery::T_PGCollateExpr:
      return "T_PGCollateExpr";
    case duckdb_libpgquery::T_PGCaseExpr:
      return "T_PGCaseExpr";
    case duckdb_libpgquery::T_PGCaseWhen:
      return "T_PGCaseWhen";
    case duckdb_libpgquery::T_PGCaseTestExpr:
      return "T_PGCaseTestExpr";
    case duckdb_libpgquery::T_PGArrayExpr:
      return "T_PGArrayExpr";
    case duckdb_libpgquery::T_PGRowExpr:
      return "T_PGRowExpr";
    case duckdb_libpgquery::T_PGRowCompareExpr:
      return "T_PGRowCompareExpr";
    case duckdb_libpgquery::T_PGCoalesceExpr:
      return "T_PGCoalesceExpr";
    case duckdb_libpgquery::T_PGMinMaxExpr:
      return "T_PGMinMaxExpr";
    case duckdb_libpgquery::T_PGSQLValueFunction:
      return "T_PGSQLValueFunction";
    case duckdb_libpgquery::T_PGXmlExpr:
      return "T_PGXmlExpr";
    case duckdb_libpgquery::T_PGNullTest:
      return "T_PGNullTest";
    case duckdb_libpgquery::T_PGBooleanTest:
      return "T_PGBooleanTest";
    case duckdb_libpgquery::T_PGCoerceToDomain:
      return "T_PGCoerceToDomain";
    case duckdb_libpgquery::T_PGCoerceToDomainValue:
      return "T_PGCoerceToDomainValue";
    case duckdb_libpgquery::T_PGSetToDefault:
      return "T_PGSetToDefault";
    case duckdb_libpgquery::T_PGCurrentOfExpr:
      return "T_PGCurrentOfExpr";
    case duckdb_libpgquery::T_PGNextValueExpr:
      return "T_PGNextValueExpr";
    case duckdb_libpgquery::T_PGInferenceElem:
      return "T_PGInferenceElem";
    case duckdb_libpgquery::T_PGTargetEntry:
      return "T_PGTargetEntry";
    case duckdb_libpgquery::T_PGRangeTblRef:
      return "T_PGRangeTblRef";
    case duckdb_libpgquery::T_PGJoinExpr:
      return "T_PGJoinExpr";
    case duckdb_libpgquery::T_PGFromExpr:
      return "T_PGFromExpr";
    case duckdb_libpgquery::T_PGOnConflictExpr:
      return "T_PGOnConflictExpr";
    case duckdb_libpgquery::T_PGIntoClause:
      return "T_PGIntoClause";
    case duckdb_libpgquery::T_PGLambdaFunction:
      return "T_PGLambdaFunction";
    case duckdb_libpgquery::T_PGExprState:
      return "T_PGExprState";
    case duckdb_libpgquery::T_PGAggrefExprState:
      return "T_PGAggrefExprState";
    case duckdb_libpgquery::T_PGWindowFuncExprState:
      return "T_PGWindowFuncExprState";
    case duckdb_libpgquery::T_PGSetExprState:
      return "T_PGSetExprState";
    case duckdb_libpgquery::T_PGSubPlanState:
      return "T_PGSubPlanState";
    case duckdb_libpgquery::T_PGAlternativeSubPlanState:
      return "T_PGAlternativeSubPlanState";
    case duckdb_libpgquery::T_PGDomainConstraintState:
      return "T_PGDomainConstraintState";
    case duckdb_libpgquery::T_PGPlannerInfo:
      return "T_PGPlannerInfo";
    case duckdb_libpgquery::T_PGPlannerGlobal:
      return "T_PGPlannerGlobal";
    case duckdb_libpgquery::T_PGRelOptInfo:
      return "T_PGRelOptInfo";
    case duckdb_libpgquery::T_PGIndexOptInfo:
      return "T_PGIndexOptInfo";
    case duckdb_libpgquery::T_PGForeignKeyOptInfo:
      return "T_PGForeignKeyOptInfo";
    case duckdb_libpgquery::T_PGParamPathInfo:
      return "T_PGParamPathInfo";
    case duckdb_libpgquery::T_PGPath:
      return "T_PGPath";
    case duckdb_libpgquery::T_PGIndexPath:
      return "T_PGIndexPath";
    case duckdb_libpgquery::T_PGBitmapHeapPath:
      return "T_PGBitmapHeapPath";
    case duckdb_libpgquery::T_PGBitmapAndPath:
      return "T_PGBitmapAndPath";
    case duckdb_libpgquery::T_PGBitmapOrPath:
      return "T_PGBitmapOrPath";
    case duckdb_libpgquery::T_PGTidPath:
      return "T_PGTidPath";
    case duckdb_libpgquery::T_PGSubqueryScanPath:
      return "T_PGSubqueryScanPath";
    case duckdb_libpgquery::T_PGForeignPath:
      return "T_PGForeignPath";
    case duckdb_libpgquery::T_PGCustomPath:
      return "T_PGCustomPath";
    case duckdb_libpgquery::T_PGNestPath:
      return "T_PGNestPath";
    case duckdb_libpgquery::T_PGMergePath:
      return "T_PGMergePath";
    case duckdb_libpgquery::T_PGHashPath:
      return "T_PGHashPath";
    case duckdb_libpgquery::T_PGAppendPath:
      return "T_PGAppendPath";
    case duckdb_libpgquery::T_PGMergeAppendPath:
      return "T_PGMergeAppendPath";
    case duckdb_libpgquery::T_PGResultPath:
      return "T_PGResultPath";
    case duckdb_libpgquery::T_PGMaterialPath:
      return "T_PGMaterialPath";
    case duckdb_libpgquery::T_PGUniquePath:
      return "T_PGUniquePath";
    case duckdb_libpgquery::T_PGGatherPath:
      return "T_PGGatherPath";
    case duckdb_libpgquery::T_PGGatherMergePath:
      return "T_PGGatherMergePath";
    case duckdb_libpgquery::T_PGProjectionPath:
      return "T_PGProjectionPath";
    case duckdb_libpgquery::T_PGProjectSetPath:
      return "T_PGProjectSetPath";
    case duckdb_libpgquery::T_PGSortPath:
      return "T_PGSortPath";
    case duckdb_libpgquery::T_PGGroupPath:
      return "T_PGGroupPath";
    case duckdb_libpgquery::T_PGUpperUniquePath:
      return "T_PGUpperUniquePath";
    case duckdb_libpgquery::T_PGAggPath:
      return "T_PGAggPath";
    case duckdb_libpgquery::T_PGGroupingSetsPath:
      return "T_PGGroupingSetsPath";
    case duckdb_libpgquery::T_PGMinMaxAggPath:
      return "T_PGMinMaxAggPath";
    case duckdb_libpgquery::T_PGWindowAggPath:
      return "T_PGWindowAggPath";
    case duckdb_libpgquery::T_PGSetOpPath:
      return "T_PGSetOpPath";
    case duckdb_libpgquery::T_PGRecursiveUnionPath:
      return "T_PGRecursiveUnionPath";
    case duckdb_libpgquery::T_PGLockRowsPath:
      return "T_PGLockRowsPath";
    case duckdb_libpgquery::T_PGModifyTablePath:
      return "T_PGModifyTablePath";
    case duckdb_libpgquery::T_PGLimitPath:
      return "T_PGLimitPath";
    case duckdb_libpgquery::T_PGEquivalenceClass:
      return "T_PGEquivalenceClass";
    case duckdb_libpgquery::T_PGEquivalenceMember:
      return "T_PGEquivalenceMember";
    case duckdb_libpgquery::T_PGPathKey:
      return "T_PGPathKey";
    case duckdb_libpgquery::T_PGPathTarget:
      return "T_PGPathTarget";
    case duckdb_libpgquery::T_PGRestrictInfo:
      return "T_PGRestrictInfo";
    case duckdb_libpgquery::T_PGPlaceHolderVar:
      return "T_PGPlaceHolderVar";
    case duckdb_libpgquery::T_PGSpecialJoinInfo:
      return "T_PGSpecialJoinInfo";
    case duckdb_libpgquery::T_PGAppendRelInfo:
      return "T_PGAppendRelInfo";
    case duckdb_libpgquery::T_PGPartitionedChildRelInfo:
      return "T_PGPartitionedChildRelInfo";
    case duckdb_libpgquery::T_PGPlaceHolderInfo:
      return "T_PGPlaceHolderInfo";
    case duckdb_libpgquery::T_PGMinMaxAggInfo:
      return "T_PGMinMaxAggInfo";
    case duckdb_libpgquery::T_PGPlannerParamItem:
      return "T_PGPlannerParamItem";
    case duckdb_libpgquery::T_PGRollupData:
      return "T_PGRollupData";
    case duckdb_libpgquery::T_PGGroupingSetData:
      return "T_PGGroupingSetData";
    case duckdb_libpgquery::T_PGStatisticExtInfo:
      return "T_PGStatisticExtInfo";
    case duckdb_libpgquery::T_PGMemoryContext:
      return "T_PGMemoryContext";
    case duckdb_libpgquery::T_PGAllocSetContext:
      return "T_PGAllocSetContext";
    case duckdb_libpgquery::T_PGSlabContext:
      return "T_PGSlabContext";
    case duckdb_libpgquery::T_PGValue:
      return "T_PGValue";
    case duckdb_libpgquery::T_PGInteger:
      return "T_PGInteger";
    case duckdb_libpgquery::T_PGFloat:
      return "T_PGFloat";
    case duckdb_libpgquery::T_PGString:
      return "T_PGString";
    case duckdb_libpgquery::T_PGBitString:
      return "T_PGBitString";
    case duckdb_libpgquery::T_PGNull:
      return "T_PGNull";
    case duckdb_libpgquery::T_PGList:
      return "T_PGList";
    case duckdb_libpgquery::T_PGIntList:
      return "T_PGIntList";
    case duckdb_libpgquery::T_PGOidList:
      return "T_PGOidList";
    case duckdb_libpgquery::T_PGExtensibleNode:
      return "T_PGExtensibleNode";
    case duckdb_libpgquery::T_PGRawStmt:
      return "T_PGRawStmt";
    case duckdb_libpgquery::T_PGQuery:
      return "T_PGQuery";
    case duckdb_libpgquery::T_PGPlannedStmt:
      return "T_PGPlannedStmt";
    case duckdb_libpgquery::T_PGInsertStmt:
      return "T_PGInsertStmt";
    case duckdb_libpgquery::T_PGDeleteStmt:
      return "T_PGDeleteStmt";
    case duckdb_libpgquery::T_PGUpdateStmt:
      return "T_PGUpdateStmt";
    case duckdb_libpgquery::T_PGSelectStmt:
      return "T_PGSelectStmt";
    case duckdb_libpgquery::T_PGAlterTableStmt:
      return "T_PGAlterTableStmt";
    case duckdb_libpgquery::T_PGAlterTableCmd:
      return "T_PGAlterTableCmd";
    case duckdb_libpgquery::T_PGAlterDomainStmt:
      return "T_PGAlterDomainStmt";
    case duckdb_libpgquery::T_PGSetOperationStmt:
      return "T_PGSetOperationStmt";
    case duckdb_libpgquery::T_PGGrantStmt:
      return "T_PGGrantStmt";
    case duckdb_libpgquery::T_PGGrantRoleStmt:
      return "T_PGGrantRoleStmt";
    case duckdb_libpgquery::T_PGAlterDefaultPrivilegesStmt:
      return "T_PGAlterDefaultPrivilegesStmt";
    case duckdb_libpgquery::T_PGClosePortalStmt:
      return "T_PGClosePortalStmt";
    case duckdb_libpgquery::T_PGClusterStmt:
      return "T_PGClusterStmt";
    case duckdb_libpgquery::T_PGCopyStmt:
      return "T_PGCopyStmt";
    case duckdb_libpgquery::T_PGCreateStmt:
      return "T_PGCreateStmt";
    case duckdb_libpgquery::T_PGDefineStmt:
      return "T_PGDefineStmt";
    case duckdb_libpgquery::T_PGDropStmt:
      return "T_PGDropStmt";
    case duckdb_libpgquery::T_PGTruncateStmt:
      return "T_PGTruncateStmt";
    case duckdb_libpgquery::T_PGCommentStmt:
      return "T_PGCommentStmt";
    case duckdb_libpgquery::T_PGFetchStmt:
      return "T_PGFetchStmt";
    case duckdb_libpgquery::T_PGIndexStmt:
      return "T_PGIndexStmt";
    case duckdb_libpgquery::T_PGCreateFunctionStmt:
      return "T_PGCreateFunctionStmt";
    case duckdb_libpgquery::T_PGAlterFunctionStmt:
      return "T_PGAlterFunctionStmt";
    case duckdb_libpgquery::T_PGDoStmt:
      return "T_PGDoStmt";
    case duckdb_libpgquery::T_PGRenameStmt:
      return "T_PGRenameStmt";
    case duckdb_libpgquery::T_PGRuleStmt:
      return "T_PGRuleStmt";
    case duckdb_libpgquery::T_PGNotifyStmt:
      return "T_PGNotifyStmt";
    case duckdb_libpgquery::T_PGListenStmt:
      return "T_PGListenStmt";
    case duckdb_libpgquery::T_PGUnlistenStmt:
      return "T_PGUnlistenStmt";
    case duckdb_libpgquery::T_PGTransactionStmt:
      return "T_PGTransactionStmt";
    case duckdb_libpgquery::T_PGViewStmt:
      return "T_PGViewStmt";
    case duckdb_libpgquery::T_PGLoadStmt:
      return "T_PGLoadStmt";
    case duckdb_libpgquery::T_PGCreateDomainStmt:
      return "T_PGCreateDomainStmt";
    case duckdb_libpgquery::T_PGCreatedbStmt:
      return "T_PGCreatedbStmt";
    case duckdb_libpgquery::T_PGDropdbStmt:
      return "T_PGDropdbStmt";
    case duckdb_libpgquery::T_PGVacuumStmt:
      return "T_PGVacuumStmt";
    case duckdb_libpgquery::T_PGExplainStmt:
      return "T_PGExplainStmt";
    case duckdb_libpgquery::T_PGCreateTableAsStmt:
      return "T_PGCreateTableAsStmt";
    case duckdb_libpgquery::T_PGCreateSeqStmt:
      return "T_PGCreateSeqStmt";
    case duckdb_libpgquery::T_PGAlterSeqStmt:
      return "T_PGAlterSeqStmt";
    case duckdb_libpgquery::T_PGVariableSetStmt:
      return "T_PGVariableSetStmt";
    case duckdb_libpgquery::T_PGVariableShowStmt:
      return "T_PGVariableShowStmt";
    case duckdb_libpgquery::T_PGVariableShowSelectStmt:
      return "T_PGVariableShowSelectStmt";
    case duckdb_libpgquery::T_PGDiscardStmt:
      return "T_PGDiscardStmt";
    case duckdb_libpgquery::T_PGCreateTrigStmt:
      return "T_PGCreateTrigStmt";
    case duckdb_libpgquery::T_PGCreatePLangStmt:
      return "T_PGCreatePLangStmt";
    case duckdb_libpgquery::T_PGCreateRoleStmt:
      return "T_PGCreateRoleStmt";
    case duckdb_libpgquery::T_PGAlterRoleStmt:
      return "T_PGAlterRoleStmt";
    case duckdb_libpgquery::T_PGDropRoleStmt:
      return "T_PGDropRoleStmt";
    case duckdb_libpgquery::T_PGLockStmt:
      return "T_PGLockStmt";
    case duckdb_libpgquery::T_PGConstraintsSetStmt:
      return "T_PGConstraintsSetStmt";
    case duckdb_libpgquery::T_PGReindexStmt:
      return "T_PGReindexStmt";
    case duckdb_libpgquery::T_PGCheckPointStmt:
      return "T_PGCheckPointStmt";
    case duckdb_libpgquery::T_PGCreateSchemaStmt:
      return "T_PGCreateSchemaStmt";
    case duckdb_libpgquery::T_PGAlterDatabaseStmt:
      return "T_PGAlterDatabaseStmt";
    case duckdb_libpgquery::T_PGAlterDatabaseSetStmt:
      return "T_PGAlterDatabaseSetStmt";
    case duckdb_libpgquery::T_PGAlterRoleSetStmt:
      return "T_PGAlterRoleSetStmt";
    case duckdb_libpgquery::T_PGCreateConversionStmt:
      return "T_PGCreateConversionStmt";
    case duckdb_libpgquery::T_PGCreateCastStmt:
      return "T_PGCreateCastStmt";
    case duckdb_libpgquery::T_PGCreateOpClassStmt:
      return "T_PGCreateOpClassStmt";
    case duckdb_libpgquery::T_PGCreateOpFamilyStmt:
      return "T_PGCreateOpFamilyStmt";
    case duckdb_libpgquery::T_PGAlterOpFamilyStmt:
      return "T_PGAlterOpFamilyStmt";
    case duckdb_libpgquery::T_PGPrepareStmt:
      return "T_PGPrepareStmt";
    case duckdb_libpgquery::T_PGExecuteStmt:
      return "T_PGExecuteStmt";
    case duckdb_libpgquery::T_PGCallStmt:
      return "T_PGCallStmt";
    case duckdb_libpgquery::T_PGDeallocateStmt:
      return "T_PGDeallocateStmt";
    case duckdb_libpgquery::T_PGDeclareCursorStmt:
      return "T_PGDeclareCursorStmt";
    case duckdb_libpgquery::T_PGCreateTableSpaceStmt:
      return "T_PGCreateTableSpaceStmt";
    case duckdb_libpgquery::T_PGDropTableSpaceStmt:
      return "T_PGDropTableSpaceStmt";
    case duckdb_libpgquery::T_PGAlterObjectDependsStmt:
      return "T_PGAlterObjectDependsStmt";
    case duckdb_libpgquery::T_PGAlterObjectSchemaStmt:
      return "T_PGAlterObjectSchemaStmt";
    case duckdb_libpgquery::T_PGAlterOwnerStmt:
      return "T_PGAlterOwnerStmt";
    case duckdb_libpgquery::T_PGAlterOperatorStmt:
      return "T_PGAlterOperatorStmt";
    case duckdb_libpgquery::T_PGDropOwnedStmt:
      return "T_PGDropOwnedStmt";
    case duckdb_libpgquery::T_PGReassignOwnedStmt:
      return "T_PGReassignOwnedStmt";
    case duckdb_libpgquery::T_PGCompositeTypeStmt:
      return "T_PGCompositeTypeStmt";
    case duckdb_libpgquery::T_PGCreateTypeStmt:
      return "T_PGCreateTypeStmt";
    case duckdb_libpgquery::T_PGCreateRangeStmt:
      return "T_PGCreateRangeStmt";
    case duckdb_libpgquery::T_PGAlterEnumStmt:
      return "T_PGAlterEnumStmt";
    case duckdb_libpgquery::T_PGAlterTSDictionaryStmt:
      return "T_PGAlterTSDictionaryStmt";
    case duckdb_libpgquery::T_PGAlterTSConfigurationStmt:
      return "T_PGAlterTSConfigurationStmt";
    case duckdb_libpgquery::T_PGCreateFdwStmt:
      return "T_PGCreateFdwStmt";
    case duckdb_libpgquery::T_PGAlterFdwStmt:
      return "T_PGAlterFdwStmt";
    case duckdb_libpgquery::T_PGCreateForeignServerStmt:
      return "T_PGCreateForeignServerStmt";
    case duckdb_libpgquery::T_PGAlterForeignServerStmt:
      return "T_PGAlterForeignServerStmt";
    case duckdb_libpgquery::T_PGCreateUserMappingStmt:
      return "T_PGCreateUserMappingStmt";
    case duckdb_libpgquery::T_PGAlterUserMappingStmt:
      return "T_PGAlterUserMappingStmt";
    case duckdb_libpgquery::T_PGDropUserMappingStmt:
      return "T_PGDropUserMappingStmt";
    case duckdb_libpgquery::T_PGAlterTableSpaceOptionsStmt:
      return "T_PGAlterTableSpaceOptionsStmt";
    case duckdb_libpgquery::T_PGAlterTableMoveAllStmt:
      return "T_PGAlterTableMoveAllStmt";
    case duckdb_libpgquery::T_PGSecLabelStmt:
      return "T_PGSecLabelStmt";
    case duckdb_libpgquery::T_PGCreateForeignTableStmt:
      return "T_PGCreateForeignTableStmt";
    case duckdb_libpgquery::T_PGImportForeignSchemaStmt:
      return "T_PGImportForeignSchemaStmt";
    case duckdb_libpgquery::T_PGCreateExtensionStmt:
      return "T_PGCreateExtensionStmt";
    case duckdb_libpgquery::T_PGAlterExtensionStmt:
      return "T_PGAlterExtensionStmt";
    case duckdb_libpgquery::T_PGAlterExtensionContentsStmt:
      return "T_PGAlterExtensionContentsStmt";
    case duckdb_libpgquery::T_PGCreateEventTrigStmt:
      return "T_PGCreateEventTrigStmt";
    case duckdb_libpgquery::T_PGAlterEventTrigStmt:
      return "T_PGAlterEventTrigStmt";
    case duckdb_libpgquery::T_PGRefreshMatViewStmt:
      return "T_PGRefreshMatViewStmt";
    case duckdb_libpgquery::T_PGReplicaIdentityStmt:
      return "T_PGReplicaIdentityStmt";
    case duckdb_libpgquery::T_PGAlterSystemStmt:
      return "T_PGAlterSystemStmt";
    case duckdb_libpgquery::T_PGCreatePolicyStmt:
      return "T_PGCreatePolicyStmt";
    case duckdb_libpgquery::T_PGAlterPolicyStmt:
      return "T_PGAlterPolicyStmt";
    case duckdb_libpgquery::T_PGCreateTransformStmt:
      return "T_PGCreateTransformStmt";
    case duckdb_libpgquery::T_PGCreateAmStmt:
      return "T_PGCreateAmStmt";
    case duckdb_libpgquery::T_PGCreatePublicationStmt:
      return "T_PGCreatePublicationStmt";
    case duckdb_libpgquery::T_PGAlterPublicationStmt:
      return "T_PGAlterPublicationStmt";
    case duckdb_libpgquery::T_PGCreateSubscriptionStmt:
      return "T_PGCreateSubscriptionStmt";
    case duckdb_libpgquery::T_PGAlterSubscriptionStmt:
      return "T_PGAlterSubscriptionStmt";
    case duckdb_libpgquery::T_PGDropSubscriptionStmt:
      return "T_PGDropSubscriptionStmt";
    case duckdb_libpgquery::T_PGCreateStatsStmt:
      return "T_PGCreateStatsStmt";
    case duckdb_libpgquery::T_PGAlterCollationStmt:
      return "T_PGAlterCollationStmt";
    case duckdb_libpgquery::T_PGPragmaStmt:
      return "T_PGPragmaStmt";
    case duckdb_libpgquery::T_PGExportStmt:
      return "T_PGExportStmt";
    case duckdb_libpgquery::T_PGImportStmt:
      return "T_PGImportStmt";
    case duckdb_libpgquery::T_PGAttachStmt:
      return "T_PGAttachStmt";
    case duckdb_libpgquery::T_PGDetachStmt:
      return "T_PGDetachStmt";
    case duckdb_libpgquery::T_PGCreateDatabaseStmt:
      return "T_PGCreateDatabaseStmt";
    case duckdb_libpgquery::T_PGUseStmt:
      return "T_PGUseStmt";
    case duckdb_libpgquery::T_PGAExpr:
      return "T_PGAExpr";
    case duckdb_libpgquery::T_PGColumnRef:
      return "T_PGColumnRef";
    case duckdb_libpgquery::T_PGParamRef:
      return "T_PGParamRef";
    case duckdb_libpgquery::T_PGAConst:
      return "T_PGAConst";
    case duckdb_libpgquery::T_PGFuncCall:
      return "T_PGFuncCall";
    case duckdb_libpgquery::T_PGAStar:
      return "T_PGAStar";
    case duckdb_libpgquery::T_PGAIndices:
      return "T_PGAIndices";
    case duckdb_libpgquery::T_PGAIndirection:
      return "T_PGAIndirection";
    case duckdb_libpgquery::T_PGAArrayExpr:
      return "T_PGAArrayExpr";
    case duckdb_libpgquery::T_PGResTarget:
      return "T_PGResTarget";
    case duckdb_libpgquery::T_PGMultiAssignRef:
      return "T_PGMultiAssignRef";
    case duckdb_libpgquery::T_PGTypeCast:
      return "T_PGTypeCast";
    case duckdb_libpgquery::T_PGCollateClause:
      return "T_PGCollateClause";
    case duckdb_libpgquery::T_PGSortBy:
      return "T_PGSortBy";
    case duckdb_libpgquery::T_PGWindowDef:
      return "T_PGWindowDef";
    case duckdb_libpgquery::T_PGRangeSubselect:
      return "T_PGRangeSubselect";
    case duckdb_libpgquery::T_PGRangeFunction:
      return "T_PGRangeFunction";
    case duckdb_libpgquery::T_PGRangeTableSample:
      return "T_PGRangeTableSample";
    case duckdb_libpgquery::T_PGRangeTableFunc:
      return "T_PGRangeTableFunc";
    case duckdb_libpgquery::T_PGRangeTableFuncCol:
      return "T_PGRangeTableFuncCol";
    case duckdb_libpgquery::T_PGTypeName:
      return "T_PGTypeName";
    case duckdb_libpgquery::T_PGColumnDef:
      return "T_PGColumnDef";
    case duckdb_libpgquery::T_PGIndexElem:
      return "T_PGIndexElem";
    case duckdb_libpgquery::T_PGConstraint:
      return "T_PGConstraint";
    case duckdb_libpgquery::T_PGDefElem:
      return "T_PGDefElem";
    case duckdb_libpgquery::T_PGRangeTblEntry:
      return "T_PGRangeTblEntry";
    case duckdb_libpgquery::T_PGRangeTblFunction:
      return "T_PGRangeTblFunction";
    case duckdb_libpgquery::T_PGTableSampleClause:
      return "T_PGTableSampleClause";
    case duckdb_libpgquery::T_PGWithCheckOption:
      return "T_PGWithCheckOption";
    case duckdb_libpgquery::T_PGSortGroupClause:
      return "T_PGSortGroupClause";
    case duckdb_libpgquery::T_PGGroupingSet:
      return "T_PGGroupingSet";
    case duckdb_libpgquery::T_PGWindowClause:
      return "T_PGWindowClause";
    case duckdb_libpgquery::T_PGObjectWithArgs:
      return "T_PGObjectWithArgs";
    case duckdb_libpgquery::T_PGAccessPriv:
      return "T_PGAccessPriv";
    case duckdb_libpgquery::T_PGCreateOpClassItem:
      return "T_PGCreateOpClassItem";
    case duckdb_libpgquery::T_PGTableLikeClause:
      return "T_PGTableLikeClause";
    case duckdb_libpgquery::T_PGFunctionParameter:
      return "T_PGFunctionParameter";
    case duckdb_libpgquery::T_PGLockingClause:
      return "T_PGLockingClause";
    case duckdb_libpgquery::T_PGRowMarkClause:
      return "T_PGRowMarkClause";
    case duckdb_libpgquery::T_PGXmlSerialize:
      return "T_PGXmlSerialize";
    case duckdb_libpgquery::T_PGWithClause:
      return "T_PGWithClause";
    case duckdb_libpgquery::T_PGInferClause:
      return "T_PGInferClause";
    case duckdb_libpgquery::T_PGOnConflictClause:
      return "T_PGOnConflictClause";
    case duckdb_libpgquery::T_PGCommonTableExpr:
      return "T_PGCommonTableExpr";
    case duckdb_libpgquery::T_PGRoleSpec:
      return "T_PGRoleSpec";
    case duckdb_libpgquery::T_PGTriggerTransition:
      return "T_PGTriggerTransition";
    case duckdb_libpgquery::T_PGPartitionElem:
      return "T_PGPartitionElem";
    case duckdb_libpgquery::T_PGPartitionSpec:
      return "T_PGPartitionSpec";
    case duckdb_libpgquery::T_PGPartitionBoundSpec:
      return "T_PGPartitionBoundSpec";
    case duckdb_libpgquery::T_PGPartitionRangeDatum:
      return "T_PGPartitionRangeDatum";
    case duckdb_libpgquery::T_PGPartitionCmd:
      return "T_PGPartitionCmd";
    case duckdb_libpgquery::T_PGIntervalConstant:
      return "T_PGIntervalConstant";
    case duckdb_libpgquery::T_PGSampleSize:
      return "T_PGSampleSize";
    case duckdb_libpgquery::T_PGSampleOptions:
      return "T_PGSampleOptions";
    case duckdb_libpgquery::T_PGLimitPercent:
      return "T_PGLimitPercent";
    case duckdb_libpgquery::T_PGPositionalReference:
      return "T_PGPositionalReference";
    case duckdb_libpgquery::T_PGIdentifySystemCmd:
      return "T_PGIdentifySystemCmd";
    case duckdb_libpgquery::T_PGBaseBackupCmd:
      return "T_PGBaseBackupCmd";
    case duckdb_libpgquery::T_PGCreateReplicationSlotCmd:
      return "T_PGCreateReplicationSlotCmd";
    case duckdb_libpgquery::T_PGDropReplicationSlotCmd:
      return "T_PGDropReplicationSlotCmd";
    case duckdb_libpgquery::T_PGStartReplicationCmd:
      return "T_PGStartReplicationCmd";
    case duckdb_libpgquery::T_PGTimeLineHistoryCmd:
      return "T_PGTimeLineHistoryCmd";
    case duckdb_libpgquery::T_PGSQLCmd:
      return "T_PGSQLCmd";
    case duckdb_libpgquery::T_PGTriggerData:
      return "T_PGTriggerData";
    case duckdb_libpgquery::T_PGEventTriggerData:
      return "T_PGEventTriggerData";
    case duckdb_libpgquery::T_PGReturnSetInfo:
      return "T_PGReturnSetInfo";
    case duckdb_libpgquery::T_PGWindowObjectData:
      return "T_PGWindowObjectData";
    case duckdb_libpgquery::T_PGTIDBitmap:
      return "T_PGTIDBitmap";
    case duckdb_libpgquery::T_PGInlineCodeBlock:
      return "T_PGInlineCodeBlock";
    case duckdb_libpgquery::T_PGFdwRoutine:
      return "T_PGFdwRoutine";
    case duckdb_libpgquery::T_PGIndexAmRoutine:
      return "T_PGIndexAmRoutine";
    case duckdb_libpgquery::T_PGTsmRoutine:
      return "T_PGTsmRoutine";
    case duckdb_libpgquery::T_PGForeignKeyCacheInfo:
      return "T_PGForeignKeyCacheInfo";
    default:
      return "(UNKNOWN)";
  }
}

}  // namespace huadb
