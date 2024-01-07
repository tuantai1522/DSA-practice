// https://www.codingninjas.com/studio/problems/unique-element-in-sorted-array_1112654?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

// 0 1 2 3 4 5 6
// 1 1 3 3 4 6 6

// ans = 4;

//(lẻ, chẵn)(0, 1): element is on the left half
//(chẵn, lẻ)(4, 5): element is on the right half

int singleNonDuplicate(vector<int> &arr)
{
  int n = arr.size();
  if (arr[0] != arr[1])
    return arr[0];

  if (arr[n - 1] != arr[n - 2])
    return arr[n - 1];

  int low = 1;
  int high = n - 2;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
      return arr[mid];

    // on the left
    if ((mid % 2 == 0 && arr[mid] == arr[mid + 1])     // at even idx => check next element
        || (mid % 2 == 1 && arr[mid] == arr[mid - 1])) // at odd idx => check before element
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return -1;
}