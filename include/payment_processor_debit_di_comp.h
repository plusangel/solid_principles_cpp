//
// Created by bender on 16/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_DEBIT_DI_COMP_H_
#define SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_DEBIT_DI_COMP_H_
#include <memory>
#include <utility>
#include "payment_processor_abstract_is.h"
#include "authorizer_abstract.h"
#include "spdlog/spdlog.h"
#include "trouble.h"

struct PaymentProcessorDebitDIComp final : public PaymentProcessorAbstractIS {
  explicit PaymentProcessorDebitDIComp(const NewOrder &new_order, std::string_view security_code, std::shared_ptr<Authorizer> authorizer)
      : new_order_{std::make_shared<NewOrder>(new_order)}
      , security_code_{security_code}
      , authorizer_{std::move(authorizer)}
  {}

  void Pay() const override {
    if (!authorizer_->IsAuthorized()) {
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
  std::shared_ptr<Authorizer> authorizer_;
};

#endif//SOLID_PRINCIPLES_INCLUDE_PAYMENT_PROCESSOR_DEBIT_DI_COMP_H_
