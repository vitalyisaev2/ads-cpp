#include "containers/single_linked_list.hpp"
#include "catch2/catch.hpp"
#include "containers/exception.hpp"

TEST_CASE("SingleLinkedList")
{
    SECTION("pushBack / pushFront / findElem / popFront")
    {
        auto list = containers::SingleLinkedList<int>();
        list.pushFront(1);
        list.pushBack(2);
        REQUIRE(list.exists(1));
        REQUIRE(list.exists(2));
        REQUIRE(!list.exists(3));
        REQUIRE(list.popFront() == 1);
        REQUIRE(list.popFront() == 2);
        // list is empty now
        REQUIRE_THROWS_AS(list.popFront(), containers::Exception);
    }

    SECTION("copy constructor")
    {
        auto list1 = containers::SingleLinkedList<int>();
        list1.pushFront(1);
        list1.pushFront(2);
        auto list2(list1);
        list2.pushFront(3);
    }

    SECTION("equality operator")
    {
        auto list1 = containers::SingleLinkedList<int>();
        list1.pushFront(1);
        list1.pushFront(2);
        auto list2 = containers::SingleLinkedList<int>();
        list2.pushBack(2);
        list2.pushBack(1);
        REQUIRE(list1 == list2);
    }
}