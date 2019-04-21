#ifndef CONTAINERS_STACK
#define CONTAINERS_STACK

#include "exception.hpp"
#include "single_linked_list.hpp"
#include <string>

namespace containers
{

    // Stack implementation based on SingleLinkedList
    template <class T>
    class Stack
    {
      public:
        Stack() : _list(SingleLinkedList<T>()), _size(0){};
        ~Stack(){};
        void   push(const T& value);
        T      pop();
        size_t size() const;

      private:
        SingleLinkedList<T> _list;
        size_t              _size;
    };

    template <class T>
    void Stack<T>::push(const T& value)
    {
        _list.pushFront(value);
        _size++;
    }

    template <class T>
    T Stack<T>::pop()
    {
        if (_size == 0)
            {
                throw Exception(ErrorCode::EMPTY_STACK);
            }

        _size--;
        return _list.popFront();
    }

    template <class T>
    size_t Stack<T>::size() const
    {
        return _size;
    }
} // namespace containers

#endif