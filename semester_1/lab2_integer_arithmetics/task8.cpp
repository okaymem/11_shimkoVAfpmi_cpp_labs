#include <iostream>

int main() {
    using std::cout; 
    using std::cin; 
    int a;
    int b;    
    cout << "Введите a\n";
    cin >> a;
    cout << "Введите b\n";
    cin >> b;
    if (!cin>>a || !cin>>b || a>b){
        cout<<"incorrect value";
        std::exit(1);
    }
    for (int i=a; i<=b; i++){
         bool flag=false;
        for (int k=2; k<i; k++){
            if (i%k==0){
                flag = true;
                break;                
        }
    }
    if (!flag){
        cout<<i<<'\n';
    }
    
}
return 0;
}