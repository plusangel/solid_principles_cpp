[![CMake](https://github.com/plusangel/solid_principles_cpp/actions/workflows/cmake.yml/badge.svg)](https://github.com/plusangel/solid_principles_cpp/actions/workflows/cmake.yml)

# SOLID principles in modern C++

## Description
We will try to explain SOLID principles with an example. We will start with a non optimised scenario of a sales system, and
we will build gradually on to of that for each individual principle. The sales system consists of the **Order** class. In this class
we can handle objects of the **Item** class. In general, we can add items in the order, print an order and finally pay it. Let's
see who the SOLID principles, which are
- Single Responsibility,
- Open-closed,
- Liskov Substitution,
- Interface Segregation and
- Dependency Inversion

can help us to optimise the sales system, step by step.

## Motivation
SOLID principles is one of the most popular set of principles which every coder should know. What is the best way
to understand it? To write an example. Okay. But the example should be representative of the situation. To accommodate this requirement,
Arjan Egges from [Arjan Codes](https://www.youtube.com/channel/UCVhQ2NnY5Rskt6UjCUkJ_DA) created the scenario. Then the final bit is that, you understand better when you try to explain to other 
people. That is the purpose of my [technical blog](http://codingadventures.org/) and this is part of it. Enjoy!

## Non-optimised example

Item class: [item.h](./include/item.h) \
Order class: [order.h](./include/order.h) & [order.cpp](./src/order.cpp)

Example of use: [main_plain.cpp](examples/main_plain.cpp)

## Principles

### Single Responsibility

Item class: [item.h](./include/item.h) \
New order class: [new_order.h](./include/new_order.h) & [new_order.cpp](./src/new_order.cpp) \
Payment processor: [payment_processor.h](./include/payment_processor.h) & [payment_processor.cpp](./src/payment_processor.cpp)

Example of use: [main_single_responsibility.cpp](examples/main_single_responsibility.cpp)

### Open-closed principle

Item class: [item.h](./include/item.h) \
New order class: [new_order.h](./include/new_order.h) & [new_order.cpp](./src/new_order.cpp) 

Payment processor abstract class: [payment_processor_abstract_op.h](./include/payment_processor_abstract_oc.h)

Child class 1: [payment_processor_credit_oc.h](./include/payment_processor_credit_oc.h) \
Child class 2: [payment_processor_debit_oc.h](./include/payment_processor_debit_oc.h) \
Child class 3: [payment_processor_paypal_oc.h](./include/payment_processor_paypal_oc.h)

Example: [main_open_closed.cpp](examples/main_open_closed.cpp)

### Liskov substitution principle

Item class: [item.h](./include/item.h) \
New order class: [new_order.h](./include/new_order.h) & [new_order.cpp](./src/new_order.cpp)

Parent class: [payment_processor_liskov.h](./include/payment_processor_abstract_liskov.h)

Child class 1: [payment_processor_credit_liskov.h](./include/payment_processor_credit_liskov.h) \
Child class 2: [payment_processor_debit_liskov.h](./include/payment_processor_debit_liskov.h) \
Child class 3: [payment_processor_paypal_liskov.h](./include/payment_processor_paypal_liskov.h)

Example: [main_liskov.cpp](examples/main_liskov.cpp)

### Interface segregation principle (Inheritance)

Item class: [item.h](./include/item.h) \
New order class: [new_order.h](./include/new_order.h) & [new_order.cpp](./src/new_order.cpp) 

Payment processor abstract class 1: [payment_processor_abstract_is.h](./include/payment_processor_abstract_is.h) \
Payment processor abstract class 2: [payment_processor_abstract_sms_is.h](./include/payment_processor_abstract_sms_is_inh.h)

Child class 1: [payment_processor_credit_is_inh.h](./include/payment_processor_credit_is_inh.h) \
Child class 2: [payment_processor_debit_is_inh.h](./include/payment_processor_debit_is_inh.h) \
Child class 3: [payment_processor_paypal_is_inh.h](./include/payment_processor_paypal_is_inh.h) 

Example: [main_is_inh.cpp](examples/main_is_inh.cpp)

### Interface segregation principle (Composition)

Item class: [item.h](./include/item.h) \
New order class: [new_order.h](./include/new_order.h) & [new_order.cpp](./src/new_order.cpp) 

Payment processor abstract  class: [payment_processor_abstract_is.h](./include/payment_processor_abstract_is.h) \
SMS Authorizer class: [sms_authorizer.h](./include/sms_authorizer.h)

Child class 1: [payment_processor_credit_is_comp.h](./include/payment_processor_credit_is_comp.h) \
Child class 2: [payment_processor_debit_is_comp.h](./include/payment_processor_debit_is_comp.h) \
Child class 3: [payment_processor_paypal_is_comp.h](./include/payment_processor_paypal_is_comp.h)

Example: [main_is_comp.cpp](examples/main_is_comp.cpp)

### Dependency inversion principle (Composition)

Item class: [item.h](./include/item.h) \
New order class: [new_order.h](./include/new_order.h) & [new_order.cpp](./src/new_order.cpp)

Payment processor abstract class: [payment_processor_abstract_is.h](./include/payment_processor_abstract_is.h)

Authorizer abstract class: [authorizer_abstract.h](./include/authorizer_abstract.h) \
SMS Authorizer class: [sms_authorizer.h](./include/sms_authorizer_di.h) \
Not a robot authorizer: [not_a_robot_authorizer.h](./include/not_a_robot_authorizer_di.h)

Child class 1: [payment_processor_credit_di_comp.h](./include/payment_processor_credit_di_comp.h) \
Child class 2: [payment_processor_debit_di_comp.h](./include/payment_processor_debit_di_comp.h) \
Child class 3: [payment_processor_paypal_di_comp.h](./include/payment_processor_paypal_di_comp.h)

Example: [main_di_comp.cpp](examples/main_di_comp.cpp)

## Author
Angelos Plastropoulos (aka Blender) via [CodingAdventures.org](http://codingadventures.org/)


## Credits
[Arjan Codes](https://www.youtube.com/channel/UCVhQ2NnY5Rskt6UjCUkJ_DA)