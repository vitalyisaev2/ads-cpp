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
        Stack() : list(SingleLinkedList<T>()), size(0){};
        ~Stack();
        void   push(const T& value);
        T      pop();
        size_t getSize() const;

      private:
        SingleLinkedList<T> list;
        size_t              size;
    };

    template <class T>
    void Stack<T>::push(const T& value)
    {
        list.pushFront(value);
        size++;
    }

    template <class T>
    T Stack<T>::pop()
    {
        if (size == 0)
            {
                throw StackException(ErrorCode::EMPTY_STACK);
            }

        size--;
        return list.popFront();
    }
} // namespace containers

#endif