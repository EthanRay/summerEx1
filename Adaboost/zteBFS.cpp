#include"zteDJSv53.h"

int pathsb[1000]; // 用来保存路径  
int cc = 0;
void ZTES::dfs(int start, int dis, int end, int begin)
{
	int i = start;
	cc = 0;
	int sum = 0, sum2=0;
	fill(pathsb, pathsb + 1000, -1);
	memset(ds,0, sizeof(ds));
	printf("mustnode=%d\n", mustNode);
	srand((int)time(0));

	for (int i = 0; i < mustNode; ++i)
	{
		ds[must_node[i]] = 1;
	}
	ds[start] = 1;
	ds[end] = 1;

	while (true)
	{

		if (i == end&&sum==mustNode)
		{
			printf("sum=%d\n", sum);
			break;
		}

			dis = G[i].size();
			i = G[i][rand() % dis].to;

			if (i == end)
			{
				if (sum < mustNode)
				{
					dis = G[i].size();
					i = G[i][rand() % dis].to;
				}
			}

			if (i == 21)
			{
				pathsb[cc++] =21;
				pathsb[cc++] = 22;
			}
			else
			{
				pathsb[cc++] = i;
			}
		

			if (tag[i] == 1)
			{
				++tag[i];
			//	printf("must_node=%d\n", i);
				++sum;
			}

			if (ds[i] == 0)
			{
				ds[i] = 1;
				++sum2;
			}

			if (sum2>53 || cc>50)//sum2>13||
			{
				cc = 0;
				sum2 = 0;
				i = start;
				fill(pathsb, pathsb + 1000, -1);
				sum = 0;
				for (int i = 0; i <mustNode; ++i)
				{
					tag[must_node[i]] = 1;
				}
			}
	}

		printf("%d: ", cc);
		printf("%d->", start);
		for (int j = 0; pathsb[j] != -1; ++j)
		{
			printf("%d->", pathsb[j]);
		}
		printf("\n");
}

void ZTES::dfs2(int start, int dis, int end, int begin)
{
	int i = start;
	cc = 0;
	int sum = 0, sumCost = 0,index=0,prev_index=0;
	bool red1 = true, red2 = true;
	int ccLimt = netNode / 2 - 1;
	fill(pathsb, pathsb + 1000, -1);
	memset(ds, 0, sizeof(ds));
	printf("mustnode=%d\n", mustNode);
	for (int i = 0; i < mustNode; ++i)
	{
		ds[must_node[i]] = 1;
	}
	ds[start] = 1;
	ds[end] = 1;

	pathsb[cc++] = start;
	while (true)
	{

		if (i == end&&sum==mustNode)
		{
			printf("sum=%d\n", sum);
			for (int i = 0; i <mustNode; ++i)
			{
				if (tag[i]>0)
					printf("%d ", i);
			}
			break;
		}

		prev_index = i;
		dis = G[i].size();
		index = rand() % dis;
		sumCost += G[i][index].cost;
		i = G[i][index].to;
		
		if (i == a1 || i == a2)
		{
			if (red1)
			{
				if (i == a1)
				{
					pathsb[cc++] = a1;
					pathsb[cc++] = a2;
					++tag[a2];
					++sum;
				}
				if (i == a2)
				{
					pathsb[cc++] = a2;
					pathsb[cc++] = a1;
					++tag[a1];
					++sum;
				}
				red1 = false;
			}
		}
		else if (i == b1 || i == b2)
		{
			if (red2)
			{
				if (i == b1)
				{
					pathsb[cc++] = b1;
					pathsb[cc++] = b2;
					++tag[b2];
					++sum;
				}
				if (i == b2)
				{
					pathsb[cc++] = b2;
					pathsb[cc++] = b1;
					++tag[b1];
					++sum;
				}
				red2 = false;
			}
		}
		else
		{
			if (pathsb[cc-1] != i)
			{
				pathsb[cc++] = i;
			}
		}
	
		
		if (tag[i] == 1)
		{
			++tag[i];
			++sum;
		}

		if (cc>ccLimt)//sum2>13||cc>50
		{
			cc = 0;
			i = start;
			fill(pathsb, pathsb + 1500, -1);
			pathsb[cc++] = start;
			sum = 0;
			for (int i = 0; i <mustNode; ++i)
			{
				tag[must_node[i]] = 1;
			}
			sumCost = 0;
			red1 = true;
			red2 = true;
		}
	}

	printf("经过储藏间个数: %d 总花费: %d\n", cc,sumCost);
//	printf("%d->", start);
	for (int j = 0; pathsb[j] != -1; ++j)
	{
		printf("%d->", pathsb[j]);
	}
	printf("\n");
}

result ZTES::BFSpro(int start, int end)
{
	result resBFS;
	int i = start,dis=0;
	cc = 0;
	int sum = 0, sumCost = 0, index = 0, prev_index = 0;
	bool red1 = true, red2 = true;
	int ccLimt = netNode / 2 - 1;
	fill(pathsb, pathsb + 1000, -1);
	memset(ds, 0, sizeof(ds));
	for (int i = 0; i < mustNode; ++i)
	{
		ds[must_node[i]] = 1;
	}
	ds[start] = 1;
	ds[end] = 1;

	pathsb[cc++] = start;
	while (true)
	{

		if (i == end&&sum == mustNode)
		{
			break;
		}

		prev_index = i;
		dis = G[i].size();
		index = rand() % dis;
		sumCost += G[i][index].cost;
		i = G[i][index].to;

		if (i == a1 || i == a2)
		{
			if (red1)
			{
				if (i == a1)
				{
					pathsb[cc++] = a1;
					pathsb[cc++] = a2;
					++tag[a2];
					++sum;
				}
				if (i == a2)
				{
					pathsb[cc++] = a2;
					pathsb[cc++] = a1;
					++tag[a1];
					++sum;
				}
				red1 = false;
			}
		}
		else if (i == b1 || i == b2)
		{
			if (red2)
			{
				if (i == b1)
				{
					pathsb[cc++] = b1;
					pathsb[cc++] = b2;
					++tag[b2];
					++sum;
				}
				if (i == b2)
				{
					pathsb[cc++] = b2;
					pathsb[cc++] = b1;
					++tag[b1];
					++sum;
				}
				red2 = false;
			}
		}
		else
		{
			if (pathsb[cc - 1] != i)
			{
				pathsb[cc++] = i;
			}
		}


		if (tag[i] == 1)
		{
			++tag[i];
			++sum;
		}

		if (cc>ccLimt)//sum2>13||cc>50
		{
			cc = 0;
			i = start;
			fill(pathsb, pathsb + 1500, -1);
			pathsb[cc++] = start;
			sum = 0;
			for (int i = 0; i <mustNode; ++i)
			{
				tag[must_node[i]] = 1;
			}
			sumCost = 0;
			red1 = true;
			red2 = true;
		}
	}

	//printf("经过储藏间个数: %d 总花费: %d\n", cc, sumCost);
	resBFS.cost = sumCost;
	resBFS.nodes = cc+1;
	for (int j = 0; pathsb[j] != -1; ++j)
	{
		//printf("%d->", pathsb[j]);
		resBFS.costPATH.push_back(pathsb[j]);
	}
	//printf("\n");
	return resBFS;
}

result ZTES::BFSproX(int start, int end)
{
	result re;
	vector<int>tmpPA;
	vector<int>PA2;
	int s= start, dis = 0,tmpCost=0;
	int nx = mustNode+1;
	cc = 0;
	int book[1000] = { 0 };
	int sum = 0, sumCost = 0, index = 0, prev_index = 0;
	bool red1 = true, red2 = true;
	int ccLimt = netNode / 2 - 1;
	memset(ds, 0, sizeof(ds));
	random_shuffle(must_node, must_node + mustNode);
	for (int i = 0; i < mustNode; ++i)
	{
		tmpCost += SPFA1(s, must_node[i]);
		tmpPA = getPath(must_node[i]);
		for (int i = 0; i < tmpPA.size(); ++i)
			PA2.push_back(tmpPA[i]);
		PA2.pop_back();
		s = must_node[i];
	}
	tmpCost += SPFA1(s,end);
	tmpPA = getPath(end);
	for (int i = 0; i < tmpPA.size(); ++i)
		PA2.push_back(tmpPA[i]);

	int len = PA2.size();
	if (len <= netNode/2)
	{
		re.bt = true; re.nodes =len; re.costPATH = PA2; re.cost = tmpCost;
		return re;
	}
	else
	{
		re.bt = false; re.nodes =len; re.costPATH = PA2; re.cost = tmpCost;
		return re;
	}
}

void ZTES::force(int t)
{
	if (t > 0)
	{
		int s = 0;
		int outt = 10;
		srand((int)time(0));
		result tmp;
		int GG = INF;
		int ttt = 10;
		while (ttt--)
		{
			tmp = BFSpro(s, t);
			if (GG > tmp.cost)
			{
				GG = tmp.cost;
				printf("\n%d", tmp.cost);
				for (int i = 0; i < tmp.costPATH.size(); ++i)
				{
					printf("%d->", tmp.costPATH[i]);
				}
			}
		}
	}
	else
	{
		srand((int)time(0));
		result tmp2;
		int GG2 = INF;
		for (int i = 0; i < 15; ++i)
		{
			tmp2=BFSproX(0, netNode - 1);
			if (tmp2.bt&&tmp2.cost < GG2)
			{
				GG2 = tmp2.cost;

				printf("%d\n", GG2);
			}
		}
		int len = tmp2.costPATH.size();
		for (int i = 0; i < len; ++i)
		{
			printf("%d->", tmp2.costPATH[i]);
			if (i % 15 == 0 && i>0)
				printf("\n");
		}
		printf("Finish\n");
		printf("\n经过了%d个点，花费了%d\n",tmp2.nodes, tmp2.cost);
		
	}

}