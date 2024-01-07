// https://www.codingninjas.com/studio/problems/aggressive-cows_1082559?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

bool func(vector<int> &stalls, int n, int cows, int dist)
{
  int countCows = 1;
  int last = stalls[0];

  for (int i = 1; i < n; ++i)
  {
    if (last + dist <= stalls[i])
    {
      ++countCows;
      last = stalls[i];
    }
    if (countCows >= cows)
      return true;
  }

  return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
  int n = stalls.size();
  sort(stalls.begin(), stalls.end());

  int low = 1;
  int high = stalls[n - 1];

  while (low <= high)
  {
    int mid = (low + high) / 2;
    bool check = func(stalls, n, k, mid);

    if (check)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return high;
}