#include <chrono>
#include <iostream>
#include <string_view>
#include <thread>
#include <vector>

using namespace std;

string removeZero(vector<int> &num) {
  string ans;
  ans.clear();

  while (num.size() > 1 && num.front() == 0)
    num.erase(num.begin());
  for (auto x : num) {
    ans += x + '0';
  }

  return ans;
}

string multiply(string a, string b) {
  int m = a.size(), n = b.size();
  vector<int> num(m + n, 0);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      int sum = (b[i] - '0') * (a[j] - '0') + num[i + j + 1];
      num[i + j + 1] = sum % 10;
      num[i + j] += sum / 10;
    }
  }

  return removeZero(num);
}

string myPow(int a, int b) {
  vector<int> num(100, 0);
  num.back() = 1;
  int n = (int)num.size();
  for (int i = 0; i < b; ++i) {
    for (int j = n - 1; j >= 0; --j) {
      num[j] *= a;
    }
    for (int j = n - 1; j >= 0; --j) {
      if (num[j] >= 10) {
        num[j - 1] += num[j] / 10;
        num[j] %= 10;
      }
    }
  }

  return removeZero(num);
}

int converHexNumtToInt(const char x) {
  return ((x >= 'A' && (x <= 'F'))) ? 10 + (x - 'A') : x - '0';
}

string StringNumAdd(string_view a, string_view b) {
  int m = (int)a.size() - 1, n = (int)b.size() - 1, carry = 0;
  string ans;
  while (m >= 0 || n >= 0) {
    int num1 = m < 0 ? 0 : a[m] - '0';
    int num2 = n < 0 ? 0 : b[n] - '0';
    int sum = num1 + num2 + carry;
    ans += to_string(sum % 10);
    carry = sum / 10;
    m--;
    n--;
  }

  if (carry != 0)
    ans += to_string(carry - '0');
  while (ans.back() == '0')
    ans.pop_back();

  reverse(ans.begin(), ans.end());
  return ans;
}

string convert(string_view hex) {
  string ans = "";
  for (int n = hex.size(), i = 0; i < n; ++i) {
    int num = converHexNumtToInt(hex[i]);
    ans = StringNumAdd(ans, multiply(myPow(16, n - i - 1), to_string(num)));
  }

  return ans;
}

int main() {
  cout << convert("2F");

  return 0;
}
