//
// Created by bender on 15/11/2021.
//

#include "payment_procesor.h"

void PaymentProcessor::PayDebit() const {
  spdlog::info("Processing debit payment type");
  spdlog::info("Verifying security code: {0}", security_code_);
  new_order_->SetStatus("paid");
}

void PaymentProcessor::PayCredit() const {
  spdlog::info("Processing credit payment type");
  spdlog::info("Verifying security code: {0}", security_code_);
  new_order_->SetStatus("paid");
}

void PaymentProcessor::PayPaypal() const {
  spdlog::info("Processing paypal payment type");
  spdlog::info("Verifying security code: {0}", security_code_);
  new_order_->SetStatus("paid");
}

void PaymentProcessor::DisplayInfo() const {
  spdlog::info("Payment processor for order {0} with security code {1}", to_string((new_order_->GetId())), security_code_);
}