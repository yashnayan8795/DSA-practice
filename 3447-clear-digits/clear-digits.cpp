class Solution {
 public:
  string clearDigits(string s) {
    string a;
    for(const char c:s)
        if(isdigit(c))
            a.pop_back();
        else
            a += c;

    return a;

  }
};