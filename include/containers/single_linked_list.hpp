#include <iostream>

namespace containers
{

    template <class T>
    class SingleLinkedListElement
    {
      public:
        SingleLinkedListElement(const T& value, SingleLinkedListElement* predecessor) : data(value), next(predecessor) {}
        ~SingleLinkedListElement() {}
        SingleLinkedListElement* getNext() const
        {
            return next;
        }
        const T& getValue() const
        {
            return data;
        }
        void setNext(SingleLinkedListElement* elem)
        {
            next = elem;
        };
        void setValue(const T& newValue)
        {
            data = newValue;
        };

      private:
        T                        data;
        SingleLinkedListElement* next;
    };

    template <class T>
    class SingleLinkedList
    {
      public:
        SingleLinkedList() : head(nullptr)
        {
            std::cout << "constructor: " << this << std::endl;
        }

        // O(N^2) because of push back
        SingleLinkedList(const SingleLinkedList& other): head(nullptr)
        {
            std::cout << "copy constructor: " << this << std::endl;
            if (other.head == nullptr)
                {
                    return;
                }
            for (auto curr = other.head; curr->getNext() != nullptr; curr = curr->getNext())
                {
                    this->pushBack(curr->getValue());
                }
        }

        ~SingleLinkedList()
        {
            std::cout << "destructor: " << this << std::endl;
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
        void pushFront(const T& value)
        {
            auto elem = new SingleLinkedListElement<T>(value, head);
            head      = elem;
        }

        // O(N)
        void pushBack(const T& value)
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
            std::cout << "push back: " << this << " curr: " << curr << " elem: " << elem << std::endl;
            curr->setNext(elem);
        }

        SingleLinkedListElement<T>* findElem(const T& value)
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

      private:
        SingleLinkedListElement<T>* head;
    };

} // namespace containers