class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int M = S.size();
        int N = T.size();
        
        if (M == 0 && N == 0)
            return 1;
        else if (M < N)
            return 0;
            
        int F[N+1];
        memset(F, 0, sizeof(int)*(N+1));
        F[0] = 1;
        for (int i = 1; i <= M; i++) {
            for (int j = N; j >= 1; j--) {
                if (S[i-1] == T[j-1])
                    F[j] = F[j-1] + F[j];
            }
        }
        return F[N];
    }
};