// https://www.codingninjas.com/studio/problems/rotated-array_1093219?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
int findMin(vector<int> &arr)
{
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int mini = 1e8;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    // if left array is sorted, min is the first element and then move
    // to the right array to find the minimum
    if (arr[low] <= arr[mid])
    {
      mini = min(mini, arr[low]);
      low = mid + 1;
    }
    else
    {
      mini = min(mini, arr[mid]);
      high = mid - 1;
    }
  }

  return mini;
}