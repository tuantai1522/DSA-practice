// https://www.codingninjas.com/studio/problems/binary-search_972?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

// Recursion

int f(vector<int> &nums, int n, int target, int low, int high)
{
  if (low > high)
    return -1;

  int mid = low + (high - low) / 2;
  if (nums[mid] == target)
    return mid;
  else if (nums[mid] > target)
    return f(nums, n, target, low, mid - 1);
  else
    return f(nums, n, target, mid + 1, high);
}
int search(vector<int> &nums, int target)
{
  int n = nums.size();
  return f(nums, n, target, 0, n - 1);
}

// Iterative

int search(vector<int> &nums, int target)
{
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    // to avoid overflow when low and high are INT_MAX
    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] > target)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}