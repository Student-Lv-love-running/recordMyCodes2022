#include<iostream>
#include<string.h>
using namespace std;

static int A[10000][100];
static int B[10000][100];
static int C[10000][100];
static int D[10000][100];
static int resultMatrix[10000][100];
static int columnSum[100];
static int cntvisited[100];
static int base_time[100];
static int line;
static int column;
static int tmpSum, SumD=9999999;

void baseCal() {
	/*
	 * ���� C �� D ����
	 * ������Сֵ SumD ͬʱ��¼��ǰ��Сֵ����
	 * ��ע����tmpSum==SumDʱ����ʱ�� B ��������һ�����Ž⣬�ڴ˾Ͳ�����¼������ 
	 */
	tmpSum = 0;
	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < column; ++j) {
			C[i][j] = A[i][j] + B[i][j];
			D[i][j] = C[i][j] - base_time[j];
			if (D[i][j] < 0)
				D[i][j] = -D[i][j];
			tmpSum += D[i][j];
		}
	}
	if (tmpSum < SumD) {
		SumD = tmpSum;
		for (int i = 0; i <= line; ++i) {
			for (int j = 0; j <= column; ++j) {
				resultMatrix[i][j] = B[i][j];
			}
		}
	}
}

/*
 * ö�� B ����, ����ĺ�����û�д�������ֻ��һ��Ϊ1������Ϊ0���������
 * �������B��������� baseCal() ����
 * ���ĳһ�����꣬������һ��
 * ���ĳһ���С������λ�á����� columnSum[xx] �е�ֵ���򽫵�ǰλ����0��������е���һ��
 * ��� columnSum[xx] ��û���� 0 ˵��ĳһ�л�û������1���򽫵�ǰλ����1��������е���һ�У�ͬʱ���û��ݴ���
 */
void enumeration(int nowline,int nowcolumn) {
	if (nowcolumn == column) {
		//baseCal();
		for (int i = 0; i < line; ++i) {
			for (int j = 0; j < column; ++j) {
				cout << B[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}
	if (nowline == line) {
		if (columnSum[nowcolumn] != 0)
			return;
		enumeration(0, nowcolumn + 1);
		return;
	}

	if (columnSum[nowcolumn] < line - nowline) {
		B[nowline][nowcolumn] = 0;
		enumeration(nowline + 1, nowcolumn);
	}
	if (columnSum[nowcolumn]) {
		columnSum[nowcolumn]--;
		B[nowline][nowcolumn] = 1;
		enumeration(nowline + 1, nowcolumn);
		columnSum[nowcolumn]++;
	}
}

/*
 * �������� enumeration() �����Ļ�����γ��Դ������յõ����º������㡰����ֻ��һ��Ϊ1������Ϊ0���������
 */
void dfs(int nowline, int nowcolumn) {
	if (nowcolumn == column) {
		memset(cntvisited, 0, sizeof(cntvisited) / sizeof(int));
		for (int i = 0; i < line; ++i) {
			for (int j = 0; j < column; ++j) {
				if (B[i][j])
					cntvisited[i]++;
				if (cntvisited[i] > 1)
					return;
			}
		}
		baseCal();
		return;
	}
	if (nowline == line) {
		if (columnSum[nowcolumn] != 0)
			return;
		dfs(0, nowcolumn + 1);
		return;
	}

	if (columnSum[nowcolumn] < line - nowline) {
		B[nowline][nowcolumn] = 0;
		dfs(nowline + 1, nowcolumn);
	}
	if (columnSum[nowcolumn]) {
		columnSum[nowcolumn]--;
		B[nowline][nowcolumn] = 1;
		dfs(nowline + 1, nowcolumn);
		columnSum[nowcolumn]++;
	}
}

int main() {
	/*
	 * �������� line ������ column
	 * �ֶ����� A ����
	 * ������� B ÿһ��������õ��ܺ�
	 * ����������� base_time
	 */
	cin >> line >> column;
	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < column; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < column; ++i) {
		cin >> columnSum[i];
	}
	for (int i = 0; i < column; ++i) {
		cin >> base_time[i];
	}

	//enumeration(0, 0);
	dfs(0, 0);

	cout << "���Ϊ���¾���" << endl;
	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < column; ++j) {
			cout << resultMatrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
