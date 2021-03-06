


#ifndef __NASLCSTIMERMSGPROC_H__
#define __NASLCSTIMERMSGPROC_H__


/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#include    "vos.h"

/*****************************************************************************
  1.1 Cplusplus Announce
*****************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif
/*****************************************************************************
  #pragma pack(*)    设置字节对齐方式
*****************************************************************************/
#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif


/*****************************************************************************
  2 Macro
*****************************************************************************/



/*****************************************************************************
  3 Massage Declare
*****************************************************************************/



/*****************************************************************************
  4 Enum
*****************************************************************************/
/*****************************************************************************
 结构名称: NAS_LCS_TIMER_ID_ENUM
 协议表格:
 ASN.1 描述:
 结构说明: 定时器美剧
*****************************************************************************/
enum NAS_LCS_TIMER_ID_ENUM
{
    TI_NAS_LCS_WAIT_NW_RSP_TIMER        = 0,      /* 等待网侧回复定时器 */
    TI_NAS_LCS_WAIT_UE_RSP_TIMER        = 1,      /* 等待用户回复定时器 */
    TI_NAS_LCS_WATI_REEST_TIMER         = 2,      /* 重新建链定时器 */
    TI_NAS_LCS_PERIOD_INTERVAL_TIMER    = 3,      /* 周期性MO-LR间隔定时器 */
    TI_NAS_LCS_TIMER_BUTT
};
typedef VOS_UINT8 NAS_LCS_TIMER_ID_ENUM_UINT8;


/*****************************************************************************
  5 STRUCT
*****************************************************************************/
/*****************************************************************************
 结构名称: NAS_LCS_TIMER_INFO_STRU
 协议表格:
 ASN.1 描述:
 结构说明: 定时器维护信息结构体
*****************************************************************************/
typedef struct
{
    HTIMER                              hTimer;             /* vos分配的Timer Id   */
    NAS_LCS_TIMER_ID_ENUM_UINT8         enLcsTimerType;     /* Timer类型   */
    VOS_UINT8                           ucExpireTimes;      /* Timer超时次数  */
    VOS_UINT8                           aucReserve1[2];     /* 四字节对齐，保留 */
}NAS_LCS_TIMER_INFO_STRU;

/*****************************************************************************
  6 UNION
*****************************************************************************/

/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/

/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/
extern VOS_VOID NAS_LCS_TimerMsgDistr( VOS_VOID *pRcvMsg );
/*****************************************************************************
  9 OTHERS
*****************************************************************************/


#if (VOS_OS_VER != VOS_WIN32)
#pragma pack()
#else
#pragma pack(pop)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif











































