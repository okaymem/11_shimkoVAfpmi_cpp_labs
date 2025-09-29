#include <iostream>
#include <cmath>
#include <random>
// solve task with usage of
// static arrays 
using std::cin;
using std::cout;

void checkData(){
    if (cin.fail()){
        cout<<"incorrect value";
        std::exit(1);
    }
}

const int maxSizeOfArray = 1000;
int main() {
    bool firstCheck = true;
    double sumOfElements = 0, array[maxSizeOfArray];
    int startOfSumIndex = -1, numberOfNumbersNeeded = -1, 
    randomOrNot = 0, n = 0, maxElementNumber = 0;
    cout<<"Введите длину массива\n";
    cin>>n;
    checkData();
    if (n > maxSizeOfArray){
        cout<<"incorrect value";
        std::exit(1);
    }
    cout<<"Вы хотите написать элементы массива сами?\n"<<"напишите да - 1, нет - 0 ";
    cin>>randomOrNot;
    if (randomOrNot != 0 && randomOrNot != 1){
        cout<<"incorrect value";
        std::exit(1);
    }

    if (randomOrNot == 1){
    cout<<"Введите элементы массива\n";
    for (int i = 0; i < n; i++){
        cin>>array[i];
        checkData();
    }
} else {
    double a, b;
    cout<<"введите диапазон, числа а и b\n";
    cin>>a;
    checkData();
    cin>>b;
    checkData();
    if (a > b){
        cout<<"incorrect value";
        std::exit(1);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(a, b);
    cout<<"ваш массив случайных чисел: \n";
    for (int i = 0; i < n; i++){
        array[i] = dist(gen);
        cout<<array[i]<<"\n";
    }
}
    double maxElement = abs(array[0]);

    for (int i = 0; i < n; i++){
        if (abs(array[i]) >= maxElement){
            maxElement = abs(array[i]);
            maxElementNumber = i + 1;
        }
        if (array[i] > 0 && firstCheck){
            startOfSumIndex = i;
            firstCheck = false;
    } 
}
    if (startOfSumIndex != -1 && startOfSumIndex < n-1) {
    for (int i = startOfSumIndex + 1; i < n; i++){
        sumOfElements+=array[i];
    }
} else {
    sumOfElements = 0;
}
        for (int i = 0; i < n; i++){
        if (array[i] < 11 && array[i] >= 0){
            numberOfNumbersNeeded++;
            double k = array[i];
            for (int j = i; j > numberOfNumbersNeeded; j--){
                array[j] = array[j - 1];
            }
            array[numberOfNumbersNeeded] = k;
        }
    }
        cout<<"отсортированный массив:"<<"\n"; 

     for (int i = 0; i < n; i++){
        cout<<array[i]<<"\n";
     }
    cout<<"maxElementNumber "<<maxElementNumber<<"\n"; 
    cout<<"sumOfElements "<<sumOfElements;
    return 0;

}