#pragma once
#include <cstdint>
#include "order.hpp"

struct PriceLevel{
    Order* head = nullptr;
    Order* tail = nullptr;
    int64_t price = 0;
    int64_t total_quantity = 0;
    void append(Order* o);
    void unlink(Order* o);
    bool isEmpty() const;
};
