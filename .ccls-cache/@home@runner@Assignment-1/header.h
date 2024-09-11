#ifndef ARRAY_MANIPULATOR_H
#define ARRAY_MANIPULATOR_H

#include <iostream>
#include <stdexcept>

const int MAX_SIZE = 100;

class ArrayManipulator {
private:
    int arr[MAX_SIZE];
    int size;

public:
    ArrayManipulator();

    int findIndex(int num);
    std::pair<int, int> modifyValue(int index, int newValue);
    void addInteger(int num);
    void replaceOrRemove(int index, bool remove);
};

#endif // ARRAY_MANIPULATOR_H
