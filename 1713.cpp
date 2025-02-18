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

        if(full < N){ //���� Ʋ�� �� �� á�� ��
            vote[student]++;

            if(order[student]) continue; //�̹� Ʋ �ȿ� ����
            
            else{   //Ʋ �ȿ� ���� ���
                order[student] = i;
                full++;
            }
        }

        else{ // Ʋ�� �� á�� ���
            int min_vote = 1001;
            int oldest = 1001;
            int target;
            
            if(order[student]) {
                vote[student]++;
                continue;
            }
           
            else{ // Ʋ�� ���� X
               
                for(int i=1; i<=MAX; i++){

                    if(vote[i] == min_vote){ //���� ��ǥ
                        if(order[i] < oldest){
                            min_vote = vote[i];
                            oldest = order[i];
                            target = i;
                        }    
                    }
                    
                    
                    if(vote[i] != 0 && vote[i] < min_vote){ // ���� ���� vote ���� �� ã��
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
