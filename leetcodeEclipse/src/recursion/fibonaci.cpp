/*
 * fibonaci.cpp
 *
 *  Created on: Oct 12, 2020
 *      Author: rehanashraf
 */


/*
 * f(0) = 0
 * f(1) = 1
 * f(n) = f(n-1) + f(n-2)
*/

// Using recursion
int getFib(int n)
{
  if (n <= 1)
    return 1;
  return getFib(n-1) + getFib(n-2);
}

// using 2 variables Dynamic Programming
int getFib2(int n)
{
  int f0, rv1, fn;

  f0 = 0;
  rv1 = 1;

  if (n == 0)
    return f0;

  for (int i = 2; i <= n; i++)
  {
    fn = f0 + rv1;
    f0 = rv1;
    rv1 = fn;
  }
  return rv1;
}
