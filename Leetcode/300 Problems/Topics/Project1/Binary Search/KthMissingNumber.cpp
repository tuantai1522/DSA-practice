// https://www.codingninjas.com/studio/problems/kth-missing-element_893215?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
int missingK(vector<int> arr, int n, int k)
{
  int low = 0;
  int high = n - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    int missing = arr[mid] - (mid + 1);

    if (missing < k)
      low = mid + 1;
    else
      high = mid - 1;
  }

  // high pointer on left and low pointer on right
  return k + (high + 1);
}
