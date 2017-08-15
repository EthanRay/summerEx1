#include"zteDJSv53.h"
#include<functional>
#include<queue>
#include <random>


int dis2[MAXVEX];
bool vis2[MAXVEX];

int ZTES::SPFA1(int s, int t)
{

	memset(vis2, false, sizeof(vis2));
	fill(dis2, dis2 + MAXVEX, INF);
	fill(prevs, prevs +MAXVEX, -1);
	dis2[s] = 0;

	queue<int> q;
	q.push(s);

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis2[u] = false;

		for (int i = 0; i < G[u].size(); ++i)
		{
			connect e = G[u][i];
			int v = e.to;
			int cost = e.cost;
			if (dis2[v]>dis2[u] + cost&&cost<INF)
			{
				dis2[v] = dis2[u] + cost;
				prevs[v] = u;
				if (!vis2[v])
				{
					q.push(v);
					vis2[v] = true;
				}
			}
		}
	}
	return dis2[t];
}

vector<int> ZTES::getPath(int t)
{
	vector<int> path;

	for (; t != -1; t = prevs[t])
	{
		path.push_back(t);
	}
	reverse(path.begin(), path.end());
	return path;
}

//必经点路径
result ZTES::Dijkstra5(int s, int t, int nxx)
{
	vector<int>tmpPA;
	vector<int>PA2;
	result re;
	int cost = 0;
	int book[500] = { 0 };
	memset(tag, 0, sizeof(tag));
	int a = 0, tmin = INT_MAX;
	int nx = mustNode;

	while (nx--)
	{
		book[s] = 1;
		tmin = INT_MAX;
		for (int i = 0; i <mustNode; ++i)
		{
			if (book[must_node[i]] == 1)
			{
				continue;
			}
			int tmp = SPFA1(s, must_node[i]);
			if (tmp < tmin)
			{
				tmin = tmp;
				a = must_node[i];
			}
		}
		s = a;
		cost += tmin;
		tmpPA = getPath(a);
		for (int i = 0; i < tmpPA.size(); ++i)
			PA2.push_back(tmpPA[i]);
		PA2.pop_back();
	}

	nx = SPFA1(s, t);

	cost += nx;
	tmpPA = getPath(t);
	for (int i = 0; i < tmpPA.size(); ++i)
		PA2.push_back(tmpPA[i]);

	int len = PA2.size();
	int x = 0;
	for (int i = 0; i < len; ++i)
	{
		if (tag[PA2[i]] == 0)
		{
			tag[PA2[i]] = 1;
			++x;
		}
	}
	memset(tag, 0, sizeof(tag));
	if (len <= nxx)
	{
		re.bt = true; re.nodes = x; re.costPATH = PA2; re.cost = cost;
		return re;
	}
	else
	{
		re.bt = false; re.nodes = x; re.costPATH = PA2; re.cost = cost;
		return re;
	}


}

//产生扰动
void ZTES::RandomCutEdge3(int s, int t, int nxx)
{
	Input_Information();
	vector<int> revPath;
	int minTh = INF;
	int minCross = INF;
	default_random_engine generator(time(NULL));
	uniform_int_distribution<int> dis(0, netNode - 2);
	auto dice = std::bind(dis, generator);
	bool flag = true, f1 = false, f2 = false;
	int cutNode[10] = { 0 };
	int outt = 10;
	while (outt)
	{
		
		int j = 0, a1, a2;
		while (j<10)
		{
			a1 = dice();
			a2 = dice();
			if (G[a1][0].cost < INF&&G[a2][0].cost<INF)
			{
				G[a1][0].cost = INF;
				int v = G[a1][0].to;
				G[v][0].cost = INF;

				G[a2][0].cost = INF;
				v = G[a2][0].to;
				G[v][0].cost = INF;
				++j;
			}	
		}

		int lenPath = revPath.size();
		int b1 = 0, b2 = 0;
		if (lenPath >=4)
		{
			uniform_int_distribution<int> dis2(1, lenPath-1);
			auto dice2 = std::bind(dis2, generator);
			b1 = revPath[dice2()];
			b2 = revPath[dice2()];
		}

		result rs = Dijkstra5(s, t, nxx);
		if (rs.bt)
		{
			if (rs.cost < minTh)//rs.cost < minTh||rs.nodes<minCross
			{
				minTh = rs.cost;
				int len = rs.costPATH.size();
				revPath = rs.costPATH;
				for (int i = 0; i < len; ++i)
					printf("%d->", rs.costPATH[i]);
				printf("\n经过了%d个点，花费了%d\n", rs.nodes, rs.cost);
				break;
			}

		}
	}
}

void ZTES::RandomCutEdge2(int s, int t, int nxx)
{
	//Input_Information();

	vector<int> revPath;
	vector<vector<connect>> MAP;
	int outt = 10;
	int minTh = INF;
	int minCross = INF;
	bool reco = false;
	default_random_engine generator2(time(0));
	//uniform_int_distribution<int> dis(1, 11);
	result rs;
	while (outt)
	{
		MAP = G;
		reco = false;
		int lenPath = revPath.size();
		int b1 = 0, b2 = 0;
		int i1 = 0, i2 = 0,cost1=0,cost2=0;
		if (lenPath >= 4)
		{
			reco = true;
			uniform_int_distribution<int> dis22(1, lenPath - 2);
			//auto dice2 = std::bind(dis22, generator2);
			int x1 = dis22(generator2);
			int x2 = dis22(generator2);
	
			b1 = revPath[x1];
			b2 = revPath[x1+1];		

			for (int i = 0; i < MAP[b1].size(); ++i)
			{
				if (b2 == MAP[b1][i].to)
				{
					i1 = i;
					cost1 = MAP[b1][i].cost;
					MAP[b1][i].cost = INF;
				}
			}

			for (int i = 0; i < MAP[b2].size(); ++i)
			{
				if (b1 == MAP[b2][i].to)
				{
					i2 = i;
					cost2 = MAP[b2][i].cost;
					MAP[b2][i].cost = INF;
				}
			}
		}

		rs = Dijkstra5(s, t, nxx);
		if (rs.bt)
		{
			if (rs.cost <= minTh &&rs.cost>0)//rs.cost < minTh||rs.nodes<minCross
			{
				minTh = rs.cost;
				int len = rs.costPATH.size();
				revPath = rs.costPATH;
				//printf("\n花费了%d\n", rs.cost);
				--outt;
			}
		}
	}
	int len = rs.costPATH.size();
	for (int i = 0; i < len; ++i)
	{
		printf("%d->", rs.costPATH[i]);
		if (i % 15 == 0&&i>0)
			printf("\n");
	}
	printf("Finish\n");
	printf("\n经过了%d个点，花费了%d\n", rs.nodes, rs.cost);
}