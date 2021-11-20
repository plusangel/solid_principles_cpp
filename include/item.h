//
// Created by bender on 10/11/2021.
//

#ifndef SOLID_PRINCIPLES__ITEM_H_
#define SOLID_PRINCIPLES__ITEM_H_
#include <string_view>

struct Item {
  Item(std::string_view item, int quantity, float price)
      : item_{item}
      , quantity_{quantity}
      , price_{price} {}

  std::string_view item_;
  int quantity_;
  float price_;
};
#endif//SOLID_PRINCIPLES__ITEM_H_
