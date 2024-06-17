#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

constexpr auto kMod = ll{1000000009};
constexpr auto kMax = ll{1000000};

ll t, n;
vl dp(kMax + 1, 0);

ll solve(ll x) {
  if (0 == dp[x]) {
    dp[x] = (solve(x - 3) + solve(x - 2)) % kMod + solve(x - 1);
    dp[x] %= kMod;
  }

  return dp[x];
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> t;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  while (0 < (t--)) {
    cin >> n;
    cout << solve(n) << '\n';
  }

  return 0;
}