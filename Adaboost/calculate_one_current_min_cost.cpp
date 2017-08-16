#include"huawei_ruantiao.h"
#include<queue>
int dist[1000];//该节点距离服务器的距离
int _prev[1000];//记录前驱节点
int prev_edge[1000];//记录前驱节点到达该节点所经过边的位置
bool visited[1000];//该节点是否被访问过

struct compare
{
	bool operator()(const node &a, const node &b)
	{
		return a.distance>b.distance;
	}
};

//服务器的位置，所需的流量以及网络图
int huawei_ruantiao::calculate_one_current_min_cost(int &pos, int &current, vector<vector<connect>> &map, set<int> &position_of_server)
{
	int costs = 0, cost, flow;
	pair<int, int> Dijkstra_result;
	while (current)
	{
		if (bellman_or_not == 0)
			Dijkstra_result = Dijkstra1(pos, map, position_of_server, current);
		else
			Dijkstra_result = Dijkstra(pos, map, position_of_server, current);
		flow = Dijkstra_result.first;
		cost = Dijkstra_result.second;
		current -= flow;
		if (cost == INT_MAX)
			return INT_MAX;
		costs += cost;
	}
	return costs;
}

pair<int, int>huawei_ruantiao::Dijkstra(int &pos, vector<vector<connect>> &map, set<int> &position_of_server, int &current)
{
	if (position_of_server.count(pos) == 1 && server_output[pos]<the_biggest_current_of_server)
	{
		int flow = min(current, the_biggest_current_of_server - server_output[pos]);
		server_output[pos] += flow;
		return pair<int, int>(flow, 0);
	}

	fill(dist, dist + 1000, INT_MAX);
	fill(_prev, _prev + 1000, -1);
	fill(prev_edge, _prev + 1000, -1);

	priority_queue<node, vector<node>, compare>que;
	que.push(node(pos, 0));
	dist[pos] = 0;
	_prev[pos] = -1;
	int sign = 0;
	int start = pos, end, min_dist_net_work;
	node min_dist_net;

	while (!que.empty())
	{
		min_dist_net = que.top();
		que.pop();
		min_dist_net_work = min_dist_net.new_work_pos;
		if (dist[min_dist_net_work] < min_dist_net.distance)
			continue;
		int min_dist_net_work = min_dist_net.new_work_pos;

		if (position_of_server.count(min_dist_net_work) == 1 && server_output[min_dist_net_work] < the_biggest_current_of_server)
		{
			sign = 1;
			end = min_dist_net_work;
			break;
		}
		for (int j = 0; j < map[min_dist_net_work].size(); ++j)
		{
			connect e = map[min_dist_net_work][j];
			if (dist[e.end] > dist[min_dist_net_work] + e.cost)
			{
				dist[e.end] = dist[min_dist_net_work] + e.cost;
				_prev[e.end] = min_dist_net_work;
				prev_edge[e.end] = j;
				que.push(node(e.end, dist[e.end]));
			}
		}
	}

	if (sign == 1)
	{
		int flow = INT_MAX, pos = end, cost = 0;
		while (_prev[pos] != -1)
		{
			connect &e = map[_prev[pos]][prev_edge[pos]];
			if (map[e.end][e.rev].flow > 0)
				map[e.end][e.rev].flow -= flow;
			else
				e.flow += flow;
			pos = _prev[pos];
		}
		return pair<int, int>(flow, dist[end] * flow);
	}
	return pair<int, int>(0, INT_MAX);
}

pair<int, int> huawei_ruantiao::Dijkstra1(int &pos, vector<vector<connect>> &map, set<int> &position_of_server, int &current)
{
	if (position_of_server.count(pos) == 1 && server_output[pos]<the_biggest_current_of_server)
	{
		int flow = min(current, the_biggest_current_of_server - server_output[pos]);
		server_output[pos] += flow;
		return pair<int, int>(flow, 0);
	}
	fill(dist, dist + 1000, INT_MAX);//该节点距离服务器的距离
	fill(_prev, _prev + 1000, -1);//记录前驱节点
	fill(prev_edge, _prev + 1000, -1);//记录前驱节点到达该节点所经过边的位置
	fill(visited, visited + 1000, false);//记录当前节点是否访问
	priority_queue<node, vector<node>, compare> que;
	que.push(node(pos, 0));
	dist[pos] = 0;
	visited[pos] = true;
	_prev[pos] = -1;
	int sign = 0;
	int start = pos, end, min_dist_net_work;
	node min_dist_net;
	int res = 0;

	while (!que.empty())
	{
		min_dist_net = que.top();
		min_dist_net_work = min_dist_net.new_work_pos;
		que.pop();
		if (dist[min_dist_net_work]<min_dist_net.distance)
			continue;
		int min_dist_net_work = min_dist_net.new_work_pos;
		if (position_of_server.count(min_dist_net_work) == 1 && server_output[min_dist_net_work]<the_biggest_current_of_server)
			//服务器输出的流量小于服务器能输出的最大流量
		{
			sign = 1;
			end = min_dist_net_work;
			break;
		}
		for (int j = 0; j < map[min_dist_net_work].size(); ++j)
		{
			connect e = map[min_dist_net_work][j];
			if (visited[e.end] == false && (e.cap - e.flow>0 && dist[e.end]>dist[min_dist_net_work] + e.cost))
			{
				dist[e.end] = dist[min_dist_net_work] + e.cost;
				_prev[e.end] = min_dist_net_work;
				prev_edge[e.end] = j;
				que.push(node(e.end, dist[e.end]));
				visited[e.end] = true;
			}
		}
	}
	if (sign == 1)
	{
		int flow =current, pos = end, cost = 0;
		for (int v = end; _prev[v] !=-1; v = _prev[v])//_prev[pos] 
		{
			connect e = map[_prev[v]][prev_edge[v]];
			flow = min(flow, e.cap-e.flow);
		}
		flow = min(flow, current);
		flow = min(flow, the_biggest_current_of_server - server_output[end]);
		server_output[end] += flow;
		for (int v = end; _prev[v] != -1; v = _prev[v])
		{
			connect &e = map[_prev[v]][prev_edge[v]];
			e.flow += flow;
			cost += flow*e.cost;
		}
		for (int v = end; _prev[v] != -1; v = _prev[v])
		{
			connect &e = map[_prev[v]][prev_edge[v]];
			if (e.flow>0 && map[e.end][e.rev].flow>0)
			{
				int flow = min(e.flow, map[e.end][e.rev].flow);
				e.flow -= flow;
				map[e.end][e.rev].flow -= flow;
				cost -= flow*e.cost * 2;
			}
		}
		return pair<int, int>(flow, cost);
	}
	return pair<int, int>(0, INT_MAX);
}