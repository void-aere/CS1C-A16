#pragma once

template <class type>
class abstack {
    public:
        virtual void initializeStack() = 0;
        virtual bool isEmpty() const = 0;
        virtual bool isFull() const = 0;
        virtual void push(const type& data) = 0;
        virtual type top() const = 0;
        virtual type pop() = 0;
};

template <class type>
struct node {
    type data;
    node<type>* next;
};

template <class type>
class linkedStack : public abstack<type> {
    private:
        node<type>* head;

        void _copyStack(const linkedStack<type>& other);
        void _deleteStack();
    
    public:
        linkedStack();
        linkedStack(const linkedStack<type>& other);
        ~linkedStack();

        const linkedStack<type>& operator=(const linkedStack<type>& other);
        bool operator==(const linkedStack<type>& other) const;
        void initializeStack();
        bool isEmpty() const;
        bool isFull() const;
        void push(const type& data);
        type top() const;
        type pop();
};

#include "stack.ipp"