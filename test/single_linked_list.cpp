#include "containers/single_linked_list.hpp"
#include "catch2/catch.hpp"

TEST_CASE("SingleLinkedList")
{
    SECTION("pushBack / pushFront / findElem")
    {
        auto list = containers::SingleLinkedList<int>();
        list.pushFront(1);
        list.pushBack(2);
        REQUIRE(list.findElem(1) != nullptr);
        REQUIRE(list.findElem(2) != nullptr);
        REQUIRE(list.findElem(3) == nullptr);
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