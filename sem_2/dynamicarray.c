#include "dynamicarray.h"
#include <stdlib.h>

DynamicArray createArray() {
    DynamicArray array;
    array.capacity = 2;
    array.length = 0;
    array.data = (TElem*)malloc(array.capacity * sizeof(TElem));
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
    return -1;
}

void resize(DynamicArray* array) {
    int newCapacity = array->capacity * 2;
    TElem* newData = (TElem*)malloc(newCapacity * sizeof(TElem));
    for (int i = 0; i < array->length; i++) {
        newData[i] = array->data[i];
    }
    free(array->data);
    array->data = newData;
    array->capacity = newCapacity;
}

void addToEnd(DynamicArray* array, TElem element) {
    if (array->length == array->capacity) {
        resize(array);
    }
    array->data[array->length] = element;
    array->length++;
}

TElem getElem(DynamicArray* array, int pos) {
    return array->data[pos];
}

TElem setElem(DynamicArray* array, TElem element, int pos) {
    TElem oldElement = array->data[pos];
    array->data[pos] = element;
    return oldElement;
}

TElem removeLast(DynamicArray* array) {
    TElem oldElement = array->data[array->length - 1];
    array->length--;
    return oldElement;
}

TElem removeFromPosition(DynamicArray* array, int pos) {
    TElem oldElement = array->data[pos];
    for (int i = pos; i < array->length-1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->length--;
    return oldElement;
}