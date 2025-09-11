#include <iostream>

int main() {
    using std::cout; 
    using std::cin; 
    int k;
    int f=1;
    cout << "Введите k\n";
    cin >> k;
    
    if (k%2==0) {
       for (int i=2; i<=k; i+=2) {
         f*=i;
    } 
    } else {
        for (int i=1; i<=k; i+=2) {
        f*=i;
    } 
    }
    cout<<"factorial: "<<f;
    return 0;
}