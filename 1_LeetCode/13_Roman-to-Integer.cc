

// 2020-09-24
class Solution {
public:
    int romanToInt(string s) {
        int n = (int)s.size();
        int res = 0;
        
        for (int i = 0; i < n; i++){
            if (s[i] == 'V') res+= 5;
            else if (s[i] == 'L') res += 50;
            else if (s[i] == 'D') res += 500;
            else if (s[i] == 'M') res += 1000;
            else if (s[i] == 'C'){
                if (i+1 < n && s[i+1] == 'D') res += 400, i++;
                else if (i+1 < n && s[i+1] == 'M') res += 900, i++;
                else res += 100;
            }
            else if (s[i] == 'X'){
                if (i+1 < n && s[i+1] == 'L') res += 40, i++;
                else if (i+1 < n && s[i+1] == 'C') res += 90, i++;
                else res += 10;
            }
            else{
                if (i + 1 < n && s[i+1] == 'V') res += 4, i++;
                else if (i+1 < n && s[i+1] == 'X') res += 9, i++;
                else res++;
            }
        }
        
        return res;
    }
};


class Solution {
public:
  int romanToInt(string s) {
    map<char, int> m{{'I', 1}, {'V', 5}, 
                     {'X', 10}, {'L', 50},
                     {'C', 100}, {'D', 500},
                     {'M', 1000}};
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
      ans += m[s[i]];
      if (i > 0 && m[s[i]] > m[s[i - 1]])
        ans -= 2 * m[s[i - 1]];
    }
    return ans;
  }
};