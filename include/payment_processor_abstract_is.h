//
// Created by bender on 15/11/2021.
//

#ifndef SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_IS_H_
#define SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_IS_H_

struct PaymentProcessorAbstractIS {
  virtual void Pay() const = 0;
  virtual void DisplayInfo() const = 0;
  virtual ~PaymentProcessorAbstractIS() = default;
};

#endif//SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_IS_H_
