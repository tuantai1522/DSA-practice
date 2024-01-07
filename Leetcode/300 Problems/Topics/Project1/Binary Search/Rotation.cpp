// https://www.codingninjas.com/studio/problems/rotation_7449070?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

// 3 4 5 1 2 => ans = 3
// 4 5 1 2 3 => ans = 2

//=> to find idx of minimum value of array
int findKRotation(vector<int> &arr)
{
  int n = arr.size();
  int low = 0;
  int high = n - 1;

  int mini = 1e8;
  int idx = -1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[low] <= arr[mid])
    {
      if (arr[low] < mini)
      {
        mini = arr[low];
        idx = low;
      }
      low = mid + 1;
    }
    else
    {
      if (arr[mid] < mini)
      {
        mini = arr[mid];
        idx = mid;
      }
      high = mid - 1;
    }
  }

  return idx;
}