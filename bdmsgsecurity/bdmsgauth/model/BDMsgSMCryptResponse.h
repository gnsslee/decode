// BDMsgSMCryptResponse.h
#ifndef LINUXBDMSGAUTH_BDMSGSMCRYPTRESPONSE_H
#define LINUXBDMSGAUTH_BDMSGSMCRYPTRESPONSE_H

#include <stdlib.h>
#include <string.h>

typedef struct {
    int code;               // 约定返回码，1000(表示成功) 非1000等表示失败
    char* msg;              // 状态码对应的描述信息
    unsigned char* data;    // 数据
    int len;                // 数据长度(应用层实际长度)
    size_t data_capacity;   // 数据缓冲区容量(内部使用)
} BDMsgSMCryptResponse;

// 初始化函数
void BDMsgSMCryptResponse_init(BDMsgSMCryptResponse* response);

// 清理函数
void BDMsgSMCryptResponse_cleanup(BDMsgSMCryptResponse* response);

// 获取返回码
int BDMsgSMCryptResponse_getCode(const BDMsgSMCryptResponse* response);

// 设置返回码
void BDMsgSMCryptResponse_setCode(BDMsgSMCryptResponse* response, int code);

// 获取消息
const char* BDMsgSMCryptResponse_getMsg(const BDMsgSMCryptResponse* response);

// 设置消息
void BDMsgSMCryptResponse_setMsg(BDMsgSMCryptResponse* response, const char* msg);

// 获取数据
const unsigned char* BDMsgSMCryptResponse_getData(const BDMsgSMCryptResponse* response, int* len);

// 设置数据
void BDMsgSMCryptResponse_setData(BDMsgSMCryptResponse* response, const unsigned char* data, int len);

//// 获取数据长度
//int BDMsgSMCryptResponse_getLen(const BDMsgSMCryptResponse* response);

// 设置数据长度
void BDMsgSMCryptResponse_setLen(BDMsgSMCryptResponse* response, int len);

BDMsgSMCryptResponse* BDMsgSMCryptResponse_create();

#endif // LINUXBDMSGAUTH_BDMSGSMCRYPTRESPONSE_H