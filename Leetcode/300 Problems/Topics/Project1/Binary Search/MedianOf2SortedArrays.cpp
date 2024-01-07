double median(vector<int> &a, vector<int> &b)
{
  int m = a.size();
  int n = b.size();
  int length = (m + n + 1) / 2;

  int low = 0;
  int high = min(m, n);

  while (low <= high)
  {
    int mid = (low + high) / 2;

    int l1 = INT_MIN;
    int l2 = INT_MIN;
    int r1 = INT_MAX;
    int r2 = INT_MAX;

    l1 = a[mid - 1];
    r1 = a[mid];

    l2 = b[length - mid - 1];
    r2 = b[length - mid];

    if (l1 > r2)
      high = mid - 1;
    else if (l1 > r2)
      low = mid + 1;
    else
      return max(l1, l2) + min(r1, r2) / 2.0;
  }
  return 0;
}