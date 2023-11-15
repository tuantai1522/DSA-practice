// https://leetcode.com/problems/partition-equal-subset-sum/description/?fbclid=IwAR19NcLZV33oD7G6i0STeTZqSDYm-EBDGj11cIzdGKkSTH9qbebuRFWmSu4
using namespace std;
bool canPartitionHelper(vector<int> &nums, int n, int index, int total_1, int total_2)
{
  if (index >= n)
  {
    return false;
  }
  if (total_1 == total_2)
    return true;

  canPartitionHelper(nums, n, index + 1, total_1 + nums[index], total_2);
  canPartitionHelper(nums, n, index + 1, total_1, total_2 + nums[index]);
  ++index;
}
bool canPartition(vector<int> &nums)
{
  int n = nums.size();
  return canPartitionHelper(nums, n, 0, 0, 0);
}