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

	//��¼�ؾ���
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
	printf("�ܹ���%d����㣬%d��·��\n", netNode, Edges);
//	printf("��㣺0 �յ㣺%d\n", netNode - 1);
	printf("���뾭���Ĵ��ؼ䣺%d %d\n", must_node[0], must_node[1]);
	printf("���뾭����·��1: %d---%d\n", must_node[2], must_node[3]);
	printf("���뾭����·��2: %d---%d\n", must_node[4], must_node[5]);
	printf("���ֻ�ܾ���%d�����ؼ�\n",netNode/2);
	printf("��ֹ������·��: %d---%d\n", d1,d2);
}
