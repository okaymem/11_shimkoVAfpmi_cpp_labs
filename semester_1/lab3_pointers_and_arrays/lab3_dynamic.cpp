#include <iostream>
#include <cmath>
#include <random>
using std::cin;
using std::cout;

void checkData(){
    if (cin.fail()){
        cout << "incorrect value";
        std::exit(1);
    }
}

void swap(int& a, int& b){
    int k = a;
    a = b;
    b = k;
}

void sortArray(int* arr, int n){
    for (int i = 0; i < n - 2; i = i + 2){
        for (int k = 0; k < n - i - 2; k = k + 2){ 
            if (arr[k] > arr[k + 2]){
                swap(arr[k], arr[k + 2]);
            }
        }
    }
    for (int i = 1; i < n - 1; i = i + 2){
        for (int k = 1; k < n - i - 1; k = k + 2){ 
            if (arr[k] > arr[k + 2]){
                swap(arr[k], arr[k + 2]);
            }
        }
    }
}

int main() {
    int randomOrNot = 0, n = 0;
    int lengthOfMaxChain = 1;
    bool isFirst0 = true;
    int indexOfFirst0 = -1; 
    int indexOfLast0 = -1;
    int sumOfEl = 0;
    
    cout << "Введите длину массива\n";
    cin >> n;
    checkData();
    
    int* array = new int[n];
    
    cout << "Вы хотите написать элементы массива сами?\n" << "напишите да - 1, нет - 0 ";
    cin >> randomOrNot;
    if (randomOrNot != 0 && randomOrNot != 1){
        cout << "incorrect value";
        delete[] array;
        std::exit(1);
    }

    if (randomOrNot == 1){
        cout << "Введите элементы массива\n";
        for (int i = 0; i < n; i++){
            cin >> array[i];
            checkData();
        }
    } else {
        double a, b;
        cout << "введите диапазон, числа а и b\n";
        cin >> a;
        checkData();
        cin >> b;
        checkData();
        if (a > b){
            cout << "incorrect value";
            delete[] array;
            std::exit(1);
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(a, b);
        cout << "ваш массив случайных чисел: \n";
        for (int i = 0; i < n; i++){
            array[i] = dist(gen);
            cout << array[i] << "\n";
        }
    }

    int startIndex = 0;
    int indexEnd = 0;
    int start = 0;

    for (int i = 0; i < n; i++){
        for (int k = startIndex; k < i; k++){
            if (array[k] == array[i]){
                if (i - startIndex > lengthOfMaxChain){
                    lengthOfMaxChain = i - startIndex;
                    indexEnd = i - 1;
                    start = startIndex;
                }
                startIndex = k + 1;
            } 
        }
        if (i - startIndex + 1 > lengthOfMaxChain && i == n - 1){
            lengthOfMaxChain = i - startIndex + 1;
            indexEnd = i;
            start = startIndex;
        }
    }
    
    cout << "length of max chain: ";
    cout << lengthOfMaxChain << "\n";
    cout << "chain of unique elements:\n";
    for (int i = start; i <= indexEnd; i++){
        cout << array[i] << "\n";
    }

    for (int i = 0; i < n; i++){
        if (isFirst0 && array[i] == 0){
            indexOfFirst0 = i;
            isFirst0 = false;
        }
        if (array[i] == 0){
            indexOfLast0 = i;
        }
    }
    
    if (indexOfFirst0 != -1 && indexOfFirst0 != indexOfLast0){
        cout << "сумма элементов между первым и последним нулем:\n";
        for (int i = indexOfFirst0 + 1; i < indexOfLast0; i++){
            sumOfEl += array[i];
        }
        cout << sumOfEl << "\n";
    } else {
        cout << "в массиве нет нулей или есть только один ноль\n";
    }

    sortArray(array, n);
    cout << "sorted array:\n";
    for (int i = 0; i < n; i++){
        cout << array[i] << "\n";
    }
    
    delete[] array;
    return 0;
}