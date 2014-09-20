class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        unordered_map<string, bool> visited;
        map<string, string> steps;

        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            string u = q.front();
            q.pop();
            if (u == end) {
                int count = 1;
                while (steps.find(u) != steps.end()) {
                    u = steps[u];
                    count++;
                }
                return count;
            }
            string v = u;
            for (int i = 0; i < v.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    v[i] = c;
                    if (visited.find(v) == visited.end() 
                        && dict.find(v) != dict.end()) {
                        visited[v] = true;
                        steps[v] = u;
                        q.push(v);
                    }
                }
                v[i] = u[i];
            }
        }
        return 0;
    }
};
