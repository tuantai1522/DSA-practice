// https://leetcode.com/problems/n-th-tribonacci-number/description/
int tribonacci(int n)
{
  if (n == 0)
    return 0;
  if (n == 1 || n == 2)
    return 1;
  int first = 0;
  int second = 1;
  int third = 1;
  int cur;

  for (int i = 3; i <= n; ++i)
  {
    cur = first + second + third;
    first = second;
    second = third;
    third = cur;
  }
  return cur;
}