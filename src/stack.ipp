#include "stack.hpp"
#include <cassert>

template <class type>
void linkedStack<type>::initializeStack() {
    head = nullptr;
}

template <class type>
bool linkedStack<type>::isEmpty() const {
    return head == nullptr;
}

template <class type>
bool linkedStack<type>::isFull() const {
    return false;
}

template <class type>
void linkedStack<type>::push(const type& data) {
    node<type>* newNode = new node<type>;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

template <class type>
type linkedStack<type>::top() const {
    assert (!isEmpty());
    return head->data;
}

template <class type>
type linkedStack<type>::pop() {
    assert (!isEmpty());
    node<type>* temp = head;
    head = head->next;

    type out = temp->data;
    delete temp;
    return out;
}

template <class type>
void linkedStack<type>::_copyStack(const linkedStack<type>& other) {
    _deleteStack();
    initializeStack();

    linkedStack<type> tempStack;
    node<type>* temp = other.head;
    while (temp != nullptr) {
        tempStack.push(temp->data);
        temp = temp->next;
    }

    temp = tempStack.head;
    while (temp != nullptr) {
        push(temp->data);
        temp = temp->next;
    }
}

template <class type>
void linkedStack<type>::_deleteStack() {
    while (head != nullptr) {
        node<type>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class type>
linkedStack<type>::linkedStack() {
    head = nullptr;
}

template <class type>
linkedStack<type>::linkedStack(const linkedStack<type>& other) {
    _copyStack(other);
}

template <class type>
linkedStack<type>::~linkedStack() {
    _deleteStack();
}

template <class type>
const linkedStack<type>& linkedStack<type>::operator=(const linkedStack<type>& other) {
    if (head != other.head) {
        _copyStack(other);
    }
    return *this;
}

template <class type>
bool linkedStack<type>::operator==(const linkedStack<type>& other) const {
    node<type>* tempThis = head;
    node<type>* tempOther = other.head;

    while (tempThis != nullptr) {
        if (tempThis->data != tempOther->data) return false;
        tempThis = tempThis->next;
        tempOther = tempOther->next;
    }

    return true;
}
