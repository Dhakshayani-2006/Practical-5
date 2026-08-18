#include <iostream>
using namespace std;
int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    int weight[100], value[100];
    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    cout << "Enter capacity: ";
    cin >> capacity;
    int dp[100][100] = {0};
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weight[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            }
            else{
                dp[i][w] = max(
                    dp[i - 1][w],
                    value[i - 1] + dp[i - 1][w - weight[i - 1]]
                );
            }
        }
    }
    cout << "Maximum value = " << dp[n][capacity] << endl;
    return 0;
}
