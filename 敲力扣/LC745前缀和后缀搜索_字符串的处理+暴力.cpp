#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//�𰸵ı�����ⷨ����ʹ�ñ���������ô�����Ŀ����ȫû�����壬������
//Ӧ�����ֵ�������һ��

/*
 * ִ����ʱ��1008 ms, ������ C++ �ύ�л�����16.41%���û�
 * �ڴ����ģ�254.1 MB, ������ C++ �ύ�л�����33.85%���û�
 * */
class WordFilter {
private:
    unordered_map<string,int> dict;
public:
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();++i){
            int m=words[i].size();
            string word=words[i];
            for(int prefixLen=1;prefixLen<=m;prefixLen++){
                for(int suffixLen=1;suffixLen<=m;++suffixLen){
                    string key=word.substr(0,prefixLen)+"#"+word.substr(m-suffixLen);
                    dict[key]=i;
                }
            }
        }
    }

    int f(string pref, string suff) {
        string target=pref+"#"+suff;
        return dict.count(target)?dict[target]:-1;
    }
};

int main(){

}

/*
 * ���һ������һЩ���ʵ�����ʵ䣬���ܹ�ͨ��ǰ׺�ͺ�׺���������ʡ�
 * ʵ�� WordFilter �ࣺ
    WordFilter(string[] words) ʹ�ôʵ��еĵ��� words ��ʼ������
    f(string pref, string suff) ���شʵ��о���ǰ׺prefix�ͺ�׺ suff�ĵ��ʵ��±ꡣ
    ������ڲ�ֹһ������Ҫ����±꣬�������� �����±� ����������������ĵ��ʣ����� -1 ��
 */

/*
����
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
���
[null, 0]
����
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // ���� 0 ����Ϊ�±�Ϊ 0 �ĵ��ʣ�ǰ׺ prefix = "a" �� ��׺ suff = "e" ��
*/

