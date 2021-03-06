#include "item.h"
#include "new_order.h"
#include "payment_processor_credit_oc.h"
#include "payment_processor_debit_oc.h"
#include "payment_processor_paypal_oc.h"

int main() {
  Item item1{"Keyboard", 1, 50.0};
  Item item2{"SSD", 1, 150.0};
  Item item3{"USB cable", 2, 5.0};
  NewOrder an_order{};

  an_order.AddItem(item1);
  an_order.AddItem(item2);
  an_order.AddItem(item3);

  an_order.PrintOrder();

  PaymentProcessorDebitOC processor1{an_order};
  processor1.DisplayInfo();
  processor1.Pay("65379");

  PaymentProcessorCreditOC processor2{an_order};
  processor2.DisplayInfo();
  processor2.Pay("65379");

  PaymentProcessorPaypalOC processor3{an_order};
  processor3.DisplayInfo();
  processor3.Pay("65379");

  return 0;
}
