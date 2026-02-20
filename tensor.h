#ifndef TENSOR_H
#define TENSOR_H

#include <stdint.h>

typedef enum {
    TYPE_FLOAT32,
    TYPE_FLOAT16,
    TYPE_INT8
} TensorType;

typedef struct {
    int rows;
    int cols;
    TensorType type;
    union {
        float *f32;
        uint16_t *f16;
        int8_t *i8;
    } data;
} Tensor;

Tensor createTensor(int rows, int cols, TensorType type);
void freeTensor(Tensor *t);
void fillTensorFloat(Tensor *t, float value);
void quantizeToInt8(Tensor *src, Tensor *dst);

#endif