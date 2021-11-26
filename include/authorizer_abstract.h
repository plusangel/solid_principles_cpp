//
// Created by bender on 26/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_AUTHORIZER_ABSTRACT_H_
#define SOLID_PRINCIPLES_INCLUDE_AUTHORIZER_ABSTRACT_H_

struct Authorizer {
  [[nodiscard]] virtual bool IsAuthorized() const = 0;
  virtual ~Authorizer() = default;
};

#endif//SOLID_PRINCIPLES_INCLUDE_AUTHORIZER_ABSTRACT_H_
