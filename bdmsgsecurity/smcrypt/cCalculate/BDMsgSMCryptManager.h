#ifndef BDMSGSMCRYPTMANAGER_H
#define BDMSGSMCRYPTMANAGER_H

#include <stddef.h>
#include "../../bdmsgauth/model/BDMsgSMCryptResponse.h"
#include "calculation_result.h"

/**
 * 需要鉴权码的国密加密算法
 *
 * @param keyAndIv 秘钥信息
 * @param keyAndIvLength 秘钥长度
 * @param needEncryptData 需要加密的数据
 * @param dataLength 数据长度
 * @return 加密结果响应
 */
BDMsgSMCryptResponse
encryptBdMsgNeedVerifyCode(const uint8_t *keyAndIv, size_t keyAndIvLength,
                           const uint8_t *needEncryptData,
                           size_t dataLength);

/**
 * 需要鉴权码的国密解密算法
 *
 * @param keyAndIv 秘钥信息
 * @param keyAndIvLength 秘钥长度
 * @param needDecryptData 需要解密的数据
 * @param needDecryptDataLength 需要解密的数据长度
 * @return 解密结果响应
 */
BDMsgSMCryptResponse
decryptBdMsgNeedVerifyCode(const uint8_t *keyAndIv, size_t keyAndIvLength,
                           const uint8_t *needDecryptData,
                           size_t needDecryptDataLength);

/**
 * 不需要鉴权码的国密加密算法
 *
 * @param keyAndIv 秘钥信息
 * @param keyAndIvLength 秘钥长度
 * @param needEncryptData 需要加密的数据
 * @param dataLength 数据长度
 * @return 加密结果响应
 */
BDMsgSMCryptResponse
encryptBdMsgNoNeedVerifyCode(const uint8_t *keyAndIv, size_t keyAndIvLength,
                             const uint8_t *needEncryptData,
                             size_t dataLength);

/**
 * 不需要鉴权码的国密解密算法
 *
 * @param keyAndIv 秘钥信息
 * @param keyAndIvLength 秘钥长度
 * @param needDecryptData 需要解密的数据
 * @param needDecryptDataLength 需要解密的数据长度
 * @return 解密结果响应
 */
BDMsgSMCryptResponse
decryptBdMsgNoNeedVerifyCode(const uint8_t *keyAndIv, size_t keyAndIvLength,
                             const uint8_t *needDecryptData,
                             size_t needDecryptDataLength);


//需要鉴权码国密加密算法
CalculationResult
gatewayUeForEncryptNeedVerifyCode(const uint8_t *keyAndIv, size_t keyAndIvLength, const uint8_t *needEncryptData,
                                  size_t needEncryptDataLength);

//无需鉴权码的解密算法
CalculationResult
ueGatewayForDecryptNoNeedVerifyCode(const uint8_t *keyAndIv, size_t keyAndIvLength,
                                    const uint8_t *needDecryptData,
                                    size_t needDecryptDataLength);

#endif
