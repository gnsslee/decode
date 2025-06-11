#include "./bdmsgauth/BDMsgAuthSdk.h"
#include "./util/BDMsgDataUtil.h"
#include "./util/BDMsgLogUtil.h"
#include "./smcrypt/cCalculate/BDMsgSMCryptManager.h"

void printBDMsgMailReplyResponse(BDMsgMailReplyResponse *response);

//测试入口界面
int main() {

   //待加密的数据
   char *plainText = "泛终端加密测试";

   uint8_t *plainTextBytes = BDMsgDataUtil_Utf8StrToGBKBytes(plainText);
   int dataLength = strlen((const char *) plainTextBytes);

   BDMsgLogUtil_printInfo("原始数据:", plainText);

   char *hexdata = BDMsgDataUtil_ByteArrayToHexStr(BDMsgDataUtil_Utf8StrToGBKBytes(plainText), dataLength);
   BDMsgLogUtil_printInfo("hexdata", hexdata);

   const char *key_hex_str = "891C400E5A577922A2740750422F98F13F6EB10369DEB628E9FB585F72FFEEF1";
   size_t key_len;

   // 转换十六进制字符串为字节数组
   unsigned char *keyAndIv = BDMsgDataUtil_HexStrToByteArray(key_hex_str, &key_len);
   if (!keyAndIv) {
       return 1;
   }

   //使用需要鉴权码的加密方法
   BDMsgSMCryptResponse encryptResponse = encryptBdMsgNeedVerifyCode(
           keyAndIv, key_len, plainTextBytes, dataLength
   );
   //打印长度
   char buffer[20];
   snprintf(buffer, sizeof(buffer), "%d", encryptResponse.len);
   //打印内容
   char *encryptedHex = BDMsgDataUtil_ByteArrayToHexStr(encryptResponse.data, encryptResponse.len / 8);
   BDMsgLogUtil_printInfo("加密后的数据(HEX): %s\n", encryptedHex);


//    //解密
//    const char *data_hex_str = "899CCBD65963A58B708E469E93C6";
//    size_t decrypt_data_len = 112 / 8;
//    unsigned char *data_hex_str_bytes = BDMsgDataUtil_HexStrToByteArray(data_hex_str, &decrypt_data_len);
//
//    //使用无鉴权码解密方法
//    BDMsgSMCryptResponse decryptResponse = decryptBdMsgNoNeedVerifyCode(keyAndIv, key_len, data_hex_str_bytes,
//                                                                        decrypt_data_len);
//
//    //打印内容
//    char *decryptStr = BDMsgDataUtil_GBKBytesToUtf8Str(decryptResponse.data, decryptResponse.len / 8);
//    BDMsgLogUtil_printInfo("解密后的数据:", decryptStr);



    //todo android 同样的数据 编码得到的16进制字符串 通用报文
    // 编码后的结果 F504499B4C583DFA1F52FD4CF5E2C8CDB9A8BC5D645FACD73E55FEA43454F1057B20639B0E7AD81DFF2C8FAA56
    // 长度 360
    /**
    * 密钥：F0E33601A5871A77868923BC4E54E54BC4ED4EFA6AFE1063007A001820BEAFF4
       IMSI：460023914893671
**/

//    const char *key_hex_str = "F0E33601A5871A77868923BC4E54E54BC4ED4EFA6AFE1063007A001820BEAFF4";
//
//    size_t key_len;
//
//    //转换十六进制字符串为字节数组
//    unsigned char *keyAndIv = BDMsgDataUtil_HexStrToByteArray(key_hex_str, &key_len);
//    if (!keyAndIv) {
//        return 1;
//    }
//
//    // 创建并初始化字符串列表
//    StringList *receiveMobileList = StringList_Create(1);
//    if (!receiveMobileList) {
//        // 处理内存分配失败
//        return -1;
//    }
//
//    // 添加手机号
//    if (StringList_Add(receiveMobileList, "13761048108") != 0) {
//        // 处理添加失败
//        StringList_Destroy(receiveMobileList);
//        return -1;
//    }
//
//
//    char *inputMsgByUser = "泛终端rtos北斗短报文消息通用报文发送";
//    BDMsgSMCryptResponse commonResult = BDMsgAuthSdk_commonMessageEncryptBDMsgByGeneric(keyAndIv,
//                                                                                        key_len,
//                                                                                        receiveMobileList,
//                                                                                        inputMsgByUser, "0001");
//    int len = 0;
//
//    BDMsgLogUtil_d("commonResultHexStr",
//                           "commonResultHexStr:%s", BDMsgDataUtil_ByteArrayToHexStr(
//                    BDMsgSMCryptResponse_getData(&commonResult, &len), commonResult.len / 8));
//
//    printf("长度: %d", commonResult.len);


////位置信息上传编码
////编码后的结果 F5449A78C0C41933F5A4B71EA6958D0401A54326542CE623A9417C59DC70C97391E33042CB850730CFF90E916AC1CA01F924C4
////长度 408
    /**位置信息上传编码
      * 密钥：F0E33601A5871A77868923BC4E54E54BC4ED4EFA6AFE1063007A001820BEAFF4
        IMSI：460023914893671
**/

//    const char *key_hex_str = "F0E33601A5871A77868923BC4E54E54BC4ED4EFA6AFE1063007A001820BEAFF4";
//
//    size_t key_len;
//
//    //转换十六进制字符串为字节数组
//    unsigned char *keyAndIv = BDMsgDataUtil_HexStrToByteArray(key_hex_str, &key_len);
//    if (!keyAndIv) {
//        return 1;
//    }
//
//    // 创建并初始化字符串列表
//    StringList *receiveMobileList = StringList_Create(1);
//    if (!receiveMobileList) {
//        // 处理内存分配失败
//        return -1;
//    }
//
//    // 添加手机号
//    if (StringList_Add(receiveMobileList, "13761048108") != 0) {
//        // 处理添加失败
//        StringList_Destroy(receiveMobileList);
//        return -1;
//    }
//
//    char *inputMsgByUser = "泛终端rtos北斗短报文消息通用报文发送";
//
//    double longitude = 121.628082;
//    double latitude = 31.259;
//    BDMsgSMCryptResponse positionResult = BDMsgAuthSdk_positionReportEncryptBDMsgByGeneric(keyAndIv,
//                                                                                           key_len,
//                                                                                           receiveMobileList,
//                                                                                           inputMsgByUser,
//                                                                                           longitude, latitude,
//                                                                                           "0001");
//    int len = 0;
//    BDMsgLogUtil_d("positionResultHexStr",
//                   "positionResultHexStr: %s", BDMsgDataUtil_ByteArrayToHexStr(
//                    BDMsgSMCryptResponse_getData(&positionResult, &len), positionResult.len / 8));
//    BDMsgLogUtil_d("positionResultLen",
//                   "positionResultLen: %d", positionResult.len);



    //邮箱查询组装及加密
    /**
    * 密钥：F0E33601A5871A77868923BC4E54E54BC4ED4EFA6AFE1063007A001820BEAFF4
       IMSI：460023914893671
**/

    //编码后的结果 C4B45227
    //长度 32    上一条回复手机号"1"  上一条回复时间start"1"

//    const char *key_hex_str = "F0E33601A5871A77868923BC4E54E54BC4ED4EFA6AFE1063007A001820BEAFF4";
//
//    size_t key_len;
//
//    //转换十六进制字符串为字节数组
//    unsigned char *keyAndIv = BDMsgDataUtil_HexStrToByteArray(key_hex_str, &key_len);
//    if (!keyAndIv) {
//        return 1;
//    }
//
//    BDMsgSMCryptResponse mailboxQueryResult = BDMsgAuthSdk_mailboxQueryEncryptBDMsg(keyAndIv, key_len, "1", "1");
//    int len = 0;
//    BDMsgLogUtil_d("positionResultHexStr",
//                   "positionResultHexStr: %s", BDMsgDataUtil_ByteArrayToHexStr(
//                    BDMsgSMCryptResponse_getData(&mailboxQueryResult, &len), mailboxQueryResult.len / 8));
//    BDMsgLogUtil_d("positionResultLen",
//                   "positionResultLen: %d", mailboxQueryResult.len);

    /**
 * 信箱下行解密
    密钥：B7B5B43A60959F427337812AF8AAD6624A23F712AD1B198324A68E0B645B248E
    IMSI：460028051962199
    6013 应用层：3aaa62e4a20a1b6a7c09804f6f060c64bd00
    解密解码后的结果 {mailboxStatus='0', isRemain='0', replyMobile='18602527817', mailBoxMsg='已安全到达八'}
 */
//    const char *key_hex_str = "B7B5B43A60959F427337812AF8AAD6624A23F712AD1B198324A68E0B645B248E";
//    size_t key_len;

    //转换十六进制字符串为字节数组
//    unsigned char *keyAndIv = BDMsgDataUtil_HexStrToByteArray(key_hex_str, &key_len);
//    if (!keyAndIv) {
//        return 1;
//    }
//    const char *data_hex_str = "3aaa62e4a20a1b6a7c09804f6f060c64bd00";
//    size_t data_len;
//    unsigned char *mailboxReplyNeedDecryptData = BDMsgDataUtil_HexStrToByteArray(data_hex_str, &data_len);
//    BytesVector *mailboxReplyNeedDecryptBytesVector = BytesVector_Create(data_len);
//    mailboxReplyNeedDecryptBytesVector->data = mailboxReplyNeedDecryptData;
//    mailboxReplyNeedDecryptBytesVector->length = data_len;
//
//    BDMsgMailReplyResponse *msgMailReplyResponse = BDMsgAuthSdk_mailboxReplyDecryptBDMsg(keyAndIv, key_len,
//                                                                                         mailboxReplyNeedDecryptBytesVector,
//                                                                                         138);
//
//    printBDMsgMailReplyResponse(msgMailReplyResponse);

}

void printBDMsgMailReplyResponse(BDMsgMailReplyResponse *response) {
    if (response == NULL) {
        printf("Error: NULL response pointer\n");
        return;
    }

    //打印信箱状态
    printf("信箱状态: %d", response->mailboxStatus);
    printf("\n");

    //打印是否剩余信箱信息
    printf("是否剩余信箱信息: %d", response->isRemain);
    printf("\n");

    //打印回复手机号码
    printf("回复手机号码: %s",
           response->replyMobile ? response->replyMobile : "NULL");
    printf("\n");

    //打印信箱消息内容（最多显示前100个字符）
    printf("信箱消息内容: ");
    if (response->mailBoxMsg) {
        size_t len = strlen(response->mailBoxMsg);
        if (len > 100) {
            printf("%.100s... (消息截断，实际长度: %zu)\n",
                   response->mailBoxMsg, len);
        } else {
            printf("%s\n", response->mailBoxMsg);
        }
    } else {
        printf("NULL\n");
    }

    //打印上一条回复时间戳
    printf("上一条回复时间戳: %s\n", response->lastReplyTimeStart);
    char *formattedTime = BDMsgDataUtil_formatTimestamp(response->lastReplyTimeStart);
    printf("格式化后的上一条回复时间戳日期时间: %s\n", formattedTime);
}



