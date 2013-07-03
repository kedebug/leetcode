class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<string> addresses;
        string ip_address;
        restoreIpAddressesHelper(s, 0, 0, ip_address, addresses);
        return addresses;
    }
    
    void restoreIpAddressesHelper(string& s, int position, 
        int blocks, string& ip_address, vector<string>& addresses) {
        
        if (position == s.size() && blocks == 4) {
            addresses.push_back(ip_address);
            return;
        }

        // some pruning skills;
        if (blocks >= 4) return;
        if ((4-blocks) * 3 < s.size() - position) return;
        if ((4-blocks) * 3 == s.size() - position) {
            for (int i = 0; i < 4 - blocks; i += 3)
                if (s[position + i] > '2') return;
        }
        
        int ip = 0;
        int ip_length = ip_address.size();
        for (int i = position; i < s.size(); i++) {
            ip *= 10;
            ip += s[i] - '0';
            if (ip > 255) break;
            if (blocks != 0 && i == position)
                ip_address += '.';
            ip_address += s[i];
            restoreIpAddressesHelper(s, i + 1, blocks + 1, ip_address, addresses);
            if (ip == 0) break;
        }
        // pass-by-reference is more effective than pass-by-value
        ip_address.erase(ip_length, ip_address.size() - ip_length);
    }
};