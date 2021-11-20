#include "item.h"
#include "new_order.h"
#include "payment_processor.h"

int main() {
  Item item1{"Keyboard", 1, 50.0};
  Item item2{"SSD", 1, 150.0};
  Item item3{"USB cable", 2, 5.0};

  NewOrder an_order{};

  an_order.AddItem(item1);
  an_order.AddItem(item2);
  an_order.AddItem(item3);

  an_order.PrintOrder();

  PaymentProcessor payment_processor1{an_order};
  payment_processor1.DisplayInfo();
  payment_processor1.PayCredit("65379");

  PaymentProcessor payment_processor2{an_order};
  payment_processor2.DisplayInfo();
  payment_processor2.PayDebit("98664");

  PaymentProcessor payment_processor3{an_order};
  payment_processor3.DisplayInfo();
  payment_processor3.PayPaypal("12245");

  return 0;
}
