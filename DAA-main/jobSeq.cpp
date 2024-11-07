#include<bits/stdc++.h>
using namespace std;


struct jobs
{
    int id;
    int deadline;
    int profit;

    /* data */
};

bool comp(jobs a, jobs b)
{
    return a.profit>b.profit;
}

void jobSequencing(vector<jobs> &job,int n){

    sort(job.begin(), job.end(),comp);

    vector<int > result(n,-1);
    vector<bool> slot(n,false);

    int maxprofit = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=min(job[i].deadline,n)-1;j>=0;j--)
        {
            if(slot[j]==false)
            {
                slot[j]=true;
                maxprofit +=job[i].profit;
                result[j] = i;

                break;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(result[i]!=-1)
        {
            cout<<job[result[i]].id<<" ";
        }
    }

    cout<<maxprofit<<endl;
}

int main()
{
    int n=5;

    vector<jobs> job={
        {1, 1, 53},
        {2, 2, 27},
        {3, 3, 49},
        {4, 2, 65},
        {5, 1, 57}
    };

    jobSequencing(job,n);



    return 0;
}
