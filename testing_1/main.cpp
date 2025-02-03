#include <iostream>
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"
#include "my_list.h"


TEST_CASE("TEST_LIST", "[TEST_LIST]")
{
	List L1;

	SECTION("�������� ������ �� ������ CHECK Empty()")
	{
		INFO("�������� ������ �� ������");
		CHECK(L1.Empty());
		L1.PushBack(1);
		CHECK(!L1.Empty());
		L1.PopBack();
		CHECK(L1.Empty());
	};
	SECTION("�������� ������� ������ CHECK Size()")
	{
		INFO("�������� ������� ������");
		CHECK(L1.Size() == 0);
		L1.PushBack(1);
		CHECK(L1.Size() == 1);
		L1.PushBack(2);
		L1.PushBack(3);
		CHECK(L1.Size() == 3);
		L1.PopBack();
		CHECK(L1.Size() == 2);
		L1.PopBack();
		L1.PopBack();
		CHECK(L1.Size() == 0);
	};
	SECTION("�������� ������� ������ CHECK Clear()")
	{
		INFO("�������� ������� ������");
		CHECK(L1.Size() == 0);
		L1.PushBack(1);
		L1.PushBack(2);
		CHECK(!L1.Empty());
		L1.Clear();
		CHECK(L1.Empty());
	};
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	return Catch::Session().run(argc, argv);
}