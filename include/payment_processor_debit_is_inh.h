//
// Created by bender on 16/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_DEBIT_IS_INH_H_
#define SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_DEBIT_IS_INH_H_
#include "payment_processor_abstract_sms_is_inh.h"
#include "spdlog/spdlog.h"
#include "trouble.h"

struct PaymentProcessorDebitISInh final : public PaymentProcessorAbstractSMS {
  explicit PaymentProcessorDebitISInh(const NewOrder &new_order, std::string_view security_code)
      : new_order_{std::make_shared<NewOrder>(new_order)}
      , security_code_{security_code} {}

  void AuthSMS(std::string_view sms_code) override {
    spdlog::info("Verifying SMS code {0}", sms_code);
    verified_ = true;
  }

  void Pay() const override {
    if (!verified_) {
      throw Trouble{"Not authorised"};
    }
    spdlog::info("Processing debit payment type");
    spdlog::info("Verifying security code: {0}", security_code_);
    new_order_->SetStatus(Status::Paid);
  }

  void DisplayInfo() const override {
    spdlog::info("Debit payment processor for order {0}", to_string(new_order_->GetId()));
  }

 private:
  std::shared_ptr<NewOrder> new_order_;
  std::string_view security_code_;
  bool verified_{false};
};

#endif//SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_DEBIT_IS_INH_H_
