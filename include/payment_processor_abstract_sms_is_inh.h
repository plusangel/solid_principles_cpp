//
// Created by bender on 15/11/2021.
//

#ifndef SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_SMS_IS_INH_H_
#define SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_SMS_IS_INH_H_
#include "payment_processor_abstract_is.h"

struct PaymentProcessorAbstractSMS : public PaymentProcessorAbstractIS {
  virtual void AuthSMS(std::string_view sms_code) = 0;
};

#endif//SOLID_PRINCIPLES__PAYMENT_PROCESSOR_ABSTRACT_SMS_IS_INH_H_
