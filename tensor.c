#include "tensor.h"
#include <stdlib.h>
#include <math.h>

Tensor createTensor(int rows, int cols, TensorType type) {
    Tensor t;
    t.rows = rows;
    t.cols = cols;
    t.type = type;

    int size = rows * cols;

    switch(type) {
        case TYPE_FLOAT32:
            t.data.f32 = (float*)malloc(sizeof(float) * size);
            break;
        case TYPE_FLOAT16:
            t.data.f16 = (uint16_t*)malloc(sizeof(uint16_t) * size);
            break;
        case TYPE_INT8:
            t.data.i8 = (int8_t*)malloc(sizeof(int8_t) * size);
            break;
    }

    return t;
}

void freeTensor(Tensor *t) {
    switch(t->type) {
        case TYPE_FLOAT32: free(t->data.f32); break;
        case TYPE_FLOAT16: free(t->data.f16); break;
        case TYPE_INT8: free(t->data.i8); break;
    }
}

void fillTensorFloat(Tensor *t, float value) {
    if (t->type != TYPE_FLOAT32) return;

    int size = t->rows * t->cols;
    for(int i = 0; i < size; i++)
        t->data.f32[i] = value;
}

void quantizeToInt8(Tensor *src, Tensor *dst) {
    if (src->type != TYPE_FLOAT32 || dst->type != TYPE_INT8) return;

    int size = src->rows * src->cols;

    float maxVal = 0.0f;
    for(int i = 0; i < size; i++) {
        float val = fabs(src->data.f32[i]);
        if (val > maxVal)
            maxVal = val;
    }

    if (maxVal == 0) maxVal = 1.0f;

    float scale = 127.0f / maxVal;

    for(int i = 0; i < size; i++) {
        dst->data.i8[i] = (int8_t)(src->data.f32[i] * scale);
    }
}