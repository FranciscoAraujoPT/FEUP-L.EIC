#include <math.h>
#include "funcs.h"

int hexstr_convert(const char h[]) {
  int r = 0;
  int pos = 0;
  while (h[pos] != '\0') {
    char c = h[pos];
    int v ;
    if (c >= '0'      // c1
    && c <= '9') {    // c2
      v = c - '0';
    }
    else if (c >= 'A'     // c2 
          && c <= 'F') {  // c3
      v = c + 10 - 'A';
    }
    else {
      v = c + 10 - 'a';
    }
    r = r * 16 + v; 
    pos++;
  }
  return r;
}


int days_in_month(int m, int y) {
  int r;
  switch (m) {
    case FEBRUARY:
      if ( y % 4 == 0 &&
             ( y % 100 != 0 
            || y % 400 == 0)) {
        r = 29;
      } else {
        r = 28;
      }
      break;
    case JANUARY: case MARCH: case MAY: 
    case JULY: case AUGUST: case OCTOBER: 
    case DECEMBER:
      r = 31;
      break;
    default:
      r = 30; 
      break;
  }
  return r;
}

long factorial(int n)
{
    int c;
    long result = 1;

    for (c = 1; c <= n; c++){
        result = result * c;
    }

    return result;
}

double exp_taylor(double x, int n) {
    if(n < 0){
        return -1;
    }

    long double res = 1;
    while(n > 0) {
        res += (pow(x, n)/ factorial(n));
        n--;
    }
    return res;
}

