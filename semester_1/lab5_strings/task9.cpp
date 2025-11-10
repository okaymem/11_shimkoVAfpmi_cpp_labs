#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

void swapStrings(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}

int compareStrings(const string& s1, const string& s2) {
    int minLength = s1.length() < s2.length() ? s1.length() : s2.length();

    for (int i = 0; i < minLength; i++) {
        if (s1[i] > s2[i]) return 1;
        if (s1[i] < s2[i]) return -1;
    }

    if (s1.length() > s2.length()) return 1;
    if (s1.length() < s2.length()) return -1;
    return 0;
}

int wordsInString(string str, string delimeters) {
    int amountOfWords = 0;
    bool inWord = false;
    for (int i = 0; i < str.length(); i++) {
        if (delimeters.find(str[i]) != string::npos) {
            inWord = false;
        }
        else if (!inWord) {
            inWord = true;
            amountOfWords++;
        }
    }
    return amountOfWords;
}

void sortLexicographical(string* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compareStrings(arr[j], arr[j + 1]) > 0) {
                swapStrings(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    const string VOWEL_LETTERS = "aeiouy";
    string delimeters = "";
    string str = "";

    cout << "Введите строку разделителей: ";
    getline(cin, delimeters);

    if (delimeters.empty()) {
        cout << "Не введены разделители. Используется пробел по умолчанию.\n";
        delimeters = " ";
    }

    cout << "введите строку: ";
    getline(cin, str);

    if (str.empty()) {
        cout << "введена пустая строка!\n";
        return 1;
    }

    for (int i = 0; i < str.length(); i++) {
        if (VOWEL_LETTERS.find(str[i]) != string::npos) {
            str[i] = toupper(str[i]);
        }
        if (str[i] == ' ') {
            str[i] = '+';
        }
    }

    int arrayLength = wordsInString(str, delimeters);

    if (arrayLength == 0) {
        cout << "В строке не найдено слов\n";
        return 1;
    }

    string* arrWithWords = new string[arrayLength];
    int j = 0;
    int startIndexOfWord = -1;

    for (int i = 0; i < str.length(); i++) {
        if (delimeters.find(str[i]) != string::npos) {
            if (startIndexOfWord != -1) {
                arrWithWords[j] = str.substr(startIndexOfWord, i - startIndexOfWord);
                j++;
                startIndexOfWord = -1;
            }
        }
        else {
            if (startIndexOfWord == -1) {
                startIndexOfWord = i;
            }
            if (i == str.length() - 1 && startIndexOfWord != -1) {
                arrWithWords[j] = str.substr(startIndexOfWord);
                j++;
            }
        }
    }

    cout << "\nСтрока после замен: " << str << "\n";
    cout << "Разделители: " << delimeters << "\n";

    cout << "\nМассив слов до сортировки:\n";
    for (int i = 0; i < arrayLength; i++) {
        cout << i + 1 << ". " << arrWithWords[i] << "\n";
    }

    sortLexicographical(arrWithWords, arrayLength);

    cout << "\nОтсортированный массив слов:\n";
    for (int i = 0; i < arrayLength; i++) {
        cout << i + 1 << ". " << arrWithWords[i] << "\n";
    }

    delete[] arrWithWords;
    return 0;
}
