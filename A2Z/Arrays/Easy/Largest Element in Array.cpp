// ques link :->
// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1

// code
class Solution {
public:
  int largest(vector<int> &arr) {
    // code here
    int mx = 0;
    for (int i = 0; i < arr.size(); i++) {
      mx = max(mx, arr[i]);
    }
    return mx;
  }
};
