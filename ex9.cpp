#include"stdfx.h"

int reverse23(int x){
	long long r = 0;
	long long t = x;

	t = t > 0 ? t : -t;

	for (; t; t /= 10)
		r = r * 10 + t % 10;

	bool sign = x > 0 ? false : true;
	if (r > INT_MAX || (sign&&r > INT_MAX)){
		return 0;
	}
	else{
		if (sign){
			return -r;
		}
		else{
			return r;
		}
	}
}

bool isPalindrome23(int x){
	if (x < 0)
		return false;

	int d = 1;
	while (x / d <= 10){
		d *= 10;
	}

	while (x > 0){
		int q = x / d;
		int r = x % 10;
		if (q != r)return false;

		x = x%d / 10;
		d /= 100;
	}

	return true;
}

struct Interval
{
	int start;
	int end;
	Interval() :start(0), end(0){}
	Interval(int s, int e) :start(s), end(e){}
};

vector<Interval> insert23(vector<Interval> &intervals, Interval newInterval){
	auto iter = intervals.begin();
	while (iter!=intervals.end())
	{
		if (newInterval.end < iter->start){
			intervals.insert(iter, newInterval);
			return intervals;
		}
		else if (newInterval.start > iter->end){
			++iter;
			continue;
		}
		else{
			newInterval.start = min(newInterval.start, iter->start);
			newInterval.end = max(newInterval.end, iter->end);
			iter = intervals.erase(iter);
		}
	}
	intervals.insert(intervals.end(), newInterval);
	return intervals;
}

vector<Interval>insert24(vector<Interval>&intervals, Interval newInterval){
	auto iter = intervals.begin();
	while (iter!=intervals.end())
	{
		if (newInterval.end < iter->start){
			intervals.insert(iter, newInterval);
			return intervals;
		}
		else if (newInterval.start > iter->end){
			++iter;
			continue;
		}
		else{
			newInterval.start = min(newInterval.start, iter->start);
			newInterval.end = max(newInterval.end, iter->end);
			iter = intervals.erase(iter);
		}
	}
	intervals.insert(intervals.end(), newInterval);
	return intervals;
}
vector<Interval>merge24(vector<Interval> &intervals, Interval newInterval){
	vector<Interval>resultss;
	for (int i = 0; i < intervals.size(); ++i){
		insert24(resultss, intervals[i]);
	}
	return resultss;
}

string minWindow(string S, string T){
	if (S.empty())return "";
	if (S.size() < T.size())return "";

	const int maxASCII = 256;
	int aC[maxASCII];
	int eC[maxASCII];

	fill(aC, aC + maxASCII, 0);
	fill(eC, eC + maxASCII, 0);

	for (int i = 0; i < T.size(); ++i)
		eC[T[i]]++;

	int minWidth = INT_MAX, minStart = 0;
	int wndStart = 0, app = 0;
	
	for (int wndEnd = 0; wndEnd < S.size(); ++wndEnd){
		if (eC[S[wndEnd]] > 0){
			aC[S[wndEnd]]++;
			if (aC[S[wndEnd]] <= eC[S[wndEnd]])
				++app;
		}
		if (app == T.size()){

			while (aC[S[wndStart]] > eC[S[wndStart]]
				||eC[S[wndStart]]==0){
				aC[S[wndStart]]--;
				wndStart++;
			}

			if (minWidth > (wndEnd - wndStart + 1)){
				minWidth = wndEnd - wndStart + 1;
				minStart = wndStart;
			}
		}
	}
}

int main(){
	vector<int> ttb(100, 0);
	ttb = {0,1,2,3,4,5,6,7,8,9};
	vector<int>::iterator iter = ttb.begin();
	++iter;
	iter = ttb.erase(iter);
	cout << *iter << endl;
	for (auto its : ttb){
		cout << its << " ";
	}
}