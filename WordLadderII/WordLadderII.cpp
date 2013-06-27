class Solution {
private:
    vector<string> vdict;
    vector<vector<int>> map;
    vector<vector<int>> prev;

    void buildMap(const unordered_set<string>& dict) {
        vdict.clear();
        unordered_map<string, int> unmap;
        for (auto iter = dict.begin(); iter != dict.end(); iter++) {
            unmap[*iter] = vdict.size();
            vdict.push_back(*iter);
        }
        
        map.clear();
        map.resize(vdict.size());
        for (size_t i = 0; i < vdict.size(); i++) {
            string word = vdict[i];
            for (size_t j = 0; j < word.size(); j++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == vdict[i][j]) continue;
                    word[j] = c;
                    if (unmap.count(word)) {
                        map[i].push_back(unmap[word]);
                    }
                    word[j] = vdict[i][j];
                }
            }
        }
    }

    void buildReverseMap(int src, int dst) {
        prev.clear();
        prev.resize(vdict.size());
        vector<int> dist(vdict.size());
        queue<int> Q;
        Q.push(src);
        dist[src] = 0;
        while (!Q.empty()) {
            src = Q.front(); Q.pop();
            if (src == dst) break;
            for (size_t i = 0; i < map[src].size(); i++) {
                int v = map[src][i];
                if (prev[v].size() == 0) {
                    prev[v].push_back(src);
                    dist[v] = dist[src] + 1;
                    Q.push(v);
                } else if (dist[v] == dist[src] + 1) {
                    prev[v].push_back(src);
                }
            }
        }
    }

    void dfs(int u, int v, vector<int>& path, vector<vector<string>>& result) {
        path.push_back(v);
        if (u == v && path.size()) {
            vector<string> pathstring;
            for (auto iter = path.rbegin(); iter != path.rend(); iter++) {
                pathstring.push_back(vdict[*iter]);
            }
            result.push_back(pathstring);
        } else {
            for (size_t i = 0; i < prev[v].size(); i++)
                dfs(u, prev[v][i], path, result);
        }
        path.pop_back();
    }
    
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        dict.insert(start);
        dict.insert(end);

        buildMap(dict);

        int src, dst;
        for (src = 0; start != vdict[src]; src++);
        for (dst = 0; end != vdict[dst]; dst++);

        buildReverseMap(src, dst);

        vector<vector<string>> result;
        vector<int> path;
        dfs(src, dst, path, result);
        return move(result);
    }
};
