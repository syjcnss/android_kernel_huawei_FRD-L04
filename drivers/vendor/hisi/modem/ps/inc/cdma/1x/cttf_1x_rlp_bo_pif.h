/** ****************************************************************************

                    Huawei Technologies Sweden AB (C), 2001-2015

 ********************************************************************************
 * @author    Automatically generated by DAISY
 * @version
 * @date      2015-12-30 14:30:41
 * @file
 * @brief
 * This interface is used by CAS and NAS to register callback functions to
 * receive reverselink of buffer occupancy of active RLP entities and status of
 * valid RLP frames sent/receive to/from network.
 * @copyright Huawei Technologies Sweden AB
 *******************************************************************************/
#ifndef CTTF_1X_RLP_BO_PIF_H
#define CTTF_1X_RLP_BO_PIF_H

/*******************************************************************************
 1. Other files included
*******************************************************************************/

#include "vos.h"
#include "cttf_1x_rlp_pub_pif.h"
#include "PsTypeDef.h"

#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#pragma pack(4)

/*******************************************************************************
 2. Macro definitions
*******************************************************************************/


/*******************************************************************************
 3. Enumerations declarations
*******************************************************************************/

/** ****************************************************************************
 * Name        : RLPITF_FORWARD_SCH_STATUS_ENUM_UINT8
 *
 * Description : contains F-SCH status. (exists or does not exist)
 *******************************************************************************/
enum RLPITF_FORWARD_SCH_STATUS_ENUM
{
    RLPITF_FORWARD_SCH_STATUS_EXIST     = 0x00,
    RLPITF_FORWARD_SCH_STATUS_NOT_EXIST = 0x01,
    RLPITF_FORWARD_SCH_STATUS_BUTT      = 0x02
};
typedef VOS_UINT8 RLPITF_FORWARD_SCH_STATUS_ENUM_UINT8;

/** ****************************************************************************
 * Name        : RLPITF_REVERSE_SCH_STATUS_ENUM_UINT8
 *
 * Description : contains R-SCH status. (exists, does not exist for some detail
 * reason)
 *******************************************************************************/
enum RLPITF_REVERSE_SCH_STATUS_ENUM
{
    RLPITF_REVERSE_SCH_STATUS_EXIST                         = 0x00,
    RLPITF_REVERSE_SCH_STATUS_NOT_EXIST_DTX                 = 0x01, /**< When DTX timer expired, MAC set R-SCH to this status. */
    RLPITF_REVERSE_SCH_STATUS_NOT_EXIST_LIFETIME            = 0x02, /**< When LifeTime of R-SCH reached, MAC set R-SCH to this status. */
    RLPITF_REVERSE_SCH_STATUS_NOT_EXIST_OTHER               = 0x03, /**< MAC release R-SCH other than DTX and LifeTime , MAC set R-SCH to this status. */
    RLPITF_REVERSE_SCH_STATUS_BUTT                          = 0x04
};
typedef VOS_UINT8 RLPITF_REVERSE_SCH_STATUS_ENUM_UINT8;

/*******************************************************************************
 4. Message Header declaration
*******************************************************************************/

/*******************************************************************************
 5. Message declaration
*******************************************************************************/

/*******************************************************************************
 6. STRUCT and UNION declaration
*******************************************************************************/

/** ****************************************************************************
 * Name        : RLPITF_1X_RLP_BO_VALIDFRAME_STRU
 *
 * Description : This contains information used by CAS and NAS.
 * @usServiceOption : Service option associated with the ucSrId.
 * @ucConnReference : Reference to the service option connection. NAS requires
 * this.
 * @ucSrId : The value is used to identify data for this service option
 * connection. CAS requires this.
 * @enNonIdleFrameSentOrRcvd: Set to PS_TRUE if a non idle RLP frame is sent or
 * received. Otherwise, it's set to PS_FALSE.
 * @enRschStatus : R-SCH status. CAS requires this.
 * @ulRevRlpEntityBo: Contains the total reverse link buffer occupancy in bytes
 * for RLP entity with ucSrId
 *******************************************************************************/
typedef struct
{
    VOS_UINT16                                              usServiceOption;
    VOS_UINT8                                               ucConnReference;
    VOS_UINT8                                               ucSrId;
    PS_BOOL_ENUM_UINT8                                      enNonIdleFrameSentOrRcvd;
    PS_BOOL_ENUM_UINT8                                      enNonIdleNonFillFrameSentOrRcvd;
    RLPITF_REVERSE_SCH_STATUS_ENUM_UINT8                    enRschStatus;
    RLPITF_FORWARD_SCH_STATUS_ENUM_UINT8                    enFschStatus;
    VOS_UINT32                                              ulRevRlpEntityBo;
} RLPITF_1X_RLP_BO_VALIDFRAME_STRU;

/** ****************************************************************************
 * Name        : RLPITF_1X_RLP_DATA_STAT_STRU
 *
 * Description : This contains information used by CAS and NAS. Based on the
 * values reported in this, CAS and NAS decide whether to request R-SCH or
 * disable packet inactivity timer respectively.
 * @ucActiveConnsCnt: Total RLP entities for which BO and Valid Frame details
 * are provided in this structure
 * @astRlpBoValidFrame: Contains valid frame received or sent details for each
 * active RLP entity and reverse link buffer occupancy
 *******************************************************************************/
typedef struct
{
    VOS_UINT8                           ucActiveConnsCnt;
    VOS_UINT8                           aucReserved[3];
    RLPITF_1X_RLP_BO_VALIDFRAME_STRU    astRlpBoValidFrame[CTTF_1X_RLP_MAX_SRV_CONN_REC_NUM];
} RLPITF_1X_RLP_DATA_STAT_STRU;

/*******************************************************************************
 7. OTHER declarations
*******************************************************************************/

/*******************************************************************************
 8. Global  declaration
*******************************************************************************/

/*******************************************************************************
 9. Function declarations
*******************************************************************************/

/** ****************************************************************************
 * Name        : CTTF_1X_L3_BO_RLP_BO_FRAME_FUNC_CB
 *
 * Description : function type definition used by RLP to update CAS and NAS
 * with Reverse Link Total Buffer Occupancy and if a valid RLP frame is
 * sent/received to the network. Updated every 20ms
 * @pstRlpDataStat: pointer to struct of type RLPITF_1X_RLP_DATA_STAT_STRU
 *******************************************************************************/
typedef VOS_VOID (*CTTF_1X_L3_BO_RLP_BO_FRAME_FUNC_CB)(const RLPITF_1X_RLP_DATA_STAT_STRU *pstRlpDataStat);

/** ****************************************************************************
 * Name        : CTTF_1X_RLP_RegUserDataUpdateCB
 *
 * Description :
 *
 * @param[in] ulClientId
 * @param[in] pfuncRegFunc
 *******************************************************************************/
VOS_UINT32 CTTF_1X_RLP_RegUserDataUpdateCB(VOS_UINT32 ulClientId,
                                           CTTF_1X_L3_BO_RLP_BO_FRAME_FUNC_CB pfuncRegFunc);

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif