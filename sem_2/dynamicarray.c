#include "dynamicarray.h"
#include <stdlib.h>

DynamicArray createArray() {
    DynamicArray array;
    array.capacity = 2;
    array.length = 0;
    array.data = (TElem*)(array.capacity * sizeof(TElem));
    return array;
}

void destroyArray(DynamicArray* array) {
    free(array->data);
}

int size(DynamicArray* array) {
    return array->length;
}

int search(DynamicArray* array, TElem element) {
    for (int i = 0; i < array->length; i++) {
        if (array->data[i] == element) {
            return i;
        }
    }
}

void resize(DynamicArray* array) {

}

void addToEnd(DynamicArray* array, TElem element) {
    if (array->length == array->capacity) {
        resize(array);
    }
}