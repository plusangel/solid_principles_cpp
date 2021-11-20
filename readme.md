# SOLID principles in modern C++

## Description
TBD

## Motivation
TBD

## Non-optimised example

Item class: [item.h](./include/item.h) \
Order class: [order.h](./include/order.h) & [order.cpp](./src/order.cpp)

Example of use: [main_plain.cpp](./main_plain.cpp)

## Principles

### Integration Segregation Principle (Inheritance)

Parent class 1: [payment_processor_abstract_is.h](./include/payment_processor_abstract_is.h) \
Parent class 2: [payment_processor_abstract_sms_is.h](./include/payment_processor_abstract_sms_is_inh.h)

Child class 1: [payment_processor_credit_is_inh.h](./include/payment_processor_credit_is_inh.h) \
Child class 2: [payment_processor_debit_is_inh.h](./include/payment_processor_debit_is_inh.h) \
Child class 3: [payment_processor_paypal_is_inh.h](./include/payment_processor_paypal_is_inh.h) 

Example: [main_is_inh.cpp](./main_is_inh.cpp)

### Integration Segregation Principle (Composition)

Parent class: [payment_processor_abstract_is.h](./include/payment_processor_abstract_is.h) \
SMS_authorizer class: [sms_authorizer.h](./include/sms_authorizer.h)

Child class 1: [payment_processor_credit_is_comp.h](./include/payment_processor_credit_is_comp.h) \
Child class 2: [payment_processor_debit_is_comp.h](./include/payment_processor_debit_is_comp.h) \
Child class 3: [payment_processor_paypal_is_comp.h](./include/payment_processor_paypal_is_comp.h)

Example: [main_is_comp.cpp](./main_is_comp.cpp)

## Author
Angelos Plastropoulos (aka Blender) via [CodingAdventures.org](http://codingadventures.org/)


## Credits
[Arjan Codes](https://www.youtube.com/channel/UCVhQ2NnY5Rskt6UjCUkJ_DA)