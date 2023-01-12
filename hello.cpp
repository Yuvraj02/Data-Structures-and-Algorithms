#include <iostream>
#include <vector>

using namespace std;

bool isPossibleHeight(vector<int> &A, int req, int height)
{

    int remaining = req;

    for (int i = 0; i < A.size(); i++)
    {
        if (height >= A[i])
            continue;

        remaining = remaining - (A[i] - height);

        if (remaining <= 0)
        {
            return true;
        }
    }
    return false;
}

int maxHeight(vector<int> &A, int req)
{
    int start = 0, end = INT32_MIN;

    for (int i = 0; i < A.size(); i++)
    {
        end = max(end, A[i]);
    }
    int mid = (start + end) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (isPossibleHeight(A, req, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return ans;
}

int main()
{

    vector<int> A = {20, 15, 10, 17};
    int requirement = 7;

    cout << "Exact Height is: " << maxHeight(A, requirement) << endl;

    return 0;
}