#pragma once
#include <cstdint>
#include "side.hpp"

struct Order {
    Order* next;
    Order* prev;
    int64_t id;
    int64_t price;
    int64_t quantity;
    int64_t timestamp;
    Side side;
};