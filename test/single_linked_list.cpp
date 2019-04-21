#include "containers/single_linked_list.hpp"
#include "catch2/catch.hpp"
#include "containers/exception.hpp"

TEST_CASE("SingleLinkedList")
{
    SECTION("pushBack / pushFront / findElem / popFront")
    {
        containers::SingleLinkedList<int> list;
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
        containers::SingleLinkedList<int> list1;
        list1.pushFront(1);
        list1.pushFront(2);
        auto list2(list1);
        list2.pushFront(3);
    }

    SECTION("equality operator")
    {
        containers::SingleLinkedList<int> list1;
        list1.pushFront(1);
        list1.pushFront(2);
        containers::SingleLinkedList<int> list2;
        list2.pushBack(2);
        list2.pushBack(1);
        REQUIRE(list1 == list2);
    }

    SECTION("remove front")
    {
        containers::SingleLinkedList<int> list;
        list.pushFront(3);
        list.pushFront(2);
        list.pushFront(1);
        // remove head
        list.remove(1);

        containers::SingleLinkedList<int> expected;
        expected.pushFront(3);
        expected.pushFront(2);
        REQUIRE(list == expected);
    }

    SECTION("remove middle")
    {
        containers::SingleLinkedList<int> list;
        list.pushFront(3);
        list.pushFront(2);
        list.pushFront(1);
        // remove item from middle
        list.remove(2);

        containers::SingleLinkedList<int> expected;
        expected.pushFront(3);
        expected.pushFront(1);
        REQUIRE(list == expected);
    }

    SECTION("remove tail")
    {
        containers::SingleLinkedList<int> list;
        list.pushFront(3);
        list.pushFront(2);
        list.pushFront(1);
        // remove item from middle
        list.remove(3);

        containers::SingleLinkedList<int> expected;
        expected.pushFront(2);
        expected.pushFront(1);
        REQUIRE(list == expected);
    }

    SECTION("remove non-existing item")
    {
        containers::SingleLinkedList<int> list;
        list.pushFront(3);
        list.pushFront(2);
        list.pushFront(1);
        // removing non-existing item causes exception
        REQUIRE_THROWS_AS(list.remove(4), containers::Exception);
    }

    SECTION("remove from empty list")
    {
        containers::SingleLinkedList<int> list;
        // removing from empty list causes panic
        REQUIRE_THROWS_AS(list.remove(4), containers::Exception);
    }
}