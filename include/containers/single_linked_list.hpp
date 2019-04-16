namespace containers
{

    template <class T>
    class SingleLinkedListElement
    {
      public:
        SingleLinkedListElement(const T& value, SingleLinkedListElement* predecessor) : data(value), next(predecessor)
        {
        }
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
        SingleLinkedListElement* next;
        T                        data;
    };

    template <class T>
    class SingleLinkedList
    {
      public:
        SingleLinkedList() : head(nullptr) {}

        ~SingleLinkedList()
        {
            SingleLinkedListElement<T>* curr = head;
            SingleLinkedListElement<T>* next = nullptr;
            while (curr != nullptr)
                {
                    next = curr->getNext();
                    curr = next;
                    delete next;
                }
        }

        void pushFront(const T& value)
        {
            auto curr = new SingleLinkedListElement<T>(value, head);
            head = curr;
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