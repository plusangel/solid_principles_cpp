//
// Created by bender on 15/11/2021.
//

#ifndef SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_OC_H_
#define SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_OC_H_

struct PaymentProcessorAbstractOC {
  virtual void Pay(std::string_view security_code) const = 0;
  virtual void DisplayInfo() const = 0;
  virtual ~PaymentProcessorAbstractOC() = default;
};

#endif//SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_OC_H_
