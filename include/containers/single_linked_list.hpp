#ifndef CONTAINERS_SINGLE_LINKED_LIST
#define CONTAINERS_SINGLE_LINKED_LIST

#include "exception.hpp"
#include <iostream>

namespace containers
{

    template <class T>
    class SingleLinkedListElement
    {
      public:
        SingleLinkedListElement(const T& value, SingleLinkedListElement* predecessor) : data(value), next(predecessor) {}
        ~SingleLinkedListElement() {}
        SingleLinkedListElement* getNext() const;
        const T&                 getValue() const;
        void                     setNext(SingleLinkedListElement* elem);
        void                     setValue(const T& newValue);

      private:
        T                        data;
        SingleLinkedListElement* next;
    };

    template <class T>
    SingleLinkedListElement<T>* SingleLinkedListElement<T>::getNext() const
    {
        return next;
    }

    template <class T>
    const T& SingleLinkedListElement<T>::getValue() const
    {
        return data;
    }

    template <class T>
    void SingleLinkedListElement<T>::setNext(SingleLinkedListElement* elem)
    {
        next = elem;
    }

    template <class T>
    void SingleLinkedListElement<T>::setValue(const T& newValue)
    {
        data = newValue;
    }

    // SingleLinkedList interface
    template <class T>
    class SingleLinkedList
    {
      public:
        SingleLinkedList() : head(nullptr) {}
        SingleLinkedList(const SingleLinkedList& other);
        ~SingleLinkedList();
        void                        pushFront(const T& value);
        void                        pushBack(const T& value);
        T                           popFront();
        SingleLinkedListElement<T>* findElem(const T& value) const;
        bool                        operator==(const SingleLinkedList<T>& other) const;

      private:
        SingleLinkedListElement<T>* head;
    };

    // O(N^2) because of push back
    template <class T>
    SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T>& other) : head(nullptr)
    {
        if (other.head == nullptr)
            {
                return;
            }
        for (auto curr = other.head; curr->getNext() != nullptr; curr = curr->getNext())
            {
                this->pushBack(curr->getValue());
            }
    }

    template <class T>
    SingleLinkedList<T>::~SingleLinkedList()
    {
        SingleLinkedListElement<T>* curr = head;
        SingleLinkedListElement<T>* next = nullptr;
        while (curr != nullptr)
            {
                next = curr->getNext();
                delete curr;
                curr = next;
            }
    }

    // O(1)
    template <class T>
    void SingleLinkedList<T>::pushFront(const T& value)
    {

        auto elem = new SingleLinkedListElement<T>(value, head);
        head      = elem;
    }

    // O(N)
    template <class T>
    void SingleLinkedList<T>::pushBack(const T& value)
    {
        auto elem = new SingleLinkedListElement<T>(value, nullptr);

        // if head is empty, set new element as head
        if (head == nullptr)
            {
                head = elem;
                return;
            }

        // rewind to last element
        auto curr = head;
        while (curr->getNext() != nullptr)
            {
                curr = curr->getNext();
            }
        curr->setNext(elem);
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
        head       = last->getNext();
        auto value = last->getValue();
        delete last;
        return value;
    }

    // O(N)
    template <class T>
    SingleLinkedListElement<T>* SingleLinkedList<T>::findElem(const T& value) const
    {

        for (auto curr = head; curr != nullptr; curr = curr->getNext())
            {
                if (curr->getValue() == value)
                    {
                        return curr;
                    }
            }
        return nullptr;
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
                if (lhs->getValue() != rhs->getValue())
                    {
                        return false;
                    }
                lhs = lhs->getNext();
                rhs = rhs->getNext();
            }
    }

} // namespace containers

#endif