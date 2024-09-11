#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;

class ArrayManipulator {
private:
    int arr[MAX_SIZE];
    int size;

public:
    ArrayManipulator() : size(0) {}

    // Function to check if a certain integer exists in the array
    int findIndex(int num) {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == num) {
                return i;
            }
        }
        return -1; // Return -1 if the number is not found
    }

    // Function to modify the value of an integer at a specific index
    std::pair<int, int> modifyValue(int index, int newValue) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }

        int oldValue = arr[index];
        arr[index] = newValue;

        return {newValue, oldValue};
    }

    // Function to add a new integer to the end of the array
    void addInteger(int num) {
        if (size < MAX_SIZE) {
            arr[size++] = num;
        } else {
            throw std::overflow_error("Array is full, cannot add more elements");
        }
    }

    // Function to replace the value at a specific index with 0 or remove the integer altogether
    void replaceOrRemove(int index, bool remove) {
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
};

int main() {
    ArrayManipulator arrayManipulator;
    std::ifstream inputFile("input.txt");

    if (!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    // Reading data from the input file into the array
    int num;
    while (inputFile >> num) {
        arrayManipulator.addInteger(num);
    }

    inputFile.close();

    // Function to check if a certain integer exists in the array
    try {
        int searchNum;
        std::cout << "Enter a number to search in the array: ";
        std::cin >> searchNum;

        int index = arrayManipulator.findIndex(searchNum);

        if (index != -1) {
            std::cout << "Number found at index: " << index << std::endl;
        } else {
            std::cout << "Number not found in the array." << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Function to modify the value of an integer at a specific index
    try {
        int modifyIndex, newValue;
        std::cout << "Enter index and new value to modify: ";
        std::cin >> modifyIndex >> newValue;

        auto result = arrayManipulator.modifyValue(modifyIndex, newValue);

        std::cout << "Modified value at index " << modifyIndex << ": "
                  << "Old Value: " << result.second << ", New Value: " << result.first << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Function to add a new integer to the end of the array
    try {
        int addNum;
        std::cout << "Enter a number to add to the end of the array: ";
        std::cin >> addNum;

        arrayManipulator.addInteger(addNum);

        std::cout << "Number added to the end of the array." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Function to replace the value at a specific index with 0 or remove the integer altogether
    try {
        int replaceIndex;
        char choice;
        std::cout << "Enter index to replace/remove and 'r' to replace, 'd' to remove: ";
        std::cin >> replaceIndex >> choice;

        bool remove = (choice == 'd' || choice == 'D');

        arrayManipulator.replaceOrRemove(replaceIndex, remove);

        if (remove) {
            std::cout << "Number removed from the array." << std::endl;
        } else {
            std::cout << "Value at index replaced with 0." << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}