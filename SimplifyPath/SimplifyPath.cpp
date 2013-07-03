class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<string> path_stack;
        int i = 0;
        while (i < path.size()) {
            while (i < path.size() && path[i] == '/') i += 1;
            if (i == path.size()) break;
            string directory;
            while (i < path.size() && path[i] != '/') {
                directory += path[i];
                i += 1;
            }
            if (directory == "..") {
                if (!path_stack.empty())
                    path_stack.pop_back();
            }
            else if (directory != ".") {
                path_stack.push_back(directory);
            }
        }
        if (path_stack.empty()) 
            return "/";
        string simplified_path;
        for (int i = 0; i < path_stack.size(); i++)
            simplified_path += "/" + path_stack[i];
        return simplified_path;
    }
};