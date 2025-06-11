// BDMsgGenericCommonData.h
#ifndef LINUXBDMSGAUTH_BDMSGGENERICCOMMONDATA_H
#define LINUXBDMSGAUTH_BDMSGGENERICCOMMONDATA_H

#include "BDMsgBaseData.h"
#include <stdbool.h>

#define TEXT_MAX_LENGTH 343

typedef struct {
    BDMsgBaseData base;
    char** mobileList;
    size_t mobileCount;
    char* text;
} BDMsgGenericCommonData;

// 函数声明
void BDMsgGenericCommonData_init(BDMsgGenericCommonData* msg);
void BDMsgGenericCommonData_initWithParams(BDMsgGenericCommonData* msg,
                                           char** mobileList,
                                           size_t mobileCount,
                                           const char* text,
                                           const char* specificBusinessAuthCodeIndicator);
void BDMsgGenericCommonData_cleanup(BDMsgGenericCommonData* msg);

BDMsgGenericCommonData* BDMsgGenericCommonData_create();
BDMsgGenericCommonData* BDMsgGenericCommonData_createWithParams(char** mobileList,
                                                                size_t mobileCount,
                                                                const char* text,
                                                                const char* specificBusinessAuthCodeIndicator);
void BDMsgGenericCommonData_destroy(BDMsgGenericCommonData* msg);

char** BDMsgGenericCommonData_getMobileList(const BDMsgGenericCommonData* msg, size_t* count);
void BDMsgGenericCommonData_setMobileList(BDMsgGenericCommonData* msg, char** mobileList, size_t count);
const char* BDMsgGenericCommonData_getText(const BDMsgGenericCommonData* msg);
void BDMsgGenericCommonData_setText(BDMsgGenericCommonData* msg, const char* text);

uint8_t* BDMsgGenericCommonData_assembleDataMsg(BDMsgGenericCommonData* msg, size_t* outLength);
char* BDMsgGenericCommonData_toString(const BDMsgGenericCommonData* msg);

#endif //LINUXBDMSGAUTH_BDMSGGENERICCOMMONDATA_H