#ifndef ARRAY_USER
#define ARRAY_USER

#include <iostream>
#include <stdexcept>

const int max_value = 800;

class ArrayUser {
private:
    int arr[max_value];
    int size;

public:
    ArrayUser();

    int LookupIndex(int num);
    std::pair<int, int> modifyValue(int index, int newValue);
    void addInt(int num);
    void ReplaceOrRemove(int index, bool remove);
};

#endif 
