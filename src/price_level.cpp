#include "orderbook/price_level.hpp"
void PriceLevel::append(Order* o){
    if (head == nullptr){
        o->prev = nullptr;
        o->next = nullptr;
        head = o;
        tail = o;
    }
    else{
        o->prev = tail;
        o->next = nullptr;
        tail->next = o;
        tail = o;
    }
    total_quantity += o->quantity;
}

void PriceLevel::unlink(Order* o){
    if (o->prev != nullptr){
        o->prev->next = o->next;
    }
    else{
        head = o->next;
    }
    if (o->next != nullptr){
        o->next->prev = o->prev;
    }
    else{
        tail = o->prev;
    }
    total_quantity -= o->quantity;
}

bool PriceLevel::isEmpty() const {
    return head == nullptr;
}