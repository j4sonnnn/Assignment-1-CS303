#include "ArrayHeader.h"
#include <fstream>

int main() {
    ArrayUser arrayValue;
    std::ifstream inputFile("input.txt");

    if (!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    
    int num;
    while (inputFile >> num) {
        arrayValue.addInt(num);
    }

    inputFile.close();

    
    try {
        int searchNum;
        std::cout << "Enter a number to look up in the array: ";
        std::cin >> searchNum;

        int index = arrayValue.LookupIndex(searchNum);

        if (index != -1) {
            std::cout << "Number/VALUE found at index: " << index << std::endl;
        } else {
            std::cout << "Number?VALUE not found in the array." << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Function that modifies the value of an integer at a given index.
    try {
        int modifyIndex, newValue;
        std::cout << "Enter index and new value to modify: ";
        std::cin >> modifyIndex >> newValue;

        auto result = arrayValue.modifyValue(modifyIndex, newValue);

        std::cout << "Modified value at index " << modifyIndex << ": "
                  << "Old Value: " << result.second << ", New Value: " << result.first << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Function that adds a new integer at the end of the array.
    try {
        int addNum;
        std::cout << "Enter a number to add to the end of the array: ";
        std::cin >> addNum;

        arrayValue.addInt(addNum);

        std::cout << "Number added to the end of the array." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Function to replace the value at a given index with 0 or remove the number entirely.
    try {
        int replaceIndex;
        char choice;
        std::cout << "Enter index to replace/remove and 'r' to replace, 'd' to remove: ";
        std::cin >> replaceIndex >> choice;

        bool remove = (choice == 'd' || choice == 'D');

        arrayValue.ReplaceOrRemove(replaceIndex, remove);

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
