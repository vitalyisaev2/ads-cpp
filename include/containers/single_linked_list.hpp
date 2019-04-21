#ifndef CONTAINERS_SINGLE_LINKED_LIST
#define CONTAINERS_SINGLE_LINKED_LIST

#include "exception.hpp"
#include <iostream>

namespace containers
{

    // SingleLinkedList interface
    template <class T>
    class SingleLinkedList
    {
      public:
        SingleLinkedList() : head(nullptr) {}
        SingleLinkedList(const SingleLinkedList& other);
        ~SingleLinkedList();
        void pushFront(const T& value);
        void pushBack(const T& value);
        T    popFront();
        bool exists(const T& value) const;
        bool operator==(const SingleLinkedList<T>& other) const;

      private:
        struct Element
        {
            Element(T _data, Element* _next) : data(_data), next(_next){};
            T        data;
            Element* next;
        };

      private:
        Element* head;
    };

    // O(N^2) because of push back
    template <class T>
    SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T>& other) : head(nullptr)
    {
        if (other.head == nullptr)
            {
                return;
            }
        for (auto curr = other.head; curr->next != nullptr; curr = curr->next)
            {
                this->pushBack(curr->data);
            }
    }

    template <class T>
    SingleLinkedList<T>::~SingleLinkedList()
    {
        Element* curr = head;
        Element* next = nullptr;
        while (curr != nullptr)
            {
                next = curr->next;
                delete curr;
                curr = next;
            }
    }

    // O(1)
    template <class T>
    void SingleLinkedList<T>::pushFront(const T& value)
    {

        auto elem = new Element(value, head);
        head      = elem;
    }

    // O(N)
    template <class T>
    void SingleLinkedList<T>::pushBack(const T& value)
    {
        auto elem = new Element(value, nullptr);

        // if head is empty, set new element as head
        if (head == nullptr)
            {
                head = elem;
                return;
            }

        // rewind to last element
        auto curr = head;
        while (curr->next != nullptr)
            {
                curr = curr->next;
            }
        curr->next = elem;
    }

    // O(1)
    template <class T>
    T SingleLinkedList<T>::popFront()
    {
        if (head == nullptr)
            {
                throw Exception(ErrorCode::EMPTY_LINKED_LIST);
            }
        auto last  = head;
        head       = last->next;
        auto value = last->data;
        delete last;
        return value;
    }

    // O(N)
    template <class T>
    bool SingleLinkedList<T>::exists(const T& value) const
    {

        for (auto curr = head; curr != nullptr; curr = curr->next)
            {
                if (curr->data == value)
                    {
                        return true;
                    }
            }
        return false;
    }

    // O(N)
    template <class T>
    bool SingleLinkedList<T>::operator==(const SingleLinkedList<T>& other) const
    {

        auto lhs = head;
        auto rhs = other.head;
        while (true)
            {
                if (lhs == nullptr && rhs == nullptr)
                    {
                        return true;
                    }
                if ((lhs == nullptr && rhs != nullptr) || (lhs != nullptr && rhs == nullptr))
                    {
                        return false;
                    }
                if (lhs->data != rhs->data)
                    {
                        return false;
                    }
                lhs = lhs->next;
                rhs = rhs->next;
            }
    }

} // namespace containers

#endif