#include <iostream>
#include <cmath>
const int MAX_LENGTH = 1000;
void swap(int& a, int& b){
    int k = a;
    a = b;
    b = k;
}

void sortBubble(int* arr, int length){
    for (int i = 0; i < length; i++){
        for (int k = 0; k < length - i - 1; k++){ 
            if (abs(arr[k]) > abs(arr[k + 1])){
                swap(arr[k], arr[k + 1]);
            }
        }
    }
    
}
int main(){
int length = 0;
std::cin>>length;    
int* array = new int[MAX_LENGTH];
for (int i = 0; i < length; i++){
    std::cin>>array[i];
}
sortBubble(array, length);
for (int i = 0; i < length; i++){
    std::cout<<array[i]<<"\n";
}
return 0;
}