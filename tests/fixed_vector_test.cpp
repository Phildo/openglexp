#include "fixed_vector_test.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "../src/fixed_vector.h"

class TestObj
{
  private:
  public:
    int x;
    int y;
    TestObj();
    ~TestObj();
};
TestObj::TestObj():x(0),y(2){}
TestObj::~TestObj(){}

FixedVectorTest::FixedVectorTest()
{
}

FixedVectorTest::~FixedVectorTest()
{
}

void FixedVectorTest::runTests()
{
  FixedVector<TestObj, 10> x;
  if(x.size != 0) std::cout << "fixed_vector_test : TEST 1 FAILED " << std::endl;
  x.make();
  if(x.size != 1) std::cout << "fixed_vector_test : TEST 2 FAILED " << std::endl;
  x.make();
  if(x.size != 2) std::cout << "fixed_vector_test : TEST 3 FAILED " << std::endl;
  x[1].x = 4;
  if(x[0].x != 0) std::cout << "fixed_vector_test : TEST 4 FAILED " << std::endl;
  if(x[1].x != 4) std::cout << "fixed_vector_test : TEST 5 FAILED " << std::endl;
  x.pop();
  if(x.size != 1) std::cout << "fixed_vector_test : TEST 6 FAILED " << std::endl;
  if(x[0].x != 0) std::cout << "fixed_vector_test : TEST 7 FAILED " << std::endl;
  x.make();
  if(x.size != 2) std::cout << "fixed_vector_test : TEST 8 FAILED " << std::endl;
  x[1].x = 1;
  x.remove(0);
  if(x.size != 1) std::cout << "fixed_vector_test : TEST 9 FAILED " << std::endl;
  if(x[0].x != 1) std::cout << "fixed_vector_test : TEST 10 FAILED " << std::endl;

  std::cout << "fixed_vector_test : TEST PASSED!" << std::endl;
}

