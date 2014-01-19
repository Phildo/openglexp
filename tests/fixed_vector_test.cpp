#include "fixed_vector_test.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include <iostream>

#include "../src/fixed_vector.h"

FixedVectorTest::FixedVectorTest()
{
}

FixedVectorTest::~FixedVectorTest()
{
}

class TestObj
{
  private:
    int x;
    int y;
  public:
    TestObj();
    ~TestObj();
};
TestObj::TestObj(){}
TestObj::~TestObj(){}

void FixedVectorTest::runTests()
{
  FixedVector<TestObj, 10> x;
  //std::cout << "fixed_vector_test : TEST PASSED!" << std::endl;
}

