//ִ����ʱ��0 ms, ������ C++ �ύ�л�����100.00%���û�
//�ڴ����ģ�8.5 MB, ������ C++ �ύ�л�����50.74%���û�

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        digits[len - 1] += 1;
        for (int i = len - 1; i >= 0; i--) {
            if (i == 0 && digits[i] == 10) {
                digits.push_back(1);
                for (int j = len; j > 0; j--) {
                    if (j == 1) {
                        digits[j] = 0;
                    } else
                        digits[j] = digits[j - 1];
                }
                digits[i] = 1;
                break;
            }
            if (digits[i] == 10) {
                digits[i] = 0;
                digits[i - 1] += 1;
            } else {
                break;
            }
        }
        return digits;
    }
};
