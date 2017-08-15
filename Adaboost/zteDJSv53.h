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
	string input_file = "case52.txt";//在这里输入测试用例的文件名，测试用例需符合格式要求
	void testG();
	void testG2(int s, int t);
	void zteMainFuction();
	void testG4();
	int SPFA1(int s, int t);
private:
	vector<vector<connect>> G;//存储图（邻接表）
	int netNode;//网络结点数
	int mustNode;//必经点个数
	int Edges;//边数
	int must_node[1000];
	int N;//经过的储物间数不能大于9个
	int ds[1000];
	bool used[1000];
	int prevs[1500];
	int tag[MAXVEX];
	void RandomCutEdge();//随机断开两条边产生扰动(后续或可改为n条)//vector<vector<connect>> &MAP
	void RandomCutEdge2(int s, int t, int nxx);
	void RandomCutEdge3(int s, int t, int nx);
	result Dijkstra5(int s, int t, int nx);
	vector<int> getPath(int t);

	//深度优先
	void dfs(int start, int dis, int end, int begin);
	void dfs2(int start, int dis, int end, int begin);

	result BFSpro(int start, int end);
	result BFSproX(int start, int end);
	void force(int t);
	bool vised[MAXVEX];
	int a1, a2, b1, b2, c1, c2,d1,d2;

	//模拟退火
	const double SPEED = 0.98;//退火速度
	const int INITIAL_TMP = 1000;//初始温度
	int L;

	void SA_TSP(int s,int t);
	void getNewSolution(result &p,int s,int t);
	bool Accept(result &bestone, result &temp, double t);
	void ReplayCount();

};