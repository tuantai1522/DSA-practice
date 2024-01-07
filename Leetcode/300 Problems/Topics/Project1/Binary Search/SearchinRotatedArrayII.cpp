// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/submissions/1124709456/
bool search(vector<int> &arr, int x)
{
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] == x)
      return true;

    if (arr[low] == arr[mid] && arr[mid] == arr[high])
    {
      low++;
      --high;
      continue;
    }

    // right sorted
    if (arr[mid] <= arr[high])
    {
      if (arr[mid] <= x && x <= arr[high]) // on right
        low = mid + 1;
      else
        high = mid - 1;
    }
    // left sorted
    else
    {
      if (arr[low] <= x && x <= arr[mid]) // on right
        high = mid - 1;
      else
        low = mid + 1;
    }
  }
  return false;
}
