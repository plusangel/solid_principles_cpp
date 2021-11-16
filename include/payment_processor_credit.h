//
// Created by bender on 16/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_CREDIT_H_
#define SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_CREDIT_H_
#include "payment_processor_abstract.h"
#include "spdlog/spdlog.h"

struct PaymentProcessorCredit final : public PaymentProcessorAbstract {
  PaymentProcessorCredit(const NewOrder &new_order, std::string_view security_code)
      : new_order_{std::make_shared<NewOrder>(new_order)}
      , security_code_{security_code} {}

  void Pay() const override {
    spdlog::info("Processing credit payment type");
    spdlog::info("Verifying security code: {0}", security_code_);
    new_order_->SetStatus(Status::Paid);
  }

  void DisplayInfo() const override {
    spdlog::info("Credit payment processor for order {0} with security code {1}", to_string(new_order_->GetId()), security_code_);
  }

 private:
  std::shared_ptr<NewOrder> new_order_;
  std::string_view security_code_;
};

#endif//SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_CREDIT_H_
