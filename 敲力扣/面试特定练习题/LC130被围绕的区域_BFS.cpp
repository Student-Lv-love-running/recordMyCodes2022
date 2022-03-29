#include<iostream>
#include<vector>
#include <queue>
using namespace std;

//学习了答案思路后，自己写的BFS
//用时击败25.03%，内存消耗击败42.12%
class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if(m==0)
            return;
        int n=board[0].size();

        queue<pair<int,int>> que;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                que.emplace(i,0);
                board[i][0]='A';
            }
            if(board[i][n-1]=='O'){
                que.emplace(i,n-1);
                board[i][n-1]='A';
            }
        }

        for(int i=1;i<n-1;i++){
            if(board[0][i]=='O'){
                que.emplace(0,i);
                board[0][i]='A';
            }
            if(board[m-1][i]=='O'){
                que.emplace(m-1,i);
                board[m-1][i]='A';
            }
        }

        while(!que.empty()){
            int x=que.front().first,y=que.front().second;
            que.pop();
            for(int i=0;i<4;i++){
                int mx=x+dx[i],my=y+dy[i];
                if(mx<0||my<0||mx>=m||my>=n||board[mx][my]!='O'){
                    continue;
                }
                que.emplace(mx,my);
                board[mx][my]='A';
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='A'){
                    board[i][j]='O';
                }
            }
        }
        return;
    }
};

int main() {
    vector<vector<char>> board;
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        vector<char> tmp;
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            tmp.emplace_back(ch);
        }
        board.emplace_back(tmp);
    }
    Solution sol;
    sol.solve(board);
    return 0;
}