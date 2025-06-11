// BDMsgGenericPositionData.h
#ifndef LINUXBDMSGAUTH_BDMSGGENERICPOSITIONDATA_H
#define LINUXBDMSGAUTH_BDMSGGENERICPOSITIONDATA_H

#include "BDMsgGenericCommonData.h"
#include <stdbool.h>

#define TEXT_MAX_LENGTH 343

typedef struct {
    BDMsgGenericCommonData common;
    double longitude;
    double latitude;
} BDMsgGenericPositionData;

// Initialization functions
void BDMsgGenericPositionData_init(BDMsgGenericPositionData* data);
void BDMsgGenericPositionData_initWithParams(
        BDMsgGenericPositionData* data,
        char** mobileList,
        size_t mobileCount,
        const char* text,
        double longitude,
        double latitude,
        const char* specificBusinessAuthCodeIndicator
);

// Cleanup function
void BDMsgGenericPositionData_cleanup(BDMsgGenericPositionData* data);

// Getters and setters
double BDMsgGenericPositionData_getLongitude(const BDMsgGenericPositionData* data);
long BDMsgGenericPositionData_getLongitudeByLong(const BDMsgGenericPositionData* data);
void BDMsgGenericPositionData_setLongitude(BDMsgGenericPositionData* data, double longitude);
double BDMsgGenericPositionData_getLatitude(const BDMsgGenericPositionData* data);
long BDMsgGenericPositionData_getLatitudeByLong(const BDMsgGenericPositionData* data);
void BDMsgGenericPositionData_setLatitude(BDMsgGenericPositionData* data, double latitude);

// Data assembly
uint8_t* BDMsgGenericPositionData_assembleDataMsg(BDMsgGenericPositionData* data, size_t* outLength);

// String representation
char* BDMsgGenericPositionData_toString(const BDMsgGenericPositionData* data);

#endif //LINUXBDMSGAUTH_BDMSGGENERICPOSITIONDATA_H