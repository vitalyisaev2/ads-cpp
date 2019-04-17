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
        SingleLinkedList() : head(nullptr) {}

        // O(N^2) because of push back
        SingleLinkedList(const SingleLinkedList& other) : head(nullptr)
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

        ~SingleLinkedList()
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
            curr->setNext(elem);
        }

        // O(N)
        SingleLinkedListElement<T>* findElem(const T& value) const
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
        bool operator==(const SingleLinkedList<T>& other) const
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

      private:
        SingleLinkedListElement<T>* head;
    };

} // namespace containers