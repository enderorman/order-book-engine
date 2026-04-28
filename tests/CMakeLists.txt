# Helper function to reduce duplication
function(add_orderbook_test name source)
    add_executable(${name} ${source})
    target_link_libraries(${name}
        PRIVATE
            orderbook_lib
            GTest::gtest
            GTest::gtest_main
    )
    gtest_discover_tests(${name})
endfunction()

include(GoogleTest)

add_orderbook_test(test_price_level test_price_level.cpp)
#add_orderbook_test(test_orderbook   test_orderbook.cpp)
#add_orderbook_test(fuzz_test        fuzz_test.cpp)