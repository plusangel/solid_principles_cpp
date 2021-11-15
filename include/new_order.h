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
#include "uuid.h"
#include "trouble.h"

struct NewOrder {
  void AddItem(const Item& new_item);
  [[nodiscard]] float TotalPrice() const;
  void SetStatus(std::string_view status);
  void PrintOrder() const;
  [[nodiscard]] const uuids::uuid &GetId() const;

 private:
  uuids::uuid id {uuids::uuid_system_generator{}()};
  std::vector<Item> items_;
  std::string status_{"open"};
};

#endif//SOLID_PRINCIPLES__ORDER_H_
