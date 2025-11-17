#include <iostream>
#include <cmath>
#include <random>

using std::cin;
using std::cout;

const int maxSize = 1000;

void checkInput() {
    if (cin.fail()) {
        throw "Invalid input, expected a number";
    }
}

int main() {
    try {
        bool foundPositive = true;
        double sum = 0;
        double arr[maxSize];
        int positiveIndex = -1;
        int countMoved = -1;
        int choice = 0;
        int n = 0;
        int maxIndex = 0;

        cout << "Enter array size: ";
        cin >> n;
        checkInput();
        
        if (n <= 0) {
            throw "Array size must be positive";
        }
        if (n > maxSize) {
            throw "Array size cannot be >1000";
        }

        cout << "Choose input method (1 for manual, 0 for random): ";
        cin >> choice;
        checkInput();
        
        if (choice != 0 && choice != 1) {
            throw "Input method must be 0 or 1";
        }

        if (choice == 1) {
            cout << "Enter " << n << " array elements:\n";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
                checkInput();
            }
        } else {
            double a, b;
            cout << "Enter range start (a): ";
            cin >> a;
            checkInput();
            cout << "Enter range end (b): ";
            cin >> b;
            checkInput();
            
            if (a > b) {
                cout << "Swapping a and b because a > b\n";
                double temp = a;
                a = b;
                b = temp;
            }

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dist(a, b);
            
            cout << "Generated array:\n";
            for (int i = 0; i < n; i++) {
                arr[i] = dist(gen);
                cout << arr[i] << "\n";
            }
        }

        double maxVal = abs(arr[0]);

        for (int i = 0; i < n; i++) {
            if (abs(arr[i]) >= maxVal) {
                maxVal = abs(arr[i]);
                maxIndex = i + 1;
            }
            if (arr[i] > 0 && foundPositive) {
                positiveIndex = i;
                foundPositive = false;
            }
        }

        if (positiveIndex != -1 && positiveIndex < n - 1) {
            for (int i = positiveIndex + 1; i < n; i++) {
                sum += arr[i];
            }
            cout << "Sum of elements after first positive: " << sum << "\n";
        } else {
            sum = 0;
            if (positiveIndex == -1) {
                cout << "No positive elements found - sum cannot be calculated\n";
            } else {
                cout << "First positive is last element, no elements to sum\n";
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] < 11 && arr[i] >= 0) {
                countMoved++;
                double temp = arr[i];
                for (int j = i; j > countMoved; j--) {
                    arr[j] = arr[j - 1];
                }
                arr[countMoved] = temp;
            }
        }

        cout << "Rearranged array:\n";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << "\n";
        }
        
        cout << "Maximum element position: " << maxIndex << "\n";
        cout << "Sum result: " << sum << "\n";

    } catch (const char* error) {
        cout << "Error: " << error << "\n";
        return 1;
    } 
    return 0;
}
