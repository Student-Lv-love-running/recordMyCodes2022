#include<iostream>
using namespace std;

//ִ����ʱ��0 ms, ������ C++ �ύ�л�����100.00%���û�
//�ڴ����ģ�6 MB, ������ C++ �ύ�л�����87.96%���û�

class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1||n==2)
            return 1;
        int first=1;
        int second=1;
        for(int i=3;i<=n;i++){
            int third=first+second;
            first=second;
            second=third;
        }
        return second;
    }
};

int main(){
    int n;
    cin>>n;
    Solution sol;
    int ans=sol.fib(n);
    cout<<ans<<endl;
    return 0;
}
