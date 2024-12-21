class Solution {
public:
    double largestSumOfAverages(vector<int>& n, int K)
{
	double dp[1002]{};
	for(int i{}, s{}; i<size(n); ++i)
		dp[i+1] = (s+=n[i])/double(i+1);

	for(int k{1}; k<K; ++k)
		for(int i(size(n)-1); i>=k; --i)
			for(int j{i}, s{}; j>=k; --j)
				dp[i+1] = max(dp[i+1], dp[j]+(s+=n[j])/double(i-j+1));     
	return dp[size(n)];
}
};