// https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

// n = 3 m = 27 => ans = 3
// n = 4 m = 69 => ans = -1 (not an integer)

// 1 -> 69
// low = 1, high = 69, mid = 35 => val = 1500625
// low = 1, high = 34, mid = 17 => val = 83521
// low = 1, high = 16, mid = 9 => val = 4096
// low = 1, high = 8, mid = 4 => val = 256
// low = 1, high = 3, mid = 2 => val = 16
// low = 2, high = 3, mid = 2 => val = 16
// low = 3, high = 3, mid = 3 => val = 81
// low = 3, high = 2 => break

// 1 -> 27
// low = 1, high = 27, mid = 14 => val = 2744
// low = 1, high = 13, mid = 7 => val = 343
// low = 1, high = 6, mid = 3 => val = 27

// to calc whether pow(mid, n) equalts to m or not
int func(int mid, int n, int m)
{
  long long int ans = 1;

  for (int i = 1; i <= n; ++i)
  {
    ans *= mid;
    if (ans > m)
      return 2;
  }

  if (ans == m)
    return 1;

  return 0;
}

int NthRoot(int n, int m)
{
  int low = 1;
  int high = m;

  while (low <= high)
  {
    long long int mid = (low + high) / 2;
    long long int val = func(mid, n, m);

    if (val == 1) // val equals to m
      return mid;

    if (val == 0) // val is lower than m
      low = mid + 1;
    else // val is higher than m
      high = mid - 1;
  }
  return -1;
}