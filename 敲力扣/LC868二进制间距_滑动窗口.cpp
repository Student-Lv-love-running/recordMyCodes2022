#include<iostream>
#include<vector>
using namespace std;

//�Լ�д������������
//ִ����ʱ��0 ms, ������ C++ �ύ�л�����100.00%���û�
//�ڴ����ģ�6.1 MB, ������ C++ �ύ�л�����5.09%���û�
class Solution {
public:
    int binaryGap(int n) {
        vector<int> binarys;
        while(n!=0){
            binarys.emplace_back(n%2);
            n=n/2;
        }

        int _size=binarys.size();
        int maxLen=0;
        int left=0,right=0;

        while(right<_size){
            if(binarys[left]==0){
                left++;
                continue;
            }

            if(right<=left){
                right++;
            }else if(binarys[right]==0){
                right++;
            }else if(binarys[right]==1){
                maxLen=max(maxLen,right-left);
                left++;
            }
        }

        return maxLen;
    }
};

//����һ��λ����
//˼·���㷨:
//���ǿ���ʹ��һ��ѭ���� n �����Ʊ�ʾ�ĵ�λ��ʼ���б��������ҳ����е� 1��������һ������ last ��¼��һ���ҵ��� 1 ��λ�á�
// �����ǰ�ڵ� i λ�ҵ��� 1����ô���� i-last ���´𰸣��ٽ� last ����Ϊ i ���ɡ�
//
//��ѭ����ÿһ���У����ǿ���ʹ��λ���� n & 1 ��ȡ n �����λ���ж����Ƿ�Ϊ 1������֮�����ǽ� n ����һλ��n = n >> 1��
//�����ڵ� i ��ʱ��n & 1 �õ��ľ��ǳ�ʼ n �ĵ� i ��������λ��
class Solution_answer {
public:
    int binaryGap(int n) {
        //�𰸵���������������
        int last = -1, ans = 0;
        for (int i = 0; n; ++i) {
            if (n & 1) {
                if (last != -1) {
                    ans = max(ans, i - last);
                }
                last = i;
            }
            n >>= 1;
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    Solution sol;
    int ans=sol.binaryGap(n);
    cout<<ans<<endl;
    return 0;
}
