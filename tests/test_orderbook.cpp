#include <gtest/gtest.h>

#include "orderbook/orderbook.hpp"

TEST(OrderBookTest, EmptyBookHasNoBidOrAsk) {
    OrderBook book;
    EXPECT_FALSE(book.calculateBestAsk().has_value());
    EXPECT_FALSE(book.calculateBestBid().has_value());
}
