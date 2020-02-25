#include <iostream>

template <typename Iterator, typename object>
Iterator my_find(Iterator start, Iterator end, const object & x) {
  while (first != last) {
    if (*first == x) return first;
    first++;
  }
  return end;
}
