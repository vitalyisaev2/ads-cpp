#ifndef CONTAINERS_EXCEPTION
#define CONTAINERS_EXCEPTION

#include <exception>

namespace containers
{

    enum ErrorCode
    {
        RESERVED          = 0,
        EMPTY_LINKED_LIST = 1,
        EMPTY_STACK       = 2
    };

    struct Exception : public std::exception
    {
      public:
        Exception(ErrorCode value) : code(value) {}
        const char* what() const throw()
        {
            switch (code)
                {
                case EMPTY_LINKED_LIST:
                    return "empty linked list";
                case EMPTY_STACK:
                    return "empty stack";
                default:
                    return "unknown container error";
                }
        };

      private:
        ErrorCode code;
    };
} // namespace containers

#endif