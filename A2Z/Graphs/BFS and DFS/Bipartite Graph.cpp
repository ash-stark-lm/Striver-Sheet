

class Solution {
public:
  bool isBipartite(vector<vector<int>> &graph) {
    // adj list is given
    // total Nodes= graph.size();
    int v = graph.size();
    vector<int> color(v, -1); // Initialise all node with color -1
    queue<int> q;
    for (int i = 0; i < v; i++) {
      if (color[i] == -1) {
        q.push(i);
        color[i] = 0;
      }

      // Now traverse the graph from nodes having color 0 and give its neighbour
      // opposite color

      while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto child : graph[node]) {
          if (color[child] == -1) {
            color[child] = !color[node];
            q.push(child);
          } else {
            if (color[child] == color[node]) // if color of child and parent
                                             // same -> not bipartite
              return false;
          }
        }
      }
    }

    return true;
  }
};