#pragma once
#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::push_back(const T& value) {
    Node* newNode = new Node(value, nullptr, tail);
    if (tail)
        tail->next = newNode;
    else
        head = newNode;
    tail = newNode;
    ++count;
}

template <typename T>
void LinkedList<T>::pop_back() {
    if (!tail)
        throw std::out_of_range("List is empty");

    Node* temp = tail;
    tail = tail->prev;
    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;

    delete temp;
    --count;
}

template <typename T>
void LinkedList<T>::push_front(const T& value) {
    Node* newNode = new Node(value, head, nullptr);
    if (head)
        head->prev = newNode;
    else
        tail = newNode;
    head = newNode;
    ++count;
}

template <typename T>
void LinkedList<T>::pop_front() {
    if (!head)
        throw std::out_of_range("List is empty");

    Node* temp = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;

    delete temp;
    --count;
}

template <typename T>
const T& LinkedList<T>::front() const {
    if (!head)
        throw std::out_of_range("List is empty");
    return head->data;
}

template <typename T>
const T& LinkedList<T>::back() const {
    if (!tail)
        throw std::out_of_range("List is empty");
    return tail->data;
}

template <typename T>
bool LinkedList<T>::empty() const {
    return head == nullptr;
}

template <typename T>
std::size_t LinkedList<T>::size() const {
    return count;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    count = 0;
}
