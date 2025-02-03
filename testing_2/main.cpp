#include <iostream>
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"
#include "my_list.h"

TEST_CASE("TEST_LIST", "[TEST_LIST]")
{
	List L1;

	SECTION("Проверка PushBack(int value), PushFront(int value)")
	{
		INFO("Проверка PushBack(int value)");
		CHECK(L1.Empty());
		L1.PushBack(1);
		L1.PushBack(2);
		CHECK(L1.Size() == 2);
		L1.Clear();
		INFO("Проверка PushFront(int value)");
		CHECK(L1.Empty());
		L1.PushFront(3);
		L1.PushFront(4);
		CHECK(L1.Size() == 2);
		L1.PushFront(5);
		CHECK(L1.Size() == 3);
		L1.Clear();
	};
	SECTION("Проверка PopBack(), PopFront()")
	{
		INFO("Проверка PopBack()");
		CHECK(L1.Empty());
		L1.PushBack(1);
		CHECK(L1.Size() == 1);
		L1.PopBack();
		CHECK(L1.Empty());
		REQUIRE_THROWS(L1.PopBack());
		INFO("Проверка PopFront()");
		CHECK(L1.Empty());
		L1.PushFront(1);
		CHECK(L1.Size() == 1);
		L1.PopFront();
		CHECK(L1.Empty());
		REQUIRE_THROWS(L1.PopFront());
	};
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	return Catch::Session().run(argc, argv);
}