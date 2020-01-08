// Copyright 2019 Fedorov james.sayfer2015@yandex.ru
#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <ctime>
#include <iostream>
#include <vector>
#include <stdlib.h>

#define repA(x) x x x x x x x x x x
#define repB(x) \
	repA(x) repA(x) repA(x) \
	repA(x) repA(x) repA(x) \
	repA(x) repA(x) repA(x) repA(x)
#define repC(x) \
  repB(x) repB(x) repB(x) \
  repB(x) repB(x) repB(x) \
  repB(x) repB(x) repB(x) repB(x)
#define repD(x) \
  repC(x) repC(x) repC(x) \
  repC(x) repC(x) repC(x) \
  repC(x) repC(x) repC(x) repC(x)
#define repE(x) \
  repD(x) repD(x) repD(x) \
  repD(x) repD(x) repD(x) \
  repD(x) repD(x) repD(x) repD(x)

double prExp(size_t, size_t);

double revExp(size_t, size_t);

double oddExp(size_t, size_t);

int* buildRandArr(size_t, size_t);

void outputResult();

#endif // INCLUDE_HEADER_HPP_
