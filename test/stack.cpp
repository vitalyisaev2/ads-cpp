#include "containers/stack.hpp"
#include "catch2/catch.hpp"
#include "containers/exception.hpp"

TEST_CASE("Stack")
{
    SECTION("push / pop / size")
    {
        containers::Stack<int> s;
        REQUIRE(s.size() == 0);
        s.push(1);
        s.push(2);
        s.push(3);
        REQUIRE(s.size() == 3);
        REQUIRE(s.pop() == 3);
        REQUIRE(s.pop() == 2);
        REQUIRE(s.pop() == 1);
        REQUIRE(s.size() == 0);
        // empty stack throws exception
        REQUIRE_THROWS_AS(s.pop(), containers::Exception);
    }
}