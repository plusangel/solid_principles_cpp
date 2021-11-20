//
// Created by bender on 15/11/2021.
//

#ifndef SOLID_PRINCIPLES__PAYMENT_PROCESSOR_H_
#define SOLID_PRINCIPLES__PAYMENT_PROCESSOR_H_
#include "new_order.h"
#include <string_view>

struct PaymentProcessor {
  explicit PaymentProcessor(NewOrder &new_order)
      : new_order_{new_order} {}

  void DisplayInfo() const;
  void PayDebit(std::string_view security_code) const;
  void PayCredit(std::string_view security_code) const;
  void PayPaypal(std::string_view security_code) const;

 private:
  NewOrder &new_order_;
};

#endif//SOLID_PRINCIPLES__PAYMENT_PROCESSOR_H_
