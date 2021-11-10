//
// Created by bender on 10/11/2021.
//

#ifndef SOLID_PRINCIPLES__ORDER_H_
#define SOLID_PRINCIPLES__ORDER_H_
#include "item.h"
#include <vector>
#include <string>
#include <string_view>
#include <iostream>
#include "spdlog/spdlog.h"
#include "trouble.h"

class Order {
 public:
  void AddItem(const Item& new_item);
  [[nodiscard]] float TotalPrice() const;
  void Pay(std::string_view payment_type, std::string_view security_code);
  void PrintOrder() const;

 private:
  std::vector<Item> items_;
  std::string status_{"open"};
};

#endif//SOLID_PRINCIPLES__ORDER_H_
