#include "spdlog/spdlog.h"
#include "item.h"
#include "new_order.h"
#include "payment_procesor.h"

int main() {
  Item item1{"Keyboard", 1, 50.0};
  Item item2{"SSD", 1, 150.0};
  Item item3{"USB cable", 2, 5.0};
  NewOrder an_order{};

  an_order.AddItem(item1);
  an_order.AddItem(item2);
  an_order.AddItem(item3);

  an_order.PrintOrder();

  PaymentProcessor payment_processor{an_order, "65379"};
  payment_processor.DisplayInfo();
  payment_processor.PayCredit();

  return 0;
}