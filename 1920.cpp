#include <iostream>
#include <algorithm>

#define endl "\n"
#define MAX 100000

using namespace std;

int dp1[MAX + 1];  // 1���� ����� �迭
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {  // 1���� ����
        cin >> dp1[i];
    }

    // dp1[1]���� dp1[N]���� ���� (dp1[0]�� ����)
    sort(dp1 + 1, dp1 + N + 1);

    cin >> M;
    for (int i = 1; i <= M; i++) {
        int tar;
        cin >> tar;

        
        int start = 1, end = N, ans = 0;
        while (start <= end) {
            int mid = (start + end) / 2;

            if (dp1[mid] == tar) {
                ans = 1;
                break;
            }
            else if (tar < dp1[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
