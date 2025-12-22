#pragma once

#include <iterator>
#include <iostream>
#include <cstdint>
#include <initializer_list>
#include <stdexcept>

class ForwardList {
private:
    struct Node {
        int32_t value_;
        Node* next_;
        explicit Node(int32_t val) : value_(val), next_(nullptr) {}
    };

    Node* front_;
    size_t size_;

public:
    class ForwardListIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int32_t;
        using pointer = value_type*;
        using reference = value_type&;

        explicit ForwardListIterator(Node* pos = nullptr) : position_(pos) {}

        ForwardListIterator& operator++() {
            if (position_) position_ = position_->next_;
            return *this;
        }

        ForwardListIterator operator++(int) {
            ForwardListIterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const ForwardListIterator& other) const {
            return position_ == other.position_;
        }

        bool operator!=(const ForwardListIterator& other) const {
            return position_ != other.position_;
        }

        reference operator*() const {
            return position_->value_;
        }

        pointer operator->() {
            return &position_->value_;
        }

    private:
        Node* position_;
    };

    ForwardListIterator begin() { return ForwardListIterator(front_); }
    ForwardListIterator end() { return ForwardListIterator(); }
    const ForwardListIterator begin() const { return ForwardListIterator(front_); }
    const ForwardListIterator end() const { return ForwardListIterator(); }

    ForwardList();
    ForwardList(const ForwardList& other);
    ForwardList(size_t count, int32_t value);
    ForwardList(std::initializer_list<int32_t> init);
    ForwardList& operator=(const ForwardList& other);
    ~ForwardList();

    void PushFront(int32_t value);
    void PopFront();
    void Remove(int32_t value);
    void Clear();
    bool FindByValue(int32_t value);
    void Print(std::ostream& out);
    int32_t Front() const;
    size_t Size() const;
};