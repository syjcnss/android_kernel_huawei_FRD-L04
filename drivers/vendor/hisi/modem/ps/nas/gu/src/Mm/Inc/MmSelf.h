

#ifndef _MM_SELF_H_
#define _MM_SELF_H_

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/
 #define MM_ZERO                        0

 #define MM_MSGDISPATCH                 1
 #define MM_SUSPEND                     2
 #define MM_AUTH                        3
 #define MM_GSMDIFMSG                   4
 #define MM_ORIGIN                      5

 #define MM_MAX_MSG_NUM                 10
 #define MM_MAX_MSG_LENGTH              1000


 #define NAS_LOG(ModulePID, SubMod, Level, String)                               PS_NAS_LOG(ModulePID, SubMod, Level, String)
 #define NAS_LOG1(ModulePID, SubMod, Level, String, Para)                        PS_NAS_LOG1(ModulePID, SubMod, Level, String, Para)
 #define NAS_LOG2(ModulePID, SubMod, Level, String, Para1, Para2)                PS_NAS_LOG2(ModulePID, SubMod, Level, String, Para1, Para2)
 #define NAS_LOG3(ModulePID, SubMod, Level, String, Para1, Para2, Para3)         PS_NAS_LOG3(ModulePID, SubMod, Level, String, Para1, Para2, Para3)
 #define NAS_LOG4(ModulePID, SubMod, Level, String, Para1, Para2, Para3, Para4)  PS_NAS_LOG4(ModulePID, SubMod, Level, String, Para1, Para2, Para3, Para4)

 /*******************************************************************************
  3 枚举定义
*******************************************************************************/

/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/

/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/
/*Identification 标识：MM_SUSPEND_MSG_CELL_ST
Type 类型：
Purpose目的：在切换或小区重选状态下缓存消息队列中消息单元 */
typedef struct
{
    VOS_VOID                           *pstMsg;                       /* 具体消息缓存 */
    VOS_UINT8                           ucEventId;                    /* 该消息对应事件ID  */
    VOS_UINT8                           aucReserved[3];
}MM_SUSPEND_MSG_CELL_ST;

/* Identification 标识：MM_SUSPEND_MSG_BUF_ST
Type 类型：
Purpose目的：在切换或小区重选状态下缓存消息的队列 */
typedef struct
{
    MM_SUSPEND_MSG_CELL_ST              astMsg[MM_MAX_MSG_NUM];
    VOS_UINT8                           ucMsgNum;           /* 缓存消息的数目     */
    /* 缓存消息索引,挂起时，表示数组当前空闲位置；恢复时，表示要恢复消息位置 */
    VOS_UINT8                           ucIndex;
    /* 缓存的具体消息结构 */
    VOS_UINT8                           aucReserved[2];
}MM_SUSPEND_MSG_BUF_ST;

/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  8 OTHERS定义
*****************************************************************************/

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of MmSelf.h */
