/**
 * @file type_name.cpp
 * @author Zsbyqx2020
 * @brief Some related code in the tutorial.
 * @version 0.1
 * @date 2022-02-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#define _GLIBCXX_USE_CXX11_ABI 0
#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#include <cxxabi.h>
#endif
#include <string.h>

#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
template <class T>
void type_name(std::string name) {
  typedef typename std::remove_reference<T>::type TR;
  std::unique_ptr<char, void (*)(void *)> own(
#ifndef _MSC_VER
      abi::__cxa_demangle(typeid(TR).name(), nullptr, nullptr, nullptr),
#else
      nullptr,
#endif
      std::free);
  std::string r = own != nullptr ? own.get() : typeid(TR).name();
  if (std::is_const<TR>::value) r += " const";
  if (std::is_volatile<TR>::value) r += " volatile";
  if (std::is_lvalue_reference<T>::value)
    r += "&";
  else if (std::is_rvalue_reference<T>::value)
    r += "&&";
  std::cout << "delctype of " << name << " is: " << r << std::endl;
}
int main() {
  // About 'constexpr'
  // 指向整型常量的指针
  const int *p1 = nullptr;
  type_name<decltype(p1)>("p1");

  // 指向整数的常量指针
  int *const p2 = nullptr;
  constexpr int *q1 = nullptr;
  type_name<decltype(p2)>("p2");
  type_name<decltype(q1)>("q1");

  // 指向整形常量的常量指针
  const int *const p3 = nullptr;
  constexpr const int *q2 = nullptr;
  type_name<decltype(p3)>("p3");
  type_name<decltype(q2)>("q2");

  // About 'auto'
  // 关于引用
  int i = 0, &r = i;
  auto a = r;
  type_name<decltype(a)>("a");

  // 忽略顶层const
  const int ci = 0, &cr = ci;
  auto b = ci;
  auto c = cr;
  type_name<decltype(b)>("b");
  type_name<decltype(c)>("c");

  // 保留底层const
  auto d = &i;
  auto e = &ci;
  const auto f = ci;
  type_name<decltype(d)>("d");
  type_name<decltype(e)>("e");
  type_name<decltype(f)>("f");

  // const引用绑定
  auto &g = ci;
  const auto &j = 42;
  type_name<decltype(g)>("g");
  type_name<decltype(j)>("j");

  // 范围for语句
  std::vector<int> v = {1, 2, 3, 4, 5, 6};
  for (auto &r : v) r *= 2;
  for (auto i : v) std::cout << i << " ";
}