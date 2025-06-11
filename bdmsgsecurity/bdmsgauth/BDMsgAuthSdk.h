#ifndef BDMSGAUTHSDK_H
#define BDMSGAUTHSDK_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "model/BDMsgSMCryptResponse.h"
#include "model/BDMsgMailReplyResponse.h"
#include "../util/StringList.h"
#include "../util/BytesVector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
     * 通用报文 文字数据组装并加密接口(码流拼接)
     * 业务类型指示：纯文字 通用报文 000（0）
     *
     * @param keyAndIv 秘钥信息 字节数组
     * @param keyAndIvLength 秘钥长度 bit单位
     * @param receiveMobileList 收方号码集合
     * @param inputMsgByUser 用户发送的信息
     * @param specificAuthCodeStr 特殊业务鉴权码
     * @return
     */
BDMsgSMCryptResponse BDMsgAuthSdk_commonMessageEncryptBDMsgByGeneric(
        const uint8_t *keyAndIv,
        size_t keyAndIvLength,
        const StringList *receiveMobileList,
        const char *inputMsgByUser,
        const char *specificAuthCodeStr
);

/**
    * 位置信息上报报文组装并加密接口(码流拼接)
    * @param keyAndIv 秘钥信息
    * @param keyAndIvLength 秘钥长度
    * @param receiveMobileList 收方号码集合
    * @param inputMsgByUser    用户发送的信息
    * @param longitude         经度
    * @param latitude          纬度
    * @param specificAuthCodeStr 特殊业务鉴权码
    * @return BDMsgSMCryptResponse 加密后的位置上报报文数据
   */
BDMsgSMCryptResponse BDMsgAuthSdk_positionReportEncryptBDMsgByGeneric(
        const uint8_t *keyAndIv,
        size_t keyAndIvLength,
        const StringList *receiveMobileList,
        const char *inputMsgByUser,
        double longitude,
        double latitude,
        const char *specificAuthCodeStr
);

/**
  * 普通短信应用渠道 信箱查询报文组装并加密接口(码流拼接)
   * @param keyAndIv 秘钥信息
   * @param keyAndIvLength 秘钥长度
   * @param lastReplyMobile 上一条回复手机号
   * @param lastReplyTimeStart 上一条回复时间
   * @return BDMsgSMCryptResponse 加密后的信箱查询报文数据
  */
BDMsgSMCryptResponse
BDMsgAuthSdk_mailboxQueryEncryptBDMsg(const uint8_t *keyAndIv,
                                      size_t keyAndIvLength,
                                      char *lastReplyMobile,
                                      char *lastReplyTimeStart);

/**
     * 业务类型为信箱回复的应用层报文解密并解析(6013)
     * @param keyAndIv 秘钥信息
     * @param keyAndIvLength 秘钥长度
     * @param mailboxReplyNeedDecryptData 待解密解析的信箱数据
     * @param mailboxReplyRealBitLength 待解密解析的信箱数据真实bit位长度(不包含补0)
     * @return 解密解析后返回的信箱数据 包含上一条回复手机号+时间，由外部自行存储
     */
BDMsgMailReplyResponse *BDMsgAuthSdk_mailboxReplyDecryptBDMsg(
        const uint8_t *keyAndIv, size_t keyAndIvLength,
        const BytesVector *mailboxReplyNeedDecryptData,
        size_t mailboxReplyRealBitLength
);

#ifdef __cplusplus
}
#endif

#endif