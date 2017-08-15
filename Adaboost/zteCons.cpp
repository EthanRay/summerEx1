#include"zteDJSv53.h"
#include<functional>

void ZTES::addNode(int from, int to, int cost)
{
	connect link(from, to, cost);
	G[from].push_back(link);
	connect link2(to, from, cost);
	G[to].push_back(link2);
}

void ZTES::Input_Information()
{
	ifstream in(input_file);
	in >> netNode >> Edges >> mustNode;
	N = 9;
	L =  netNode;

	in >> a1 >> a2;
	in >> b1 >> b2;
	in >> c1 >> c2;
	in >> d1 >> d2;

	vector<connect> empty;
	G.assign(netNode, empty);

	int f, t, cap, c;
	for (int i = 0; i <Edges; ++i)
	{
		in >> f >> t >> cap >> c;
		cap = 0;
		if (f == d1&&t == d2)
		{
			continue;
		}
		addNode(f, t, c);
	}

	//记录必经点
	memset(must_node, 0, sizeof(must_node));
	memset(tag, 0, sizeof(tag));
	for (int i = 0; i < mustNode; ++i)
	{
		in >> t >> cap >> t;
		must_node[i] = cap;
		//printf("%d ", cap);
		tag[cap] = 1;
	}
	//printf("\n");
	printf("总共有%d个结点，%d个路段\n", netNode, Edges);
//	printf("起点：0 终点：%d\n", netNode - 1);
	printf("必须经过的储藏间：%d %d\n", must_node[0], must_node[1]);
	printf("必须经过的路段1: %d---%d\n", must_node[2], must_node[3]);
	printf("必须经过的路段2: %d---%d\n", must_node[4], must_node[5]);
	printf("最多只能经过%d个储藏间\n",netNode/2);
	printf("禁止经过的路段: %d---%d\n", d1,d2);
}
