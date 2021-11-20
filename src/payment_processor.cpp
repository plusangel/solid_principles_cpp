//
// Created by bender on 15/11/2021.
//

#include "payment_processor.h"

void PaymentProcessor::PayDebit(std::string_view security_code) const {
  spdlog::info("Processing debit payment type");
  spdlog::info("Verifying security code: {0}", security_code);
  new_order_.SetStatus(Status::Paid);
}

void PaymentProcessor::PayCredit(std::string_view security_code) const {
  spdlog::info("Processing credit payment type");
  spdlog::info("Verifying security code: {0}", security_code);
  new_order_.SetStatus(Status::Paid);
}

void PaymentProcessor::PayPaypal(std::string_view security_code) const {
  spdlog::info("Processing paypal payment type");
  spdlog::info("Verifying security code: {0}", security_code);
  new_order_.SetStatus(Status::Paid);
}

void PaymentProcessor::DisplayInfo() const {
  spdlog::info("Payment processor for order {0}", to_string(new_order_.GetId()));
}