#include <iostream>
#include <random>
using std::cout;
using std::cin;
void makeMatrix(int**& matrix, int rows, int cols){
    matrix = new int*[rows];
    for (int i = 0; i < rows; i++){
        matrix[i] = new int[cols];
    }
}
void checkData(){
    if (cin.fail()){
        cout<<"incorrect value";
        std::exit(1);
    }
}
int main() {
    int numberOfTheFirstRowWithTheLongestChain = 1;
    int amountOfColsWithoutZero = 0;
    int** matrix = nullptr;
    int randomOrNot = 0;
    int rows = 0;
    int cols = 0;
    cout<<"введите количество строк матрицы\n";
    cin>>rows;
    cout<<"введите количество столбцов матрицы\n";
    cin>>cols;
    makeMatrix(matrix, rows, cols);
    cout<<"Вы хотите написать элементы массива сами?\n"<<"напишите да - 1, нет - 0 ";
    cin>>randomOrNot;
    if (randomOrNot != 0 && randomOrNot != 1){
        cout<<"incorrect value";
        std::exit(1);
    }

    if (randomOrNot == 1){
    cout<<"Введите элементы матрицы\n";
    for (int i = 0; i < rows; i++){
        for (int k = 0; k < cols; k++){
            cin>>matrix[i][k];
            checkData();
        }
    }
     for (int i = 0; i < rows; i++){
        for (int k = 0; k < cols; k++){
            if (-1 < matrix[i][k] && matrix[i][k] < 10){
            cout<<" "<<matrix[i][k]<<" ";
            } else {
            cout<<matrix[i][k]<<" ";
            }
        }
        cout<<"\n";
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
    std::uniform_int_distribution<int> dist(a, b);
    cout<<"ваша матрица случайных чисел: \n";
    for (int i = 0; i < rows; i++){
        for (int k = 0; k < cols; k++){
            matrix[i][k] = dist(gen);
            checkData();
            if (-1 < matrix[i][k] && matrix[i][k] < 10){
            cout<<" "<<matrix[i][k]<<" ";
            } else {
            cout<<matrix[i][k]<<" ";
            }
        }
        cout<<"\n";
    }
}
for (int i = 0; i < cols; i++){
    int colWithZero = false;
    for (int k = 0; k < rows; k++){
        if (matrix[k][i] == 0){
            colWithZero = true;
        }
    }
    if (!colWithZero){
    amountOfColsWithoutZero++;
    }

}
int maxLengthInMatrix = 1;
for (int i = 0; i < rows; i++){
    int intermediateLength = 1;
    int maxLengthInRow = 1;
    for (int k = 1; k < cols; k++){
        
        if (matrix[i][k] > matrix[i][k-1]){
            intermediateLength++;
            if (k == cols - 1 && intermediateLength > maxLengthInRow){
                maxLengthInRow = intermediateLength;
            }
        } else if (intermediateLength > maxLengthInRow){
            maxLengthInRow = intermediateLength;
            intermediateLength = 1;
        } else {
            intermediateLength = 1;
        }
    }
    if (maxLengthInRow > maxLengthInMatrix){
        maxLengthInMatrix = maxLengthInRow;
        numberOfTheFirstRowWithTheLongestChain = i + 1;
    }
}
cout<<"количество столбцов без нулей: "<<amountOfColsWithoutZero<<"\n";
cout<<"номер первой из строк в которой содержится самая длинная строго возрастающая последовательность элементов: "<<numberOfTheFirstRowWithTheLongestChain<<"\n";
cout<<"длина этой последовательности "<<maxLengthInMatrix<<"\n";

}