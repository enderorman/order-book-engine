#include <gtest/gtest.h>
#include "orderbook/order.hpp"
#include "orderbook/price_level.hpp"

TEST(PriceLevelTest, AppendToEmpty) {
    PriceLevel level;
    Order o{};
    o.quantity = 100;
    level.append(&o);
    EXPECT_EQ(level.head, level.tail);
    EXPECT_EQ(level.head, &o);
}

TEST(PriceLevelTest, AppendThree) {
    PriceLevel level;
    Order A{}, B{}, C{};
    A.quantity = 100;
    B.quantity = 50;
    C.quantity = 75;

    level.append(&A);
    level.append(&B);
    level.append(&C);

    // forward chain
    EXPECT_EQ(level.head, &A);
    EXPECT_EQ(A.next, &B);
    EXPECT_EQ(B.next, &C);
    EXPECT_EQ(C.next, nullptr);

    // backward chain
    EXPECT_EQ(level.tail, &C);
    EXPECT_EQ(C.prev, &B);
    EXPECT_EQ(B.prev, &A);
    EXPECT_EQ(A.prev, nullptr);

    // bookkeeping
    EXPECT_EQ(level.total_quantity, 225);
}


TEST(PriceLevelTest, UnlinkHead){
    PriceLevel level;
    Order A{}, B{}, C{};
    A.quantity = 100;
    B.quantity = 50;
    C.quantity = 75;

    level.append(&A);
    level.append(&B);
    level.append(&C);

    level.unlink(&A);
    // forward chain
    EXPECT_EQ(level.head, &B);
    EXPECT_EQ(B.next, &C);
    EXPECT_EQ(C.next, nullptr);

    // backward chain
    EXPECT_EQ(level.tail, &C);
    EXPECT_EQ(C.prev, &B);
    EXPECT_EQ(B.prev, nullptr);

    // bookkeeping
    EXPECT_EQ(level.total_quantity, 125);
}

TEST(PriceLevelTest, UnlinkTail){
    PriceLevel level;
    Order A{}, B{}, C{};
    A.quantity = 100;
    B.quantity = 50;
    C.quantity = 75;

    level.append(&A);
    level.append(&B);
    level.append(&C);

    level.unlink(&C);
    // forward chain
    EXPECT_EQ(level.head, &A);
    EXPECT_EQ(A.next, &B);
    EXPECT_EQ(B.next, nullptr);

    // backward chain
    EXPECT_EQ(level.tail, &B);
    EXPECT_EQ(B.prev, &A);
    EXPECT_EQ(A.prev, nullptr);

    // bookkeeping
    EXPECT_EQ(level.total_quantity, 150);
}


TEST(PriceLevelTest, UnlinkMiddle){
    PriceLevel level;
    Order A{}, B{}, C{};
    A.quantity = 100;
    B.quantity = 50;
    C.quantity = 75;

    level.append(&A);
    level.append(&B);
    level.append(&C);

    level.unlink(&B);
    // forward chain
    EXPECT_EQ(level.head, &A);
    EXPECT_EQ(A.next, &C);
    EXPECT_EQ(C.next, nullptr);

    // backward chain
    EXPECT_EQ(level.tail, &C);
    EXPECT_EQ(C.prev, &A);
    EXPECT_EQ(A.prev, nullptr);

    // bookkeeping
    EXPECT_EQ(level.total_quantity, 175);
}

TEST(PriceLevelTest, UnlinkOnlyElement){
    PriceLevel level;
    Order o{};
    o.quantity = 100;
    level.append(&o);
    level.unlink(&o);
    EXPECT_EQ(level.head, nullptr);
    EXPECT_EQ(level.tail, nullptr);
    EXPECT_EQ(level.total_quantity, 0);
}

TEST(PriceLevelTest, UnlinkAndReappend){
    PriceLevel level;
    Order A{}, B{}, C{};
    A.quantity = 100;
    B.quantity = 50;
    C.quantity = 75;

    level.append(&A);
    level.append(&B);
    level.append(&C);

    level.unlink(&A);
    level.append(&A);
    // forward chain
    EXPECT_EQ(level.head, &B);
    EXPECT_EQ(B.next, &C);
    EXPECT_EQ(C.next, &A);
    EXPECT_EQ(A.next, nullptr);

    // backward chain
    EXPECT_EQ(level.tail, &A);
    EXPECT_EQ(A.prev, &C);
    EXPECT_EQ(C.prev, &B);
    EXPECT_EQ(B.prev, nullptr);

    // bookkeeping
    EXPECT_EQ(level.total_quantity, 225);
}

