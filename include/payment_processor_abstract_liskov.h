//
// Created by bender on 15/11/2021.
//

#ifndef SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_LISKOV_H_
#define SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_LISKOV_H_

struct PaymentProcessorAbstractLiskov {
  virtual void AuthSMS(std::string_view sms_code) = 0;
  virtual void Pay() const = 0;
  virtual void DisplayInfo() const = 0;
  virtual ~PaymentProcessorAbstractLiskov() = default;
};

#endif//SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_LISKOV_H_
