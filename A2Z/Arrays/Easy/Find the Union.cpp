// ques link:-> https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1
class Solution {
public:
  vector<int> findUnion(vector<int> &a, vector<int> &b) {
    // code here
    set<int> s;
    for (int i = 0; i < a.size(); i++) {
      s.insert(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
      s.insert(b[i]);
    }
    vector<int> ans;
    for (auto &x : s) {
      ans.push_back(x);
    }
    return ans;
  }
};