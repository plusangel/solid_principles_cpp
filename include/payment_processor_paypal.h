//
// Created by bender on 16/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_PAYPAL_H_
#define SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_PAYPAL_H_
#include "payment_processor_abstract.h"
#include "spdlog/spdlog.h"

struct PaymentProcessorPaypal final : public PaymentProcessorAbstract {
  explicit PaymentProcessorPaypal(const NewOrder &new_order)
      : new_order_{std::make_shared<NewOrder>(new_order)} {}

  void Pay(std::string_view security_code) const override {
    spdlog::info("Processing paypal payment type");
    spdlog::info("Verifying security code: {0}", security_code);
    new_order_->SetStatus(Status::Paid);
  }

  void DisplayInfo() const override {
    spdlog::info("Paypal payment processor for order {0}", to_string(new_order_->GetId()));
  }

 private:
  std::shared_ptr<NewOrder> new_order_;
};

#endif//SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_PAYPAL_H_
