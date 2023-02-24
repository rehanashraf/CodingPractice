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

/*
0 1
1 1
2 2
3 3
4 5
5 8
6 13
7 21
8 34
9 55
*/
// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
int getFibDynamic(int num)
{
    int rv = 0, f_1 = 1, f_n = 0;

    if (num < 0)
        return rv;
    
    if (num < 2) {
        return f_1;
    }
    
    for (int i = 2; i <= num; i++) {
        
    }

    
    
    
    return rv;
}
