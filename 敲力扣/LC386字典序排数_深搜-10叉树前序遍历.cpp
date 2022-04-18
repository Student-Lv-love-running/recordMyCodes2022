#include<iostream>
#include<vector>
using namespace std;

//���ѣ�10�����������
//ִ����ʱ��12 ms, ������ C++ �ύ�л�����41.83%���û�
//�ڴ����ģ�10.7 MB, ������ C++ �ύ�л�����78.09%���û�
class Solution {
public:
    vector<int> res;
    vector<int> lexicalOrder(int n) {
        res.reserve(n);
        for(int i=1;i<=9;i++){
            dfs(i,n);
        }
        return res;
    }
    void dfs(int cur,int n){
        if(cur>n)
            return;
        res.emplace_back(cur);
        for(int i=0;i<=9;++i){
            dfs(cur*10+i,n);
        }
    }
};

int main(){
    int n;
    cin>>n;
    Solution sol;
    vector<int> res=sol.lexicalOrder(n);
    for(auto& a:res)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}
