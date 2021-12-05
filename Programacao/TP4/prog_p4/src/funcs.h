
#ifndef __funcs_h__ // {
#define __funcs_h__

//! \file funcs.h
#ifdef __cplusplus
extern "C" {
#endif

//! Convert hexadecimal string to integer.
//!
//! \param String formed by characters '0'-'9', 'A-F', 'a-f'
//! \return Corresponding integer
int hexstr_convert(const char str[]);

//! Enumeration for month values.
enum { 
  JANUARY = 1, 
  FEBRUARY,
  MARCH, 
  APRIL, 
  MAY, 
  JUNE, 
  JULY, 
  AUGUST, 
  SEPTEMBER, 
  OCTOBER, 
  NOVEMBER, 
  DECEMBER
};

//! Tells how many days a month has.
//!
//! \param int corresponding to the month
//! \param int corresponding to the year
//! \return Number of days of the month
int days_in_month(int m, int y);

double exp_taylor(double x, int n);

#ifdef __cplusplus
}
#endif

#endif // }
