#include <iostream>
#include <vector>

using namespace std;

// nums is alread sorted and then rotated
// target is the number we are searching in nums
int search(vector<int>& nums, int target) {
  if (nums.size() == 0)
    return -1;
  if (nums.size() == 1) {
    if (nums[0] == target)
      return 0;
    else
      return -1;
  }

  int front, back, mid_index, mid;

  // check if nums is rotated

  // Search 0
  // [4,5,6,7,0,1,2]
  // [6,0,1,2,3,4,5]
  // [6,7,8,1,2,3,4]

  // Search 3
  // [5,6,7,0,1,2,3,4]
  // [7,8,0,1,2,3,4,5]
  // [8,1,3,4,5,6,7,7.5]

  for (int i = 0, j = nums.size() - 1; i <= j; i++, j--) {
    front = nums[i];
    back = nums[j];
    mid_index = (i + j) / 2;
    mid = nums[mid_index];

    // cout << " i: " << i << " j: " << j << " mid: " << mid_index << endl;

    if (front == target)
      return i;
    else if (back == target)
      return j;
    else if (mid == target)
      return mid_index;

    if (front < back) {
      // subarray is not rotated
      if (mid < target) {
        i = mid_index;
      } else {
        j = mid_index;
      }
    } else if (front > back) {
      // subarry is rotated
      if (((mid > front) && (front > target)) || ((mid < back) && (mid < target) && (back > target)) || ((front < mid) && (back < mid) && (mid < target))) {
        i = mid_index;
      } else if (((mid > target) && (back > target) && (back > mid)) || ((mid < target) && (back < target) && (back > mid))) {
        j = mid_index;
      }

      // cout << "*i: " << i << " j: " << j << " mid: " << (i + j) / 2 << endl;

    } else {
      // array does not have distinct values
      return -1;
    }
  }

  return -1;
}

int main(int argc, char const* argv[]) {
  // vector<int> numbers = {8, 9, 2, 3, 4};
  // int t = 9;

  vector<int> numbers = {4, 5, 6, 7, 8, 1, 2, 3};
  int t = 8;

  cout << search(numbers, t) << endl;
  return 0;
}
