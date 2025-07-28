// ques link :-> https://www.geeksforgeeks.org/problems/second-largest3735/1

class Solution {
public:
  int getSecondLargest(vector<int> &arr) {
    // code here
    int mx1 = -1;
    int mx2 = -1;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] > mx1) {
        mx2 = mx1;
        mx1 = arr[i];
      }
      if (arr[i] > mx2 && arr[i] < mx1) {
        mx2 = arr[i];
      }
    }
    return mx2;
  }
};