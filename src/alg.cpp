// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  while (n > 0) {
    res *= value;
    n--;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  if (n == 1 || n == 0) {
    return 1;
  }
  else {
    return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 0;
  for (int i = 0; i <= count; i++) {
    sum += calcItem(x, i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sin = 0;
  for (int i = 1; i <= count; i++) {
    sin += pown(-1, i - 1) * calcItem(x, 2 * i - 1);
  }
  return sin;
}

double cosn(double x, uint16_t count) {
  double cos = 0;
  for (int i = 1; i <= count; i++) {
    cos += pown(-1, i - 1) * calcItem(x, 2 * i - 2);
  }
  return cos;
}
