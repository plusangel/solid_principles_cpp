//
// Created by bender on 15/11/2021.
//

#ifndef SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_H_
#define SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_H_

struct PaymentProcessorAbstract {
  virtual void Pay(std::string_view security_code) const = 0;
  virtual void DisplayInfo() const = 0;
  virtual ~PaymentProcessorAbstract() = default;
};

#endif//SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_H_
