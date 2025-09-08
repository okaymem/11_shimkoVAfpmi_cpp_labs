#include <iostream>

int main() {
    int n;
    int sumChet=0;
    int proizNechet=1;
    using std::cout; // будем использовать cout из std
    using std::cin;
    cout << "Введите n\n";
    cin >> n;
    for (int i=1; i<=n; i++) {
        if (i%2==0){
            sumChet=sumChet + i; 
        } else {
            proizNechet=proizNechet*i;
        }

    }
cout << "Сумма четных " << sumChet<<"\n";
cout << "Произведение нечетных " << proizNechet;

    return 0;
}