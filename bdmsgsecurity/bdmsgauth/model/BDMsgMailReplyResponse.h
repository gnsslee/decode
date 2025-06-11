#ifndef BDMSGMAILREPLYRESPONSE_H
#define BDMSGMAILREPLYRESPONSE_H

#include <stddef.h>

// BDMsgMailReplyResponse结构体定义
typedef struct {
    int mailboxStatus;      // 信箱状态（0:有回复，1:解密失败，2:无回复）
    int isRemain;           // 是否剩余信箱信息（0:不剩余，1:剩余）
    char *replyMobile;      // 回复手机号码(上一条回复手机号)
    char *mailBoxMsg;       // 信箱消息内容
    char *lastReplyTimeStart;     //上一条回复手机号时间戳  毫秒
} BDMsgMailReplyResponse;

// 创建和销毁函数
BDMsgMailReplyResponse *BDMsgMailReplyResponse_Create(void);

void BDMsgMailReplyResponse_Destroy(BDMsgMailReplyResponse *response);

// 获取和设置函数
int BDMsgMailReplyResponse_GetMailboxStatus(const BDMsgMailReplyResponse *response);

void BDMsgMailReplyResponse_SetMailboxStatus(BDMsgMailReplyResponse *response, int status);

int BDMsgMailReplyResponse_GetIsRemain(const BDMsgMailReplyResponse *response);

void BDMsgMailReplyResponse_SetIsRemain(BDMsgMailReplyResponse *response, int isRemain);

const char *BDMsgMailReplyResponse_GetReplyMobile(const BDMsgMailReplyResponse *response);

void BDMsgMailReplyResponse_SetReplyMobile(BDMsgMailReplyResponse *response,  char *mobile);

const char *BDMsgMailReplyResponse_GetMailBoxMsg(const BDMsgMailReplyResponse *response);

void BDMsgMailReplyResponse_SetMailBoxMsg(BDMsgMailReplyResponse *response,  char *msg);

const char *BDMsgMailReplyResponse_GetLastReplyTimeStart(const BDMsgMailReplyResponse *response);

void BDMsgMailReplyResponse_SetLastReplyTimeStart(BDMsgMailReplyResponse *response, char *lastReplyTimeStart);

#endif // BDMSGMAILREPLYRESPONSE_H