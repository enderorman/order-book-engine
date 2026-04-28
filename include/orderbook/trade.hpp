#pragma once
#include <cstdint>

struct Trade {
    int64_t buy_id;
    int64_t sell_id;
    int64_t price;
    int64_t quantity;
    int64_t timestamp;  
};