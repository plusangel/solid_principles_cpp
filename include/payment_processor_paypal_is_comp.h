//
// Created by bender on 16/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_PAYPAL_IS_INH_H_
#define SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_PAYPAL_IS_INH_H_
#include <memory>
#include "payment_processor_abstract_is.h"
#include "sms_authorizer.h"
#include "spdlog/spdlog.h"
#include "trouble.h"

struct PaymentProcessorPaypalISComp final : public PaymentProcessorAbstractIS {
  explicit PaymentProcessorPaypalISComp(const NewOrder &new_order, std::string_view email_address, std::shared_ptr<SMSAuthorizer> sms_authorizer)
      : new_order_{std::make_shared<NewOrder>(new_order)}
      , email_address_{email_address}
      , sms_authorizer_{std::move(sms_authorizer)} {}

  void Pay() const override {
    if (!sms_authorizer_->IsAuthorized()) {
      throw Trouble{"Not authorised"};
    }
    spdlog::info("Processing paypal payment type");
    spdlog::info("Verifying security code: {0}", email_address_);
    new_order_->SetStatus(Status::Paid);
  }

  void DisplayInfo() const override {
    spdlog::info("Paypal payment processor for order {0}", to_string(new_order_->GetId()));
  }

 private:
  std::shared_ptr<NewOrder> new_order_;
  std::string_view email_address_;
  std::shared_ptr<SMSAuthorizer> sms_authorizer_;
};

#endif//SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_PAYPAL_IS_INH_H_
