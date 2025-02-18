#include <iostream>
#include <algorithm>
#include <queue>


#define endl "\n"
#define MAX 100

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int vote[MAX + 1];
int N, M;
int full;
int order[MAX+1];


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    cin >> N >> M;

    for (int i = 1; i <= M; i++){
        int student;
        cin >> student;

        if(full < N){ //아직 틀이 다 안 찼을 때
            vote[student]++;

            if(order[student]) continue; //이미 틀 안에 존재
            
            else{   //틀 안에 없을 경우
                order[student] = i;
                full++;
            }
        }

        else{ // 틀이 다 찼을 경우
            int min_vote = 1001;
            int oldest = 1001;
            int target;
            
            if(order[student]) {
                vote[student]++;
                continue;
            }
           
            else{ // 틀에 존재 X
               
                for(int i=1; i<=MAX; i++){

                    if(vote[i] == min_vote){ //같은 투표
                        if(order[i] < oldest){
                            min_vote = vote[i];
                            oldest = order[i];
                            target = i;
                        }    
                    }
                    
                    
                    if(vote[i] != 0 && vote[i] < min_vote){ // 가장 적게 vote 받은 애 찾기
                        min_vote = vote[i];
                        oldest = order[i];
                        target = i;
                    }
                }
                
                vote[student]++;
                order[student] = i;
                vote[target] = 0;
                order[target] = 0;

            }
        }
    }
    for (int i = 1; i <= 100; i++) {
        if (order[i]) cout << i << ' ';
    }
    return 0;
}   
