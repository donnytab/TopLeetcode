// 模拟法
class Solution {
    public:
        string validIPAddress(string queryIP) {
            char delimiter = ':';
            if(queryIP.find('.') != string::npos) {
                delimiter = '.';
            }
            vector<string> ip = split(queryIP, delimiter);
            if(isIPV4(ip)) {
                return "IPv4";
            }
            if(isIPV6(ip)) {
                return "IPv6";
            }
            return "Neither";
        }

        bool isIPV4(vector<string>& vec) {
            if(vec.size() != 4) {
                return false;
            }
            for(int i = 0; i < 4; i++) {
                // 检查前导零
                if(vec[i].size() > 1 && vec[i][0] == '0') {
                    return false;
                }
                // 检查长度
                if(vec[i].size() == 0 || vec[i].size() > 3) {
                    return false;
                }
                for(int j = 0; j < vec[i].size(); j++) {
                    // 检查是否每个段都由0-9组成
                    if(!('0' <= vec[i][j] && vec[i][j] <= '9')) {
                        return false;
                    }
                }
                // 检查数字范围是否合法
                int num = stoi(vec[i]);
                if(num < 0 || num > 255) {
                    return false;
                }
            }
            return true;
        }

        bool isIPV6(vector<string>& vec) {
            if(vec.size() != 8) {
                return false;
            }
            for(int i = 0; i < 8; i++) {
                // 检查长度
                if(vec[i].size() == 0 || vec[i].size() > 4) {
                    return false;
                }
                for(int j = 0; j < vec[i].size(); j++) {
                    // 检查是否每个段都由a-f或A-F或0-9组成
                    if(!(('A' <= vec[i][j] && vec[i][j] <= 'F') || ('a' <= vec[i][j] && vec[i][j] <= 'f') || ('0' <= vec[i][j] && vec[i][j] <= '9'))) {
                        return false;
                    }
                }
            }
            return true;
        }

        vector<string> split(string& s, char delimiter) {
            int n = s.size(), l = 0;
            vector<string> ans;
            for(int r = 0; r < n; r++) {
                if(s[r] == delimiter) {
                    ans.push_back(s.substr(l, r - l));
                    l = r + 1;
                }
            }
            ans.push_back(s.substr(l, n - l));
            return ans;
        }
};




// REGEX
regex ipv4("^(?:(?:25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)($|(?!\\.$)\\.)){4}$");
regex ipv6("^(?:(?:[\\da-fA-F]{1,4})($|(?!:$):)){8}$");
class Solution {
    public:
    string validIPAddress(string queryIP) {
            if (regex_search(queryIP, ipv4)) return "IPv4";
            else if (regex_search(queryIP, ipv6)) return "IPv6";
            else return "Neither";
        }
};
