// https://codingninjas.com/studio/problems/square-root-integral_893351?leftPanelTab=0%3Futm_source%3Dyoutube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

// n = 7 => sqrt(7) => 2.645 => ans = 2

// 1 2 3 4 5 6
int floorSqrt(int n)
{
  int low = 1;
  int high = n;
  while (low <= high)
  {
    long long int mid = (low + high) / 2;
    long long int temp = mid * mid;
    if (temp <= n)
    {
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  return high;
}
