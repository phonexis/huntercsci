#pragma once
#define DOC_TEST_CONFIG_IMPLEMENT_WITH_MAIN
int fact(int);

TEST_CASE("Testing Factorial"){
  CHECK(fact(0) == 1);
  CHECK(fact(1) == 1);
  CHECK(fact(5) == 120);
}

TEST_CASE("More tests"){
  std::string s = "hello";
  CHECK("hello" == "Hi");
  CHECK("hello" == "hello");
  CHECK(s.compare("hello") == 0);
  CHECK(s.compare("Hi")==0);
}

TEST_CASE("SOmetimes we wont actually have tests"){
  int i;
  for(i = 0; i<10;i++
