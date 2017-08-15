#include<queue>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	 queue<int> que;
	 deque<int>que2;

	for (int i = 0; i < 5; ++i)
	{
		
		que.push(i);
		que2.push_back(i);
	}
	printf("%d %d\n", que.size(), que2.size());
	//que2.clear();
	printf("%d %d\n", que.size(), que2.size());
	for (int i = 0; i < 5; ++i)
	{
		int tmp = que.front();
		que.pop();
		int tmp2 = que2.front();
		que2.pop_front();
		printf("%d %d\n", tmp, tmp2);
	}

}