// BDMsgMailboxData.h
#ifndef LINUXBDMSGAUTH_BDMSGMAILBOXDATA_H
#define LINUXBDMSGAUTH_BDMSGMAILBOXDATA_H

#include "BDMsgBaseData.h"
#include <stdbool.h>

#define MAX_REPLY_TIME (16383 * 60 * 1000L)
#define IDLE_VALUE 1

typedef struct {
    BDMsgBaseData base;
    char* mobile;
    long timestamp;
} BDMsgMailboxData;

// Initialization functions
void BDMsgMailboxData_init(BDMsgMailboxData* data);
void BDMsgMailboxData_initWithParams(BDMsgMailboxData* data, const char* mobile, long timestamp);

// Cleanup function
void BDMsgMailboxData_cleanup(BDMsgMailboxData* data);

// Getters and setters
const char* BDMsgMailboxData_getMobile(const BDMsgMailboxData* data);
void BDMsgMailboxData_setMobile(BDMsgMailboxData* data, const char* mobile);
long BDMsgMailboxData_getTimestamp(const BDMsgMailboxData* data);
void BDMsgMailboxData_setTimestamp(BDMsgMailboxData* data, long timestamp);

// Data assembly
uint8_t* BDMsgMailboxData_assembleDataMsg(BDMsgMailboxData* data, size_t* outLength);

// String representation
char* BDMsgMailboxData_toString(const BDMsgMailboxData* data);

#endif // LINUXBDMSGAUTH_BDMSGMAILBOXDATA_H