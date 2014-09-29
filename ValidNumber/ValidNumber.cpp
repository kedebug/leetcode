// NFA
class Solution {
public:
    bool accept(const char* s, int& i, string expected) {
        for (int j = 0; j < expected.size(); j++) {
            if (s[i] == expected[j]) {
                i += 1;
                return true;
            }
        }
        return false;
    }
    
    bool acceptRun(const char* s, int& i, string expected) {
        bool found = false;
        int count = 0;
        while (s[i] != '\0') {
            found = false;
            for (int j = 0; j < expected.size(); j++) {
                if (s[i] == expected[j]) {
                    i++;
                    count++;
                    found = true;
                }
            }
            if (!found) {
                break;
            }
        }
        if (count > 0) {
            return true;
        }
        return false;
    }

    bool isNumber(const char *s) {
        string digits("0123456789");
        
        int i = 0;
        
        acceptRun(s, i, " ");
        
        bool beforedot = false;
        bool afterdot = false;
        
        accept(s, i, "+-");
        beforedot = acceptRun(s, i, digits);
        
        if (accept(s, i, ".")) {
            if (acceptRun(s, i, digits)) {
                afterdot = true;
            }
        }
        
        if (!beforedot && !afterdot) {
            return false;
        }
        
        if (accept(s, i, "eE")) {
            accept(s, i, "+-");
            if (!acceptRun(s, i, digits)) {
                return false;
            }
        }
   
        while (s[i] != '\0') {
            if (s[i] != ' ') {
                return false;
            }
            i++;
        }
        return true;
    }
};
