#ifndef BYTES_VECTOR_H
#define BYTES_VECTOR_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t* data;  // 字节数组
    size_t length;  // 当前长度
    size_t capacity;// 容量
} BytesVector;

/**
 * 创建空的字节向量
 * @param initialCapacity 初始容量
 * @return 初始化后的字节向量
 */
BytesVector* BytesVector_Create(size_t initialCapacity);

/**
 * 销毁字节向量并释放内存
 * @param vec 字节向量指针
 */
void BytesVector_Destroy(BytesVector* vec);

/**
 * 添加字节到向量
 * @param vec 字节向量指针
 * @param byte 要添加的字节
 * @return 成功返回0，失败返回非0
 */
int BytesVector_Add(BytesVector* vec, uint8_t byte);

/**
 * 添加字节数组到向量
 * @param vec 字节向量指针
 * @param data 字节数组
 * @param length 字节数组长度
 * @return 成功返回0，失败返回非0
 */
int BytesVector_AddBytes(BytesVector* vec, const uint8_t* data, size_t length);

/**
 * 获取向量中的字节
 * @param vec 字节向量指针
 * @param index 索引位置
 * @return 字节值，索引无效时返回0
 */
uint8_t BytesVector_Get(const BytesVector* vec, size_t index);

/**
 * 获取向量长度
 * @param vec 字节向量指针
 * @return 向量长度
 */
size_t BytesVector_Length(const BytesVector* vec);

/**
 * 获取向量数据
 * @param vec 字节向量指针
 * @return 数据指针
 */
const uint8_t* BytesVector_Data(const BytesVector* vec);

/**
 * 清空向量中的所有元素
 * @param vec 字节向量指针
 */
void BytesVector_Clear(BytesVector* vec);

/**
 * 从二进制字符串创建字节向量
 * @param binaryStr 二进制字符串（'0'和'1'组成）
 * @return 创建的字节向量，失败返回NULL
 */
BytesVector* BytesVector_FromBinary(const char* binaryStr);

/**
 * 将字节向量转换为二进制字符串
 * @param vec 字节向量指针
 * @return 二进制字符串，调用者需要free，失败返回NULL
 */
char* BytesVector_ToBinary(const BytesVector* vec);

#endif // BYTES_VECTOR_H