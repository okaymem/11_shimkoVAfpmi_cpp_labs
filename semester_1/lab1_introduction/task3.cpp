#include <iostream>

int elementOfSum(int i) {
    int element=1;
    for (int k=1; k<=i; k++) {
        element = element * i; //вычисляем i^i, что является огромным значением, при n=100, и переполняем тип int
    }
    return element;
} 

int main() {
    int n;
    int sum=0;
    using std::cout; // будем использовать cout из std
    using std::cin;
    cout << "Введите n\n";
    cin >> n;
    for (int i=1; i<=n; i++) {
        sum = sum + elementOfSum(i);
    }
cout << "Сумма " << sum<<"\n";

    return 0;
}