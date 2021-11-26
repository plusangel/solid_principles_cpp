//
// Created by bender on 20/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_SMS_AUTHORIZER_DI_H_
#define SOLID_PRINCIPLES_INCLUDE_SMS_AUTHORIZER_DI_H_
#include <string_view>
#include "spdlog/spdlog.h"
#include "authorizer_abstract.h"

struct SMSAuthorizerDI final : public Authorizer  {

  void VerifyCode(std::string_view code) {
    spdlog::debug("Verified SMS {0}", code);
    authorized_ = true;
  }

  [[nodiscard]] bool IsAuthorized() const override {
    return authorized_;
  }

 private:
  bool authorized_{false};

};
#endif//SOLID_PRINCIPLES_INCLUDE_SMS_AUTHORIZER_DI_H_
