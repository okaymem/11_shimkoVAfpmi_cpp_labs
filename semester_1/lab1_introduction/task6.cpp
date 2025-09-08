#include <iostream>

int main() {
    int n;
    int sum=0;
    using std::cout; // будем использовать cout из std
    using std::cin;
    cout << "Введите n\n";
    cin >> n;
    for (int i=1; i<=n; i++) {
        if (i%2!=0){
            sum=sum + i; 
        } 
    }
cout << "Сумма нечетных " << sum<<"\n";
    return 0;
}