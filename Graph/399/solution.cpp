#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        unordered_map<string, unordered_map<string, double> > graph;
        vector<double> ret;
        
        /* fill the graph */
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            double value = values[i];
            graph[A][B] = value;
            graph[B][A] = 1.0 / value;
        }

        /* calculate result using DFS */
        for (auto &query : queries) {
            string a = query[0];
            string b = query[1];
            
            unordered_set<string> visited;
            double result = dfs(a, b, graph, visited);
            ret.push_back(result);
        }

        return ret;
    }

private: 
    double dfs(string &a, string &b, 
               unordered_map<string, unordered_map<string, double> > &graph,
               unordered_set<string> &visited) {
        if (graph.count(a) == 0 || graph.count(b) == 0) { return -1.0; }
        if (a == b) { return 1.0; }
        visited.insert(a);
        for (auto &pair : graph[a]) {
            string c = pair.first; // a / b = a / c * c / b
            if (visited.count(c)) { continue; }
            double d = 0.0;
            // d = c / b
            if (graph[c].count(b)) { d = graph[c][b]; }
            else { d = dfs(c, b, graph, visited); }
            if (d > 0.0) { return d * graph[a][c]; }
        }
        return -1.0;
    }
};

int main() {
    Solution s;
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = { {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} };
    vector<double> res = s.calcEquation(equations, values, queries);
    for (auto &r : res) { cout << r << " "; } cout << endl;
    return 0;
}