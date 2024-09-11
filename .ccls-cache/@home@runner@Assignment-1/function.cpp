#include "ArrayHeader.h"

// Constructor
ArrayUser::ArrayUser() : size(0) {}

//Function for checking if a specific number exists in the array.
int ArrayUser::findIndex(int num) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1; // Return -1 if the number is not found
}

// Function for changing the value of an integer at a given index.
std::pair<int, int> ArrayUser::modifyValue(int index, int newValue) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }

    int oldValue = arr[index];
    arr[index] = newValue;

    return {newValue, oldValue};
}

// Function that adds a new integer at the end of the array.
void ArrayUser::addInteger(int num) {
    if (size < max_value) {
        arr[size++] = num;
    } else {
        throw std::overflow_error("Array is full, cannot add more elements");
    }
}

// Function to replace the value at a given index with 0 or remove the number completely.
void ArrayUser::replaceOrRemove(int index, bool remove) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }

    if (remove) {
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size;
    } else {
        arr[index] = 0;
    }
}
