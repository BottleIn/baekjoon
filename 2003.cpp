#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define MAX 10002

using namespace std;
typedef long long ll;

int N,M;
int l,r; // 왼쪽 오른쪽 포인터
int cnt, sum;
int num[MAX];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++){
        cin >> num[i];
    }

    sum = num[l];

    while(l<=r && r<=N){
        if(sum == M){
            cnt++;
            sum += num[++r];
        }
        else if( sum < M){
            sum += num[++r];
        }
        else if( sum > M){
            sum -= num[l++];
        }

        if (l > r) {        // 오름차순이 아니므로 넘어가면 리셋하기
			r = l;
			sum = num[l];
		}

    }


    cout << cnt << endl;

    return 0;
}
