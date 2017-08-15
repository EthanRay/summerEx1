#include"zteDJSv53.h"

int thout[6] = { 0 }, cct = 0;
result bestone;
void ZTES::SA_TSP(int s,int dst)
{
	srand((int)time(0));
	int gii = 0;
	double r = SPEED;
	double t = INITIAL_TMP;
	const double t_min = 0.001;//0.001
	memset(thout, 0, sizeof(thout));
	cct = 0;
	result temp;

	while (t > t_min)
	{
		if (cct >4)
			break;
		for (int j = 0;j <5; ++j)
		{
			getNewSolution(temp, s, dst);
			if (Accept(bestone, temp, t))
			{
				bestone = temp;
			//	printf("花费：%d\n", bestone.cost);
				ReplayCount();
			}
			else
				temp = bestone;
		}
		t *= r;
	}

	for (int i = 0; i < bestone.costPATH.size(); ++i)
	{
		printf("%d->", bestone.costPATH[i]);
		if (i>0 && i %15 == 0)
			printf("\n");
	}
	printf("Finish\n");
	printf("花费：%d\n", bestone.cost);
}

void ZTES::getNewSolution(result &p, int s, int t)
{
	if (netNode > 150)
	{
		p = BFSproX(s, t);
	}
	else
	{
		p = BFSpro(s, t);
	}
	
}

bool ZTES::Accept(result &bestone, result &temp, double tx)
{
	if (bestone.cost>temp.cost)
		return true;
	else
	{
		if ((int)(exp((bestone.cost - temp.cost) / tx) * 100) > (rand() % 101))
			return true;//true
	}
	return false;
}

void ZTES::ReplayCount()
{
	if (cct == 0)
	{
		thout[cct++] = bestone.cost;
	}
	else
	{
		if (thout[cct - 1] == bestone.cost&&cct <4)
		{
			thout[cct++] = bestone.cost;
		}
		else
		{
			cct = 0;
			memset(thout, 0, sizeof(thout));
		}
	}
}

