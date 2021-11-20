//
// Created by bender on 20/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_SMS_AUTHORIZER_H_
#define SOLID_PRINCIPLES_INCLUDE_SMS_AUTHORIZER_H_
#include <string_view>
#include "spdlog/spdlog.h"

struct SMSAuthorizer {

  void VerifyCode(std::string_view code) {
    spdlog::debug("Verified SMS {0}", code);
    authorized_ = true;
  }

  [[nodiscard]] bool IsAuthorized() const {
    return authorized_;
  }

 private:
  bool authorized_{false};

};
#endif//SOLID_PRINCIPLES_INCLUDE_SMS_AUTHORIZER_H_
