//
// Created by bender on 10/11/2021.
//

#include "order.h"

void Order::AddItem(const Item &new_item) {
  items_.push_back(new_item);
}

void Order::PrintOrder() const {
  for (auto &item : items_) {
    spdlog::info(item.item_);
  }
}

float Order::TotalPrice() const {
  float total{0.0};
  for (auto &item : items_) {
    total += static_cast<float>(item.quantity_) * item.price_;
  }
  return total;
}

void Order::Pay(std::string_view payment_type, std::string_view security_code) {
  if (payment_type == "debit") {
    spdlog::info("Processing debit payment type");
    spdlog::info("Verifying security code: {}", security_code);
    status_ = "paid";
  } else if (payment_type == "credit") {
    spdlog::info("Processing credit payment type");
    spdlog::info("Verifying security code: {}", security_code);
    status_ = "paid";
  } else {
    throw Trouble(std::string("Unknown payment type ") + payment_type.data());
  }
}
