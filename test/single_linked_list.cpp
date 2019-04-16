#include "catch2/catch.hpp"
#include "containers/single_linked_list.hpp"

TEST_CASE("SingleLinkedList")
{
    SECTION("populate list with some data, check availability")
    {
        auto sll = containers::SingleLinkedList<int>();
        sll.pushFront(1);
        sll.pushFront(2);
        sll.pushFront(3);
        REQUIRE( sll.findElem(1) != nullptr);
        // REQUIRE( sll.findElem(2) != nullptr);
        // REQUIRE( sll.findElem(3) != nullptr);
        // REQUIRE( sll.findElem(4) == nullptr);
    }
}