#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

//̰���㷨
//ִ����ʱ��60 ms, ������ C++ �ύ�л�����29.80%���û�
//�ڴ����ģ�47.1 MB, ������ C++ �ύ�л�����87.00%���û�
//����һ�����飬ά��һ����Զ����
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n=nums.size();
        if(n==1)
            return true;
        int index=1;
        int maxDis=nums[0];
        while(index<n){
            if(index<=maxDis){
                maxDis=max(index+nums[index],maxDis);
                index++;
                if(maxDis>=n-1)
                    return true;
            }else{
                break;
            }
        }
        return false;
    }
};

int main() {
    vector<int> ob;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        ob.emplace_back(num);
    }
    Solution sol;
    bool ans = sol.canJump(ob);
    cout << ans << endl;
    return 0;
}