#include <iostream>

template <typename Iterator, typename object>
Iterator my_find(Iterator start, Iterator end, const object & x) {
  while (start != end) {
    if (*start == x) {
      return start;
    }
    start++;
  }
  return end;
}
