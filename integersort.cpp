// integersort.cpp

#include <iostream>
#include <vector>
#include <algorithm>

void getNumber(std::vector<int> &v) {
    int n;
    std::cout << "Enter your integer: ";
    std::cin >> n;
    std::cout << n << " added successfully.\n";
    v.push_back(n);
}

void showNumber(std::vector<int> &v) {
    int counter = 1;
    for (const auto &i : v) {
        std::cout << "Number #" << counter << ": " << i << "\n";
        counter++;
    }
}

void sortSmallestToLargest(std::vector<int> &v) {
        std::sort(v.begin(), v.end());
}

void sortLargestToSmallest(std::vector<int> &v) {
    std::sort(v.begin(), v.end(), std::greater<int>());
}

void sortInteger(std::vector<int> &v) {
    bool isRunning = true;
    while (isRunning) {
        int choice;
        std::cout << "0. Exit\n1. Largest to Smallest\n2. Smallest to Largest\nChoice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 0: isRunning = false; break;
            case 1: {
                if (v.empty()) {
                    std::cout << "Integer list empty.\n";
                    isRunning = false;
                    std::cout << "Go to: 1: Create integer and then insert a number inside.\n";
                } else {
                    sortLargestToSmallest(v);
                    std::cout << "Successfully sorted!\n";
                }

                break;
            }
            case 2: {
                if (v.empty()) {
                    std::cout << "Integer list empty.\n";
                    isRunning = false;
                    std::cout << "Go to: 1: Create integer and then insert a number inside.\n";
                } else {
                    sortSmallestToLargest(v);
                    std::cout << "Successfully sorted!\n";
                }

                break;
            }
        }
    }
}

int main() {
    std::vector<int> n;
    while (true) {
        int choice;
        std::cout << "0. Exit\n1. Create integer\n2. Show numbers\n3. Sort integer\nChoice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 0: return 0;
            case 1: {
                getNumber(n);
                break;
            }
            case 2: {
                showNumber(n);
                break;
            }
            case 3: {
                sortInteger(n);
                break;
            }
            default: continue;
        }
    }
    return 0;
}

