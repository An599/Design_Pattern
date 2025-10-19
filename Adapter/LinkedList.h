#pragma once
#include "List.h"
#include <cstddef>
#include <stdexcept>

template <typename T>
class LinkedList : public List<T>
{
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& value, Node* n = nullptr, Node* p = nullptr)
            : data(value), next(n), prev(p) {
        }
    };

    Node* head;
    Node* tail;
    std::size_t count;

public:
    LinkedList();
    ~LinkedList();

    void push_back(const T& value) override;
    void pop_back() override;
    void push_front(const T& value) override;
    void pop_front() override;
    const T& front() const override;
    const T& back() const override;
    std::size_t size() const override;
    bool empty() const override;
    void clear() override;
};

#include "LinkedList.ipp"
