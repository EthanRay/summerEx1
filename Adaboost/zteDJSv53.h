#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<time.h>
#include<fstream>
#include<random>
#define MAXVEX 1500
#define INF 214748
using namespace std;

struct  connect
{
	int from, to, cost;
	connect(int _from, int _to, int _cost)
	{
		from = _from, to = _to, cost = _cost;
	}
};

struct result
{
	int nodes;
	int cost;
	bool bt;
	vector<int> costPATH;
	
	result()
	{
		nodes = 0; cost = INF; bt = false;
	}
};

class ZTES
{
public:
	void Input_Information();
	void Output_Information(result rs);
	void addNode(int from, int to, int cost);
	string input_file = "case52.txt";//��������������������ļ�����������������ϸ�ʽҪ��
	void testG();
	void testG2(int s, int t);
	void zteMainFuction();
	void testG4();
	int SPFA1(int s, int t);
private:
	vector<vector<connect>> G;//�洢ͼ���ڽӱ�
	int netNode;//��������
	int mustNode;//�ؾ������
	int Edges;//����
	int must_node[1000];
	int N;//�����Ĵ���������ܴ���9��
	int ds[1000];
	bool used[1000];
	int prevs[1500];
	int tag[MAXVEX];
	void RandomCutEdge();//����Ͽ������߲����Ŷ�(������ɸ�Ϊn��)//vector<vector<connect>> &MAP
	void RandomCutEdge2(int s, int t, int nxx);
	void RandomCutEdge3(int s, int t, int nx);
	result Dijkstra5(int s, int t, int nx);
	vector<int> getPath(int t);

	//�������
	void dfs(int start, int dis, int end, int begin);
	void dfs2(int start, int dis, int end, int begin);

	result BFSpro(int start, int end);
	result BFSproX(int start, int end);
	void force(int t);
	bool vised[MAXVEX];
	int a1, a2, b1, b2, c1, c2,d1,d2;

	//ģ���˻�
	const double SPEED = 0.98;//�˻��ٶ�
	const int INITIAL_TMP = 1000;//��ʼ�¶�
	int L;

	void SA_TSP(int s,int t);
	void getNewSolution(result &p,int s,int t);
	bool Accept(result &bestone, result &temp, double t);
	void ReplayCount();

};