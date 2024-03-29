#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
if (a.first == b.first)
return a.second < b.second;

return a.first < b.first;
}

int findInd(vector<pair<int, int> >& prefix_sum, int n, int val)
{

    int l = 0;
    int h = n - 1;
    int mid;

    int ans = -1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (prefix_sum[mid].first <= val){
            ans = mid;
            l = mid + 1;
        }
        else
            h = mid - 1;
    }

    return ans;
}

int longest_sub_array(int arr[], int n, int k)
{
    int i;

    for (i = 0; i < n; i++)
        arr[i] -= k;

    int max_length = 0;

    vector<pair<int, int> > prefix_sum;

    int sum = 0;
    int min_ind[n];

    for (i = 0; i < n; i++){
        sum = sum + arr[i];
        prefix_sum.push_back({ sum, i });
    }

    sort(prefix_sum.begin(), prefix_sum.end(), compare);

    min_ind[0] = prefix_sum[0].second;

    for (i = 1; i < n; i++) {
        min_ind[i] = min(min_ind[i - 1], prefix_sum[i].second);
    }

    sum = 0;
    for (i = 0; i < n; i++){
        sum = sum + arr[i];

        if (sum >= 0)
            max_length = i + 1;

        else
        {
            int ind = findInd(prefix_sum, n, sum);
            if (ind != -1 && min_ind[ind] < i)
            max_length = max(max_length, i - min_ind[ind]);
        }
    }

    return max_length;
}

int main()
{
    int arr[] = {3,-4,6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 0;

    cout << longest_sub_array(arr, n, k);
    return 0;
}