//
// Created by bender on 15/11/2021.
//
#include "new_order.h"

void NewOrder::AddItem(const Item& new_item){
  items_.push_back(new_item);
}

void NewOrder::PrintOrder() const {
  spdlog::info("The id of the order is {}, with items:", uuids::to_string(id));
  for (auto& item : items_) {
    spdlog::info(item.item_);
  }
  spdlog::info("and the status is {0}", StatusToString(status_));
}

float NewOrder::TotalPrice() const {
  float total {0.0};
  for (auto& item : items_) {
    total += static_cast<float>(item.quantity_)*item.price_;
  }
  return total;
}

void NewOrder::SetStatus(Status status) {
  status_ = status;
}

const uuids::uuid &NewOrder::GetId() const {
  return id;
}
