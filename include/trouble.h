//
// Created by bender on 10/11/2021.
//

#ifndef SOLID_PRINCIPLES_INCLUDE_TROUBLE_H_
#define SOLID_PRINCIPLES_INCLUDE_TROUBLE_H_

class Trouble : public std::exception {
 public:
  explicit Trouble(const char * message = "There's a problem") : m_message {message}{}
  [[nodiscard]] const char * what() const noexcept override { return m_message; }
 private:
  const char *m_message;
};

#endif//SOLID_PRINCIPLES_INCLUDE_TROUBLE_H_
