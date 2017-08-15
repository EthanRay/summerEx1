#include"zteDJSv53.h"
#include <random>
#include<functional>
#include<stdint.h> 
#include <chrono>
using namespace chrono;

//测试
void ZTES::testG4()
{
	auto start = system_clock::now();
	Input_Information();
	int s = 0;
	int t = netNode-1;
	//RandomCutEdge2(s, t, netNode/2);
	force(0);
	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "花费时间：" << double(duration.count()) * microseconds::period::num / microseconds::period::den << "秒" << endl;
	//Dijkstra5(s, 49, 25);
}

//必经点路径（测试用）
void ZTES::testG2(int s, int t)
{
	vector<int>tmpPA;
	vector<int>PA2;
	int book[500] = { 0 };
	memset(tag, 0, sizeof(tag));
	Input_Information();
	int a = 0, tmin = INT_MAX;
	int nx = mustNode;
	while (nx--)
	{
		book[s] = 1;
		tmin = INT_MAX;
		for (int i = 0; i < mustNode; ++i)
		{
			if (book[must_node[i]] == 1)
			{
				continue;
			}

		//	printf("%d ", must_node[i]);
			int tmp = SPFA1(s, must_node[i]);
			if (tmp < tmin)
			{
				tmin = tmp;
				a = must_node[i];
			}
		}
		//printf("\n***************************************\n");
	//	printf("\n%d %d \n", a, tmin);
		s = a;
		//PA.push_back(getPath(a));
		tmpPA = getPath(a);
		for (int i = 0; i < tmpPA.size(); ++i)
			PA2.push_back(tmpPA[i]);
		PA2.pop_back();

	//	printf("PASIZE=%d\n", PA2.size());
	}

//	printf("最后的输出:%d %d %d\n", s, t, nx);
	nx = SPFA1(s, t);
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
		printf("%d->", PA2[i]);
	}
	printf("\n经过了%d个点\n", x);

}

//输出测试
void ZTES::testG()
{
	Input_Information();
	connect con(0, 0, 0);
	printf("%d %d\n", netNode, Edges);

	for (int i = 0; i < netNode; ++i)//netNode
	{
		for (int j = 0; j < G[i].size(); ++j)
		{
			con = G[i][j];
		//	printf("%d %d %d\n", con.from, con.to, con.cost);
		}
	}
	printf("***************************************\n");
	for (int i = 0; i < mustNode; ++i)
	{
		printf("%d\n", must_node[i]);
	}
	printf("***************************************\n");
	printf("最短路径：%d\n", SPFA1(0, netNode-1));
	printf("*******输出路径*****************\n");
	vector<int> pathss;
	pathss = getPath(9);
	int len = pathss.size();
	for (int i = 0; i <len; ++i)
	{
		printf("%d-->", pathss[i]);
	}
	printf("\n%d %d %d %d %d %d\n", a1, a2, b1, b2, c1, c2);
}

void RandTest()
{
	default_random_engine generator(time(NULL));
	uniform_int_distribution<int> dis(0, 10),dis2(0,4);
	auto dice = std::bind(dis, generator);
	auto dice2 = std::bind(dis2, generator);
	int outt = 15;
	int x[5]= { 1, 3, 5, 7, 9 };

	while (outt)
	{
		printf("%d: ", dice());
		for (int i = 0; i < 2; ++i)
		{
			printf("%d ", x[dice2()]);
		}
		--outt;
		printf("\n");
	}
}

void ZTES::zteMainFuction()
{
	auto start = system_clock::now();
	Input_Information();
	int t = netNode - 1;
	int s = 0;
	printf("起点：%d，终点：%d：\n", s, t);
	if (netNode <= 300 && netNode>150)
	{
		RandomCutEdge2(s, t, netNode / 2);
	}
	else
	{
		SA_TSP(s, t);
	}
	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "花费时间：" << double(duration.count()) * microseconds::period::num / microseconds::period::den << "秒" << endl;
}

void randTest2()
{
	srand((int)time(0));
	for (int j = 0; j < 10; ++j)
	{
		for (int i = 0; i < 10; ++i)
		{
			printf("%d ", rand() % 100);
		}
		printf("\n");
	}
	
}

