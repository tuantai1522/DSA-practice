// https://www.codingninjas.com/studio/problems/minimise-max-distance_7541449?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

// Iterative
double minimiseMaxDistance(vector<int> &arr, int k)
{
  int n = arr.size();

  vector<int> diff(n - 1, 0);
  vector<int> count(n - 1, 0);

  for (int i = 0; i < n - 1; ++i)
    diff[i] = arr[i + 1] - arr[i];

  for (int gas = 1; gas <= k; ++gas)
  {
    long double maxi = -1;
    long double idxMax = -1;
    for (int i = 0; i < n - 1; ++i)
    {
      long double length = diff[i] * 1.0 / (count[i] + 1);

      if (length > maxi)
      {
        maxi = length;
        idxMax = i;
      }
    }
    count[idxMax]++;
  }

  long double ans = -1;
  for (int i = 0; i < n - 1; ++i)
  {
    ans = max(ans, diff[i] / (long double)(count[i] + 1));
  }

  return ans;
}

// Priority queue
double minimiseMaxDistance(vector<int> &arr, int k)
{
  int n = arr.size();

  priority_queue<pair<long double, int>> maxHeap;

  vector<int> diff(n - 1, 0);
  vector<int> count(n - 1, 0);

  for (int i = 0; i < n - 1; ++i)
  {
    diff[i] = arr[i + 1] - arr[i];
    maxHeap.push({arr[i + 1] - arr[i], i});
  }

  for (int gas = 1; gas <= k; ++gas)
  {
    int idxMax = maxHeap.top().second;
    maxHeap.pop();

    count[idxMax]++;

    long double newDiff = diff[idxMax] * 1.0 / (count[idxMax] + 1);
    maxHeap.push({newDiff, idxMax});
  }

  return maxHeap.top().first;
}
