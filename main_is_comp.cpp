#include "item.h"
#include "new_order.h"
#include "payment_processor_credit_is_comp.h"
#include "payment_processor_debit_is_comp.h"
#include "payment_processor_paypal_is_comp.h"
#include "spdlog/spdlog.h"

int main() {
  Item item1{"Keyboard", 1, 50.0};
  Item item2{"SSD", 1, 150.0};
  Item item3{"USB cable", 2, 5.0};
  NewOrder an_order{};

  an_order.AddItem(item1);
  an_order.AddItem(item2);
  an_order.AddItem(item3);

  an_order.PrintOrder();

  auto authorizer1 = std::make_shared<SMSAuthorizer>();
  PaymentProcessorDebitISComp processor1{an_order, "65379", authorizer1};
  try {
    processor1.DisplayInfo();
    authorizer1->VerifyCode("7987356");
    processor1.Pay();
  } catch (const std::exception &e) {
    spdlog::error(e.what());
  }

  PaymentProcessorCreditISComp processor2{an_order, "65379"};
  try {
    processor2.DisplayInfo();
    processor2.Pay();
  } catch (const std::exception &e) {
    spdlog::error(e.what());
  }

  auto authorizer3 = std::make_shared<SMSAuthorizer>();
  PaymentProcessorPaypalISComp processor3{an_order, "angelos@in.gr", authorizer3};
  try {
    processor3.DisplayInfo();
    authorizer3->VerifyCode("9778555");
    processor3.Pay();
  } catch (const std::exception &e) {
    spdlog::error(e.what());
  }

  return 0;
}