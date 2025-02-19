#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define endl "\n"
#define MAX 100000

using namespace std;

int dp1[MAX + 1];  // 1���� ����� �迭
int N, M;
int alp[26];
int ans;
vector<string> words;


void DFS(int idx, int remain){

    if(!remain){    //�� �̻� ���� �ܾ ���� ���
        int cnt = 0;
        for(auto word : words){

            bool flag = true;
            for(char ch : word){
                if(alp[ch-'a'] == 0){
                    flag = false;
                    break;
                }
            }

            if(flag){
                cnt++;
            }
            ans = max(ans,cnt);
            
        }
        return;
    }
    
    
    
    for(int i=idx; i<26; i++){  //��Ʈ��ŷ
        if(alp[i]==1) continue;
        alp[i] = 1;
        DFS(i,remain-1);
        alp[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    
    cin >> N >> M;
    if(M<5){
        cout<<0<<endl;
        return 0;
    }

    while(N--){
        string str;
        cin >> str;
        words.push_back(str);
    }

    alp['a'-'a'] = 1;
    alp['n'-'a'] = 1;
    alp['t'-'a'] = 1;
    alp['i'-'a'] = 1;
    alp['c'-'a'] = 1;

    DFS(0,M-5);
    cout << ans<< endl;
    return 0;
}
