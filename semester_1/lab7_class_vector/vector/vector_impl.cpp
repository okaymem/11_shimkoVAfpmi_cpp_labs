#include "vector_impl.h"
#include <iostream>

    Vector::Vector(): arr_(nullptr), size_(0), capacity_(0){}

    Vector::Vector(int Size) : size_(std::max(0, Size)), capacity_(size_){
    if (size_ > 0) {
        arr_ = new int[size_]();
    }
    }

    Vector::Vector(std::initializer_list<int> list)
    : size_(list.size()), capacity_(list.size()), arr_(new int[size_]){
        int i = 0;
      for (int item: list){
         arr_[i++] = item;
      }
    }

    Vector::~Vector(){
        delete[] arr_;
    }

    Vector::Vector(const Vector& other)
    : size_(other.size_), capacity_(other.capacity_), arr_(nullptr) {
    if (capacity_ > 0) {
        arr_ = new int[capacity_];
        std::copy(other.arr_, other.arr_ + size_, arr_);
    }
}
    Vector& Vector::operator=(const Vector& other){
        if (this == &other){
            return *this;
        }
        Vector copy(other);
        Swap(copy);
        return *this;
    }
    void Vector::Swap(Vector& other){
        std::swap(size_, other.size_);
        std::swap(arr_, other.arr_);
        std::swap(capacity_, other.capacity_);
    }
    const int& Vector::operator[](int index) const{
        return arr_[index];
    };
    int& Vector::operator[](int index){
        return arr_[index];
    }
    const int& Vector::At(int index) const{
        if (index >= size_ || index < 0){
            throw std::out_of_range("Index out of range!");
        }
        return arr_[index];
    }
    int& Vector::At (int index){
        if (index >= size_ || index < 0){
            throw std::out_of_range("Index out of range!");
        }
        return arr_[index];
    };
    int Vector::Size() const{
        return size_;
    }
    int Vector::Capacity() const{
        return capacity_;
    }
    void Vector::PushBack(int value){
        if (size_ == capacity_){
            int newCapacity = capacity_ == 0 ? 1 : capacity_ * 2;
            Reserve(newCapacity);
        } 
        arr_[size_++] = value;
    }
    void Vector::PopBack(){
        if (size_ > 0){
            size_--;
        }
    }
    void Vector::Clear(){
        size_ = 0;
    }
    void Vector::Reserve(int newCapacity) {
    if (newCapacity <= capacity_ || newCapacity < 0) {
        return;  
    }
    int* temp = new int[newCapacity];
    if (arr_ != nullptr && size_ > 0) {
        std::copy(arr_, arr_ + size_, temp);
    }
    delete[] arr_;  
    arr_ = temp;
    capacity_ = newCapacity;
    }
    std::ostream& operator<<(std::ostream& out, const Vector& vec){
        out<<'[';
        for (int i = 0; i < vec.size_; ++i){
            if (i != vec.size_ - 1){
               out<<vec.arr_[i]<<", "; 
            } else {
                out<<vec.arr_[i];
            }
            
        }
        out<<']';
        return out;
    };
