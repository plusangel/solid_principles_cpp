#include "spdlog/spdlog.h"
#include "item.h"
#include "order.h"

int main() {
  Item item1{"Keyboard", 1, 50.0};
  Item item2{"SSD", 1, 150.0};
  Item item3{"USB cable", 2, 5.0};
  Order an_order{};

  an_order.AddItem(item1);
  an_order.AddItem(item2);
  an_order.AddItem(item3);

  an_order.PrintOrder();

  spdlog::info("The total price is {}", an_order.TotalPrice());
  try {
    an_order.Pay("debit", "09878");
  } catch (const Trouble& t) {
    spdlog::error(t.what());
  }

  try {
    an_order.Pay("credit", "96553");
  } catch (const Trouble& t) {
    spdlog::error(t.what());
  }

  return 0;
}
