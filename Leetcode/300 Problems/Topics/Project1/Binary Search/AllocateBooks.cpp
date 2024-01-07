// https://www.codingninjas.com/studio/problems/allocate-books_1090540?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
bool func(vector<int> &arr, int n, int students, int totalPages)
{
  int countStudents = 1;
  long long int total = arr[0];

  for (int i = 1; i < n; ++i)
  {
    if (total + arr[i] <= totalPages)
      total += arr[i];
    else
    {
      ++countStudents;
      total = arr[i];
    }
  }

  return countStudents > students;
}

int findPages(vector<int> &arr, int n, int students)
{
  if (students > n)
    return -1;

  int maxi = INT_MIN;
  int total = 0;

  for (int i = 0; i < n; ++i)
  {
    maxi = max(maxi, arr[i]);
    total += arr[i];
  }

  int low = maxi;
  int high = total;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    bool check = func(arr, n, students, mid);

    if (check)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return low;
}