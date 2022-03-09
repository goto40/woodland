#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "cpp_tree_interpreter/version.h"

TEST_CASE( "hello_world", "[hello]" ) {
    std::cout << "cpp_tree_interpreter "<< cpp_tree_interpreter::VERSION << " " << cpp_tree_interpreter::VERSION_SHORT << " unittests\n";
    REQUIRE( true );
}
