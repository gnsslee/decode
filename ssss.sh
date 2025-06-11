#!/bin/bash

# Function to create directories and files
create_structure() {
    # Create directories
    mkdir -p {bdmsgauth/model,common,smcrypt/{cCalculate,calculatejni},util}

    # bdmsgauth files
    touch bdmsgauth/BDMsgAuthSdk.{c,h}
    
    # bdmsgauth/model files
    files=(
        BDMsgBaseData BDMsgGenericCommonData BDMsgGenericPositionData
        BDMsgMailReplyResponse BDMsgMailboxData BDMsgSMCryptResponse
    )
    for file in "${files[@]}"; do
        touch bdmsgauth/model/"$file".{c,h}
    done

    # common files
    enums=(CompressIndicatorEnum MsgResultCodeEnum MsgTypeEnum)
    for enum in "${enums[@]}"; do
        touch common/"$enum".{c,h}
    done

    # smcrypt/cCalculate files
    touch smcrypt/cCalculate/BDMsgSMCryptManager.{c,h}
    touch smcrypt/cCalculate/calculate_jni.{c,h}
    touch smcrypt/cCalculate/calculation_result.{c,h}

    # smcrypt/calculatejni files
    touch smcrypt/calculatejni/calculation.{c,h}
    touch smcrypt/calculatejni/endian_custom.h
    touch smcrypt/calculatejni/sm{3,4}.{c,h}

    # util files
    utils=(
        BDMsgBitSetUtils BDMsgDataUtil BDMsgLogUtil
        BytesVector StringList
    )
    for util in "${utils[@]}"; do
        touch util/"$util".{c,h}
    done
}

main() {
    echo "Creating directory structure and files..."
    create_structure
    echo "Done! Structure created:"
    tree -d
}

main