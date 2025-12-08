#pragma once
#include <initializer_list>
#include <iostream>
class Vector {
private:
    int *arr_ = nullptr;
    int size_ = 0;
    int capacity_ = 0;
public:
    Vector();
    Vector(int size);
    Vector(std::initializer_list<int> list);
    ~Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    void Swap(Vector& other);
    const int& operator[](int index) const;
    int& operator[](int index);
    const int& At(int index) const;
    int& At (int index);
    int Size() const;
    int Capacity() const;
    void PushBack(int value);
    void PopBack();
    void Clear();
    void Reserve(int newCapacity);
    friend std::ostream& operator<<(std::ostream&, const Vector& vec);
};
