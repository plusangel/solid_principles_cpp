//
// Created by bender on 15/11/2021.
//

#ifndef SOLID_PRINCIPLES__PAYMENT_PROCESSOR_H_
#define SOLID_PRINCIPLES__PAYMENT_PROCESSOR_H_
#include <string_view>
#include <memory>
#include "new_order.h"

struct PaymentProcessor {
  PaymentProcessor(const NewOrder& new_order, std::string_view security_code) :
      new_order_{std::make_shared<NewOrder>(new_order)},
      security_code_{security_code} {}

  void DisplayInfo() const;
  void PayDebit() const;
  void PayCredit() const;
  void PayPaypal() const;

 private:
  std::shared_ptr<NewOrder> new_order_;
  std::string_view security_code_;
};

#endif//SOLID_PRINCIPLES__PAYMENT_PROCESSOR_H_
