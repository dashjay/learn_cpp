#include <algorithm>
#include <cassert>
#include <cctype>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

#define LOG(X)                                                                 \
  cout << X << endl;                                                           \
  cin.get();
// copy from <https://blog.csdn.net/yasi_xi/article/details/9216497>
inline string &ltrim(string &str) {
  string::iterator p =
      find_if(str.begin(), str.end(), not1(ptr_fun<int, int>(isspace)));
  str.erase(str.begin(), p);
  return str;
}
inline string &rtrim(string &str) {
  string::reverse_iterator p =
      find_if(str.rbegin(), str.rend(), not1(ptr_fun<int, int>(isspace)));
  str.erase(p.base(), str.end());
  return str;
}

inline string &trim(string &str) {
  ltrim(rtrim(str));
  return str;
}
// it is so hard for me to write a split func in cpp 2020 05 07
void readWords(string file) {
  // a file handle
  ifstream infile;
  // open the word list
  infile.open(file.data());
  assert(infile.is_open());

  // i use # to split english and chinese
  regex re("#");

  // like a buffer?
  string s;
  // split every line into 2 part by a #
  while (getline(infile, s)) {
    // copy from <https://www.zhihu.com/question/36642771>
    vector<string> v(sregex_token_iterator(s.begin(), s.end(), re, -1),
                     sregex_token_iterator());
    for (auto &&s : v) {
      LOG(trim(s))
    }
  }
}

int main() {
  string hello = "Hello Welcome to The Vocabulary, I will record all words I "
                 "don't know into this";
  LOG(hello)
  hello = "Press enter to get the Chinese,ok let's start!";
  LOG(hello)
  readWords("words.md");
  cout << "All Over! Good Job" << endl;
}
