//
// Created by bender on 15/11/2021.
//

#ifndef SOLID_PRINCIPLES__PAYMENT_PROCESSOR_H_
#define SOLID_PRINCIPLES__PAYMENT_PROCESSOR_H_
#include <string_view>
#include <memory>
#include "new_order.h"

struct PaymentProcessor {
  explicit PaymentProcessor(const NewOrder &new_order)
      : new_order_{std::make_shared<NewOrder>(new_order)}{}

  void DisplayInfo() const;
  void PayDebit(std::string_view security_code) const;
  void PayCredit(std::string_view security_code) const;
  void PayPaypal(std::string_view security_code) const;

 private:
  std::shared_ptr<NewOrder> new_order_;
};

#endif//SOLID_PRINCIPLES__PAYMENT_PROCESSOR_H_
