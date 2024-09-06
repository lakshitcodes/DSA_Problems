#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.naukri.com/code360/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017

#include<bits/stdc++.h>

vector<int> prevSmaller(vector<int> &height){
	stack<int> st;
	vector<int> ans(height.size(),-1);
	for(int i=0;i<height.size();i++){
		while(!st.empty() && height[st.top()]>=height[i]){
			st.pop();
		}
		if(!st.empty()){
			ans[i]=st.top();
		}
		st.push(i);
	}
	return ans;
}
vector<int> nextSmaller(vector<int> &height){
	int n =height.size();
	stack<int> st;
	vector<int> ans(n,-1);
	for(int i=n-1;i>=0;i--){
		while(!st.empty() && height[st.top()]>=height[i]){
			st.pop();
		}
		if(!st.empty()){
			ans[i]=st.top();
		}
		st.push(i);
	}
	return ans;
}
int largestRectangle(vector<int> &height){
	vector<int> prev = prevSmaller(height);
	vector<int> next = nextSmaller(height);
	int ans=0;
	for(int i=0;i<height.size();i++){
		int length = height[i];
		if(next[i]==-1){
			next[i]=height.size();
		}
		int breadth = next[i]-prev[i]-1;
		ans=max(ans,length*breadth);
	}
	return ans;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix, int n, int m){
	vector<int> height(m,0);
	int ans=INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==1){
				height[j]++;
			}
			else{
				height[j]=0;
			}
		}
		ans = max(ans,largestRectangle(height));
	}
	return ans;
}