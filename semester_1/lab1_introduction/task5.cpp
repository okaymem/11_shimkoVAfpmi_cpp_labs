#include <iostream>

int main() {
    using std::cout; 
    using std::cin; 
    int n;
    int m;    
    cout << "Введите n\n";
    cin >> n;
    cout << "Введите m\n";
    cin >> m;
    if (m<n) {
       for (int i=1; i<=m; i++) {
        if (m%i==0 and n%i==0 ) {
            cout <<i<<"\n";
        }
    } 
    } else {
        for (int i=1; i<=n; i++) {
        if (m%i==0 and n%i==0 ) {
            cout <<i<<"\n";
        }
    } 
    }
    
    return 0;
}