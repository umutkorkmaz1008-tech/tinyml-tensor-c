#include <stdio.h>
#include "tensor.h"

int main() {
    Tensor a = createTensor(2, 2, TYPE_FLOAT32);
    fillTensorFloat(&a, 3.14f);

    Tensor q = createTensor(2, 2, TYPE_INT8);
    quantizeToInt8(&a, &q);

    printf("Quantized Tensor:\n");
    for(int i = 0; i < 4; i++)
        printf("%d ", q.data.i8[i]);

    freeTensor(&a);
    freeTensor(&q);
    return 0;
}