//
// Created by bender on 20/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_ROBOT_AUTHORIZER_DI_H_
#define SOLID_PRINCIPLES_INCLUDE_ROBOT_AUTHORIZER_DI_H_
#include <string_view>
#include "spdlog/spdlog.h"
#include "authorizer_abstract.h"

struct NotARobotDI final : public Authorizer  {

  void VerifyCode() {
    spdlog::debug("Are you a robot? Naa");
    authorized_ = true;
  }

  [[nodiscard]] bool IsAuthorized() const override {
    return authorized_;
  }

 private:
  bool authorized_{false};

};
#endif//SOLID_PRINCIPLES_INCLUDE_ROBOT_AUTHORIZER_DI_H_
