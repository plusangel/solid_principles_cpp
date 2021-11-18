//
// Created by bender on 16/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_CREDIT_LISKOV_H_
#define SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_CREDIT_LISKOV_H_
#include "payment_processor_abstract_liskov.h"
#include "spdlog/spdlog.h"
#include "trouble.h"

struct PaymentProcessorCreditLiskov final : public PaymentProcessorAbstractLiskov {
  explicit PaymentProcessorCreditLiskov(const NewOrder &new_order, std::string_view security_code)
      : new_order_{std::make_shared<NewOrder>(new_order)}
      , security_code_{security_code} {}

  void AuthSMS(std::string_view sms_code) override {
    throw Trouble("Credit card payments don't support SMS code authorization.");
  }

  void Pay() const override {
    spdlog::info("Processing credit payment type");
    spdlog::info("Verifying security code: {0}", security_code_);
    new_order_->SetStatus(Status::Paid);
  }

  void DisplayInfo() const override {
    spdlog::info("Credit payment processor for order {0}", to_string(new_order_->GetId()));
  }

 private:
  std::shared_ptr<NewOrder> new_order_;
  std::string_view security_code_;
};

#endif//SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_CREDIT_LISKOV_H_
