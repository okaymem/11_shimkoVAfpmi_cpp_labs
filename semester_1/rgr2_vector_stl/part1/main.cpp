#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int> inputNumbers() {
    std::vector<int> numbers;
    std::cout << "Введите целые числа (для завершения ввода введите любой нечисловой символ):\n";
    
    int num;
    while (std::cin >> num) {
        numbers.push_back(num);
    }
    
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    return numbers;
}

int calculateSum(const std::vector<int>& vec) {
    int sum = 0;
    for (int x : vec) {
        sum += x;
    }
    return sum;
}

int countEqual(const std::vector<int>& vec, int target) {
    int count = 0;
    for (int x : vec) {
        if (x == target) {
            count++;
        }
    }
    return count;
}

int countGreaterThan(const std::vector<int>& vec, int n) {
    int count = 0;
    for (int x : vec) {
        if (x > n) {
            count++;
        }
    }
    return count;
}

void replaceZerosWithAverage(std::vector<int>& vec) {
    if (vec.empty()) return;
    
    int sum = calculateSum(vec);
    int average = sum / static_cast<int>(vec.size());
    
    for (int& x : vec) {
        if (x == 0) {
            x = average;
        }
    }
    
    std::cout << "   Все нули заменены на среднее арифметическое: " << average << std::endl;
}

void addIntervalSumToAll(std::vector<int>& vec, int start_idx, int end_idx) {
    if (start_idx < 0 || end_idx >= vec.size() || start_idx > end_idx) {
        std::cout << "   Неверный интервал, операция пропущена." << std::endl;
        return;
    }
    
    int interval_sum = 0;
    for (int i = start_idx; i <= end_idx; i++) {
        interval_sum += vec[i];
    }
    
    for (int& x : vec) {
        x += interval_sum;
    }
    
    std::cout << "   Сумма интервала [" << start_idx << ", " << end_idx << "]: " << interval_sum << std::endl;
}

void replaceEvenModulusWithDiff(std::vector<int>& vec) {
    if (vec.empty()) return;
    
    int max_val = vec[0];
    int min_val = vec[0];
    
    for (int x : vec) {
        if (x > max_val) max_val = x;
        if (x < min_val) min_val = x;
    }
    
    int diff = max_val - min_val;
    
    for (int& x : vec) {
        if (std::abs(x) % 2 == 0) {
            x = diff;
        }
    }
    
    std::cout << "   Числа с четным модулем заменены на разность (max-min): " << diff << std::endl;
}

std::vector<int> removeDuplicateModulus(const std::vector<int>& vec) {
    std::vector<int> result;
    std::vector<int> seen_mods;
    
    for (int x : vec) {
        int mod = std::abs(x);
        bool found = false;
        
        for (int m : seen_mods) {
            if (m == mod) {
                found = true;
                break;
            }
        }
        
        if (!found) {
            seen_mods.push_back(mod);
            result.push_back(x);
        }
    }
    
    return result;
}

void printVector(const std::vector<int>& vec) {
    
    
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i != vec.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = inputNumbers();
    
    if (numbers.empty()) {
        std::cout << "Вектор пуст. Программа завершена.\n";
        return 0;
    }
    
    std::cout << "\nИсходный вектор: ";
    printVector(numbers);
    
    int sum = calculateSum(numbers);
    std::cout << "\n1. Сумма чисел: " << sum << std::endl;
    
    std::cout << "2. Общее количество чисел: " << numbers.size() << std::endl;
    
    int target;
    std::cout << "\n3. Введите число для подсчета: ";
    std::cin >> target;
    int count_target = countEqual(numbers, target);
    std::cout << "   Количество чисел, равных " << target << ": " << count_target << std::endl;
    
    int n;
    std::cout << "\n4. Введите число n для условия 'больше чем n': ";
    std::cin >> n;
    int count_greater = countGreaterThan(numbers, n);
    std::cout << "   Количество чисел, больших чем " << n << ": " << count_greater << std::endl;
    
    std::cout << "\n5. Замена нулей средним арифметическим:";
    replaceZerosWithAverage(numbers);
    std::cout << "   Вектор после замены: ";
    printVector(numbers);
    
    std::cout << "\n6. Добавление суммы интервала ко всем элементам:" << std::endl;
    int start_idx, end_idx;
    std::cout << "   Введите начальный и конечный индексы интервала (от 0 до " << numbers.size() - 1 << "): ";
    std::cin >> start_idx >> end_idx;
    addIntervalSumToAll(numbers, start_idx, end_idx);
    std::cout << "   Вектор после добавления суммы интервала: ";
    printVector(numbers);
    
    std::cout << "\n7. Замена чисел с четным модулем:";
    replaceEvenModulusWithDiff(numbers);
    std::cout << "   Вектор после замены: ";
    printVector(numbers);
    
    std::cout << "\n8. Удаление равных по модулю чисел:";
    std::vector<int> filtered_numbers = removeDuplicateModulus(numbers);
    std::cout << "\n   Вектор после удаления: ";
    printVector(filtered_numbers);
    
    std::cout << "\nИтоговый вектор: ";
    printVector(filtered_numbers);
    
    return 0;
}