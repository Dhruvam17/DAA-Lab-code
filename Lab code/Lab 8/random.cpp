#include <bits/stdc++.h>
using namespace std;

class Activity
{
public:
    int start, finish;
};

bool activityCompare(Activity s1, Activity s2)
{
    return (s1.finish < s2.finish);
}

void populateActivities(vector<Activity> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 10;
        int y = x + rand() % 10;
        Activity temp;
        temp.start = x;
        temp.finish = y;
        a.push_back(temp);
    }
}

vector<Activity> findMaxActivities(vector<Activity> arr)
{
    int n = arr.size();
    vector<Activity> ans;
    sort(arr.begin(), arr.end(), activityCompare);

    int i = 0;
    ans.push_back(arr[i]);

    for (int j = 1; j < n; j++)
    {

        if (arr[j].start >= arr[i].finish)
        {
            ans.push_back(arr[j]);
            i = j;
        }
    }
    return ans;
}

int main()
{
    vector<Activity> activities;
    int n;
    cout << "Enter the number of activities : ";
    cin >> n;
    populateActivities(activities, n);

    vector<Activity> ans = findMaxActivities(activities);

    cout << "Max activities : " << ans.size() << endl;
    cout << "The activities that are executed are as follows : " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "(" << ans[i].start << "," << ans[i].finish << ")" << endl;
    }

    return 0;
}
