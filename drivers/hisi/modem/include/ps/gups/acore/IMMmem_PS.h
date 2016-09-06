


#ifndef __IMM_MEM_PS_H__
#define __IMM_MEM_PS_H__

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include "product_config.h"
#if (VOS_LINUX == VOS_OS_VER)
#include <linux/skbuff.h>
#else
#include "skbuff.h"
#endif


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif




#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define FEATURE_IMM_MEM_DEBUG           (FEATURE_TTF_MEM_DEBUG)


/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/
/*****************************************************************************
 ö����    : IMM_BOOL_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : IMMͳһ��������ö�ٶ���
*****************************************************************************/
enum IMM_BOOL_ENUM
{
    IMM_FALSE                            = 0,
    IMM_TRUE                             = 1,
    IMM_BOOL_BUTT
};
typedef unsigned char   IMM_BOOL_ENUM_UINT8;

/*****************************************************************************
 ö����    : IMM_RSLT_CODE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : IMM ͳһ����ֵö�ٶ���
*****************************************************************************/
enum IMM_RSLT_CODE_ENUM
{
    IMM_SUCC                             = 0,
    IMM_FAIL                             = 1,
};
typedef unsigned int   IMM_RSLT_CODE_ENUM_UINT32;


/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/

enum MEM_BLK_STATE_ENUM
{
    MEM_BLK_STATE_FREE,       /*���ڴ�δ����������ͷ�*/
    MEM_BLK_STATE_ALLOC,      /*���ڴ�������*/
    MEM_BLK_STATE_BUTT
};
typedef unsigned int MEM_BLK_STATE_ENUM_UINT32;



typedef struct
{
    MEM_BLK_STATE_ENUM_UINT32           enMemStateFlag;
    unsigned int                        ulAllocTick;        /* CPU tick when alloc or free */
    unsigned short                      usAllocFileID;      /* File ID when alloc or free */
    unsigned short                      usAllocLineNum;     /* File Line when alloc or free */
    unsigned short                      usTraceFileID;      /* File ID when traced */
    unsigned short                      usTraceLineNum;     /* File Line when traced */
    unsigned int                        ulTraceTick;        /* CPU tick when traced */
} IMM_BLK_MEM_DEBUG_STRU;



enum IMM_MEM_POOL_ID_ENUM
{
    IMM_MEM_POOL_ID_SHARE = 0,              /* A�˹����ڴ��ID */
    IMM_MEM_POOL_ID_EXT,                    /* A���ⲿ�ڴ��ID */

    IMM_MEM_POOL_ID_BUTT
};
typedef unsigned char IMM_MEM_POOL_ID_ENUM_UINT8;



typedef struct
{
    IMM_MEM_POOL_ID_ENUM_UINT8          enPoolId;           /* ���ڴ�����������ĸ��ڴ�� */
    unsigned char                       ucClusterId;        /* ���ڴ���������һ������ */
    unsigned short                      usMagicNum;         /* �ڴ���ƿ�ħ���� */
#if(FEATURE_ON == FEATURE_IMM_MEM_DEBUG)
    IMM_BLK_MEM_DEBUG_STRU              stDbgInfo;         /* �ڴ���ƿ��DEBUG��Ϣ�洢�� */
#endif
    unsigned char                      *pstMemBlk;          /* ������ݵ�ָ�룬������ָ��ṹ��������ڴ� */
}IMM_MEM_STRU;


/* Ϊ�����β�ͬ�汾�Ĳ���, ��IMM_ZC_HEAD_STRU/IMM_ZC_STRU�ŵ�ͷ�ļ��� */
typedef struct sk_buff_head IMM_ZC_HEAD_STRU;

typedef struct sk_buff IMM_ZC_STRU;

typedef void (*IMM_MEM_EVENT_CALLBACK)(unsigned int ulMaxClusterFreeCnt);


/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/

#pragma pack(0)



#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of IMM.h */
