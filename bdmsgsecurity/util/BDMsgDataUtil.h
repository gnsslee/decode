#ifndef BDMSGDATAUTIL_H
#define BDMSGDATAUTIL_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

//字符串工具函数
bool *BDMsgDataUtil_IsEmptyStr(const char *str);

char *BDMsgDataUtil_Base64Encode(const uint8_t *data, size_t length);

uint8_t *BDMsgDataUtil_Base64Decode(const char *encoded, size_t *out_length);

char *BDMsgDataUtil_ByteArrayToHexStr(const uint8_t *data, size_t length);

unsigned char *BDMsgDataUtil_HexStrToByteArray(const char *hex_str, size_t *out_len);

unsigned char hex_char_to_value(char c);

char *BDMsgDataUtil_GBKBytesToUtf8Str(const uint8_t *data, size_t length);

uint8_t *BDMsgDataUtil_Utf8StrToGBKBytes(char *str);

long long BDMsgDataUtil_CurrentTimeMillis(void);

char *BDMsgDataUtil_GetTimeFormatMS(void);

//将毫秒级时间戳转换为字符串
char *BDMsgDataUtil_millisToString(long long millis);

//将毫秒级时间戳字符串格式化为 "%Y-%m-%d %H:%M:%S" 格式的日期时间字符串
char* BDMsgDataUtil_formatTimestamp(const char* timestampStr);




#endif