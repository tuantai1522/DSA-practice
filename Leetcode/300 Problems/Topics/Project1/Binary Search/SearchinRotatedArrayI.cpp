// https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTabValue=SUBMISSION
int search(vector<int> &arr, int n, int x)
{
  if (arr[0] == target)
    return 0;

  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] == x)
      return mid;

    // right sorted
    if (arr[mid] <= arr[high])
    {
      if (arr[mid] <= x && x <= arr[high]) // on right
        low = mid + 1;
      else
        high = mid - 1;
    }
    else
    {
      if (arr[low] <= x && x <= arr[mid]) // on right
        high = mid - 1;
      else
        low = mid + 1;
    }
  }
  return -1;
}