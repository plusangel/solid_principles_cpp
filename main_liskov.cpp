#include "item.h"
#include "new_order.h"
#include "payment_processor_debit_liskov.h"
#include "payment_processor_credit_liskov.h"
#include "payment_processor_paypal_liskov.h"

int main() {
  Item item1{"Keyboard", 1, 50.0};
  Item item2{"SSD", 1, 150.0};
  Item item3{"USB cable", 2, 5.0};
  NewOrder an_order{};

  an_order.AddItem(item1);
  an_order.AddItem(item2);
  an_order.AddItem(item3);

  an_order.PrintOrder();

  PaymentProcessorDebitLiskov processor1{an_order, "65379"};
  processor1.DisplayInfo();
  processor1.Pay();

  PaymentProcessorCreditLiskov processor2{an_order, "65379"};
  processor2.DisplayInfo();
  processor2.Pay();

  PaymentProcessorPaypalLiskov processor3{an_order, "angelos@in.gr"};
  processor3.DisplayInfo();
  processor3.Pay();

  return 0;
}
