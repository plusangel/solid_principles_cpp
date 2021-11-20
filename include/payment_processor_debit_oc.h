//
// Created by bender on 16/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_DEBIT_OC_H_
#define SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_DEBIT_OC_H_
#include "payment_processor_abstract_oc.h"
#include "spdlog/spdlog.h"

struct PaymentProcessorDebitOC final : public PaymentProcessorAbstractOC {
  explicit PaymentProcessorDebitOC(NewOrder &new_order)
      : new_order_{new_order} {}

  void Pay(std::string_view security_code) const override {
    spdlog::info("Processing debit payment type");
    spdlog::info("Verifying security code: {0}", security_code);
    new_order_.SetStatus(Status::Paid);
  }

  void DisplayInfo() const override {
    spdlog::info("Debit payment processor for order {0}", to_string(new_order_.GetId()));
  }

 private:
  NewOrder &new_order_;
};

#endif//SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_DEBIT_OC_H_
