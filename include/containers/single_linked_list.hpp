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
        SingleLinkedList() : _head(nullptr) {}
        SingleLinkedList(const SingleLinkedList& other);
        ~SingleLinkedList();
        void pushFront(const T& value);
        void pushBack(const T& value);
        T    popFront();
        void remove(const T& value);
        void insertAfter(const T& existingValue, const T& newValue);
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
        Element* _head;
    };

    // O(N^2) because of push back
    template <class T>
    SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T>& other) : _head(nullptr)
    {
        if (other._head == nullptr)
            {
                return;
            }
        for (auto curr = other._head; curr->next != nullptr; curr = curr->next)
            {
                this->pushBack(curr->data);
            }
    }

    template <class T>
    SingleLinkedList<T>::~SingleLinkedList()
    {
        Element* curr = _head;
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

        auto elem = new Element(value, _head);
        _head     = elem;
    }

    // O(N)
    template <class T>
    void SingleLinkedList<T>::pushBack(const T& value)
    {
        auto elem = new Element(value, nullptr);

        // if _head is empty, set new element as _head
        if (_head == nullptr)
            {
                _head = elem;
                return;
            }

        // rewind to last element
        auto curr = _head;
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
        if (_head == nullptr)
            {
                throw Exception(ErrorCode::EMPTY_LINKED_LIST);
            }
        auto last  = _head;
        _head      = last->next;
        auto value = last->data;
        delete last;
        return value;
    }

    template <class T>
    void SingleLinkedList<T>::remove(const T& value)
    {
        if (_head == nullptr)
            {
                throw Exception(ErrorCode::EMPTY_LINKED_LIST);
            }

        // head item
        if (_head->data == value)
            {
                auto removed = _head;
                _head        = _head->next;
                delete removed;
                return;
            }

        // seek for target item
        auto curr = _head;
        while (curr->next != nullptr)
            {
                if (curr->next->data == value)
                    {
                        auto removed = curr->next;
                        // middle item
                        if (curr->next->next != nullptr)
                            {
                                curr->next = curr->next->next;
                            }
                        // last item
                        else
                            {
                                curr->next = nullptr;
                            }
                        delete removed;
                        return;
                    }
                curr = curr->next;
            }

        throw Exception(ErrorCode::ITEM_DOES_NOT_EXIST);
    }

    // O(N)
    template <class T>
    void SingleLinkedList<T>::insertAfter(const T& existingValue, const T& newValue)
    {
        if (_head == nullptr)
            {
                throw Exception(ErrorCode::EMPTY_LINKED_LIST);
            }

        for (auto curr = _head; curr != nullptr; curr = curr->next)
            {
                if (curr->data == existingValue)
                    {
                        curr->next = new Element(newValue, curr->next);
                        return;
                    }
            }

        throw Exception(ErrorCode::ITEM_DOES_NOT_EXIST);
    }

    // O(N)
    template <class T>
    bool SingleLinkedList<T>::exists(const T& value) const
    {
        for (auto curr = _head; curr != nullptr; curr = curr->next)
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

        auto lhs = _head;
        auto rhs = other._head;
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