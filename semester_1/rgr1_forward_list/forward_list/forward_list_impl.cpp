#include "forward_list_impl.h"

ForwardList::ForwardList() : front_(nullptr), size_(0) {}

ForwardList::ForwardList(const ForwardList& other) : front_(nullptr), size_(0) {
    Node* src = other.front_;
    Node* last = nullptr;
    
    while (src) {
        Node* new_node = new Node(src->value_);
        
        if (!front_) {
            front_ = new_node;
        } else {
            last->next_ = new_node;
        }
        
        last = new_node;
        src = src->next_;
        ++size_;
    }
}

ForwardList::ForwardList(size_t count, int32_t value) : front_(nullptr), size_(0) {
    for (size_t i = 0; i < count; ++i) {
        PushFront(value);
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> init) : front_(nullptr), size_(0) {
    for (auto it = std::rbegin(init); it != std::rend(init); ++it) {
        PushFront(*it);
    }
}

ForwardList& ForwardList::operator=(const ForwardList& other) {
    if (this != &other) {
        Clear();
        
        Node* src = other.front_;
        Node* last = nullptr;
        
        while (src) {
            Node* new_node = new Node(src->value_);
            
            if (!front_) {
                front_ = new_node;
            } else {
                last->next_ = new_node;
            }
            
            last = new_node;
            src = src->next_;
            ++size_;
        }
    }
    return *this;
}

ForwardList::~ForwardList() {
    Clear();
}

void ForwardList::PushFront(int32_t value) {
    Node* node = new Node(value);
    node->next_ = front_;
    front_ = node;
    ++size_;
}

void ForwardList::PopFront() {
    if (!front_) {
        throw std::runtime_error("Forward list is empty");
    }
    
    Node* old = front_;
    front_ = front_->next_;
    delete old;
    --size_;
}

void ForwardList::Remove(int32_t value) {
    while (front_ && front_->value_ == value) {
        PopFront();
    }
    
    if (!front_) return;
    
    Node* prev = front_;
    Node* curr = front_->next_;
    
    while (curr) {
        if (curr->value_ == value) {
            prev->next_ = curr->next_;
            delete curr;
            curr = prev->next_;
            --size_;
        } else {
            prev = curr;
            curr = curr->next_;
        }
    }
}

void ForwardList::Clear() {
    while (front_) {
        PopFront();
    }
}

bool ForwardList::FindByValue(int32_t value) {
    Node* current = front_;
    while (current) {
        if (current->value_ == value) return true;
        current = current->next_;
    }
    return false;
}

void ForwardList::Print(std::ostream& out) {
    Node* current = front_;
    bool first = true;
    
    while (current) {
        if (!first) out << ' ';
        out << current->value_;
        first = false;
        current = current->next_;
    }
}

int32_t ForwardList::Front() const {
    if (!front_) {
        throw std::runtime_error("Forward list is empty");
    }
    return front_->value_;
}

size_t ForwardList::Size() const {
    return size_;
}