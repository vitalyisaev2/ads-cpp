#include "catch2/catch.hpp"
#include "containers/single_linked_list.hpp"

TEST_CASE("SingleLinkedList")
{
    SECTION("pushBack / pushFront / findElem")
    {
        auto list = containers::SingleLinkedList<int>();
        list.pushFront(1);
        list.pushBack(2);
        REQUIRE( list.findElem(1) != nullptr);
        REQUIRE( list.findElem(2) != nullptr);
        REQUIRE( list.findElem(3) == nullptr);
    }

    SECTION("copy constructor") {
        auto list1 = containers::SingleLinkedList<int>();
        list1.pushFront(1);
        list1.pushFront(2);
        auto list2(list1);
        list2.pushFront(3);
    }
}