//
// Created by bender on 16/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_CREDIT_DI_COMP_H_
#define SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_CREDIT_IS_COMP_H_
#include "payment_processor_abstract_is.h"
#include "spdlog/spdlog.h"
#include "trouble.h"

struct PaymentProcessorCreditDIComp final : public PaymentProcessorAbstractIS {
  explicit PaymentProcessorCreditDIComp(const NewOrder &new_order, std::string_view security_code)
      : new_order_{std::make_shared<NewOrder>(new_order)}
      , security_code_{security_code} {}

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

#endif//SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_CREDIT_DI_COMP_H_
