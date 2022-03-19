//ִ����ʱ��4 ms, ������ C++ �ύ�л�����76.36%���û�
//�ڴ����ģ�9.3 MB, ������ C++ �ύ�л�����96.72%���û�

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int len = nums.size();
        int i = 0, j = len - 1;
        int mid = (i + j) / 2;
        while (i <= j) {
            if (nums[mid] > target)
                j = mid - 1;
            else if (nums[mid] < target)
                i = mid + 1;
            else
                return mid;
            mid = (i + j) / 2;
        }
        return i;
    }
};
