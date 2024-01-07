// https://www.codingninjas.com/studio/problems/lower-bound_8165382?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

//"lower_bound" of a number "x" is defined as the smallest index such
// that arr[idx] >= x

// Recursion
void f(vector<int> arr, int n, int x, int low, int high, int &ans)
{
  if (low > high)
    return;

  int mid = (low + high);
  if (arr[mid] >= x) // this is ans
  {
    ans = mid;

    f(arr, n, x, low, mid - 1, ans);
  }
  else
    f(arr, n, x, mid + 1, high, ans);
}
int lowerBound(vector<int> arr, int n, int x)
{
  int ans = n;
  f(arr, n, x, 0, n - 1, ans);
  return ans;
}

// Iterative
int lowerBound(vector<int> arr, int n, int x)
{
  int ans = n;
  int low = 0;
  int high = n - 1;

  while (low <= high)
  {
    int mid = (low + high);
    if (arr[mid] >= x) // this is ans
    {
      ans = mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return ans;
}

// https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

//"upper_bound" of a number "x" is defined as the smallest index such
// that arr[idx] > x
// Recursion
void f(vector<int> arr, int n, int x, int low, int high, int &ans)
{
  if (low > high)
    return;

  int mid = (low + high) / 2;
  if (arr[mid] > x) // this is ans
  {
    ans = mid;
    f(arr, n, x, low, mid - 1, ans);
  }
  else
    f(arr, n, x, mid + 1, high, ans);
}

int upperBound(vector<int> &arr, int x, int n)
{
  int ans = n;
  f(arr, n, x, 0, n - 1, ans);
  return ans;
}

// Iterative
int upperBound(vector<int> &arr, int x, int n)
{
  int ans = n;
  int low = 0;
  int high = n - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] > x) // this is ans
    {
      ans = mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return ans;
}

// https://www.codingninjas.com/studio/problems/algorithm-to-find-best-insert-position-in-sorted-array_839813?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

/*
0 1 2 3
1 3 4 7
6

low = 0; high = 3 => mid = 1;
arr[mid] < 6 => low = mid + 1

low = 1; high = 3 => mid = 2
arr[mid] < 6 => low = mid + 1

low = 2; high = 3 => mid = 2;
arr[mid] < 6 => low = mid + 1

low = 3; high = 3 => mid = 3;
arr[mid] > 6 => high = 2; ans = 3;
*/
int searchInsert(vector<int> &arr, int m)
{
  int n = arr.size();

  int low = 0;
  int high = n - 1;
  int ans = n;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == m)
      return mid;
    else if (arr[mid] > m)
    {
      high = mid - 1;
      ans = mid;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

// https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401

// 6 2
// 0 1 2 3 4  5
// 3 4 4 7 8 10
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x)
{
  pair<int, int> ans = {-1, -1};

  int low = 0;
  int high = n - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
      ans.first = ans.second = arr[mid];
      return ans;
    }
    else if (arr[mid] < x)
    {
      low = mid + 1;
      ans.first = arr[mid];
    }
    else
    {
      high = mid - 1;
      ans.second = arr[mid];
    }
  }
  return ans;
}