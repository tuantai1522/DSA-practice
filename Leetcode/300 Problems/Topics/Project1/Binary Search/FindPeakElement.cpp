// https://www.codingninjas.com/studio/problems/find-peak-element_1081482?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

// Peak element
// arr[i - 1] < arr[i] > arr[i + 1]
int findPeakElement(vector<int> &arr)
{
  int n = arr.size();
  if (n == 1)
    return 0;

  // at idx 0
  if (arr[0] > arr[1])
    return 0;

  // at idx n - 1;
  if (arr[n - 2] < arr[n - 1])
    return n - 1;

  int low = 1;
  int high = n - 2;

  while (low <= high)
  {
    if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
      return mid;

    if (arr[mid - 1] < arr[mid]) // on the left
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}
