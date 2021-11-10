//
// Created by bender on 10/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_TROUBLE_H_
#define SOLID_PRINCIPLES_INCLUDE_TROUBLE_H_
class Trouble {
 public:
  explicit Trouble(std::string_view message = "There's a problem") : m_message {message}{}
  [[nodiscard]] std::string_view what() const { return m_message; }
 private:
  std::string m_message;
};

#endif//SOLID_PRINCIPLES_INCLUDE_TROUBLE_H_
