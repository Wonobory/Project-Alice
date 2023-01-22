#include "catch.hpp"
#include"system_state.hpp"

TEST_CASE("string pool tests", "[misc_tests]") {
	std::unique_ptr<sys::state> state = std::make_unique<sys::state>();

	auto a = state->add_to_pool("blah_blah");
	auto b = state->add_to_pool("1234");

	auto old_size_a = state->text_data.size();
	auto c = state->add_to_pool("");
	REQUIRE(old_size_a == state->text_data.size());

	auto d = state->add_to_pool("last");

	REQUIRE(state->to_string_view(a) == "blah_blah");
	REQUIRE(state->to_string_view(b) == "1234");
	REQUIRE(state->to_string_view(c).length() == size_t(0));
	REQUIRE(state->to_string_view(d) == "last");

	auto old_size = state->text_data.size();
	auto x = state->add_unique_to_pool("12");
	REQUIRE(old_size == state->text_data.size());

	auto y = state->add_unique_to_pool("new");

	REQUIRE(state->to_string_view(x) == "12");
	REQUIRE(state->to_string_view(y) == "new");
}