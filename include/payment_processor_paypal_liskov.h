//
// Created by bender on 16/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_PAYPAL_LISKOV_H_
#define SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_PAYPAL_LISKOV_H_
#include "payment_processor_abstract_liskov.h"
#include "spdlog/spdlog.h"

struct PaymentProcessorPaypalLiskov final : public PaymentProcessorAbstractLiskov {
  explicit PaymentProcessorPaypalLiskov(NewOrder &new_order, std::string_view email_address)
      : new_order_{new_order}
      , email_address_{email_address} {}

  void AuthSMS(std::string_view sms_code) override {
    spdlog::info("Verifying SMS code {0}", sms_code);
    verified_ = true;
  }

  void Pay() const override {
    spdlog::info("Processing paypal payment type");
    spdlog::info("Verifying security code: {0}", email_address_);
    new_order_.SetStatus(Status::Paid);
  }

  void DisplayInfo() const override {
    spdlog::info("Paypal payment processor for order {0}", to_string(new_order_.GetId()));
  }

 private:
  NewOrder &new_order_;
  std::string_view email_address_;
  bool verified_{false};
};

#endif//SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_PAYPAL_LISKOV_H_
