#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> coins = {1, 3, 4};
    int amount = 7;

    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    cout << "Minimum number of coins = " << dp[amount] << endl;

    return 0;
}
