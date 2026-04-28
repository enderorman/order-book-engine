#pragma once
#include "trade.hpp"
#include "order.hpp"
#include "price_level.hpp"
#include <vector>
#include <optional>
#include <unordered_map>
#include <map>
class OrderBook {
    public: 
        std::vector<Trade> addLimitOrder(int64_t id, Side side, int64_t price, int64_t quantity, int64_t timestamp);
        std::vector<Trade> addMarketOrder(int64_t id, Side side, int64_t quantity, int64_t timestamp);
        bool cancelOrder(int64_t id);
        bool modifyOrder(int64_t id, int64_t new_price, int64_t  newQuantity);
        std::optional<int64_t> calculateBestBid() const;
        std::optional<int64_t> calculateBestAsk() const;
    private:
        std::map<int64_t, PriceLevel, std::greater<>> bids;
        std::map<int64_t, PriceLevel> asks;
        std::unordered_map<int64_t, Order*> orders; // id lookup for orders
};