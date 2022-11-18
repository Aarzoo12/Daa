#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct item
{
    int profit, weight;
};
int compare(item a, item b) // compare and find which item has more profit/weight ratio
{
    double r1 = ((double)a.profit / a.weight);
    double r2 = ((double)b.profit / b.weight);
    if (r1 > r2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int comparebyprofit(item a, item b) // compare and find which item has more profit/weight ratio
{
    double r1 = a.profit;
    double r2 = b.profit;
    if (r1 > r2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int comparebyweight(item a, item b) // compare and find which item has more profit/weight ratio
{
    double r1 = a.weight;
    double r2 = b.weight;
    if (r1 > r2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int knapsackbyprofit(int weight, item a[], int n)
{
    sort(a, a + n, comparebyprofit);
    double current_wt = 0, total_profit = 0, remaining_capacity;
    for (int i = 0; i < n; i++)
    {
        if (current_wt + a[i].weight <= weight) // check if after adding current element knapsack overflows or not
        {
            total_profit = total_profit + a[i].profit; // update profit
            current_wt = current_wt + a[i].weight;     // update weight
        }
        else
        {
            return total_profit;
        }
    }
}
int knapsackbyweight(int weight, item a[], int n)
{
    sort(a, a + n, comparebyweight);
    double current_wt = 0, total_profit = 0, remaining_capacity;
    for (int i = 0; i < n; i++)
    {
        if (current_wt + a[i].weight <= weight)
        // check if after adding current element knapsack overflows or not
        {
            total_profit = total_profit + a[i].profit; // update profit
            current_wt = current_wt + a[i].weight;     // update weight
        }
        else
        {
            return total_profit;
        }
    }
}
double knapsack(int weight, item a[], int n)
{
    sort(a, a + n, compare); // sort according to profit to weight ratio
    double current_wt = 0, total_profit = 0, remaining_capacity;
    for (int i = 0; i < n; i++)
    {
        if (current_wt + a[i].weight <= weight) // check if after adding current element knapsack overflows or not
        {
            total_profit = total_profit + a[i].profit; // update profit
            current_wt = current_wt + a[i].weight;     // update weight
        }
        else
        {
            remaining_capacity = weight - current_wt;
            total_profit = total_profit + a[i].profit * ((double)remaining_capacity / a[i].weight);
            // if knapsack over flows add fraction of the item to be added in to knapsack
            break;
        }
    }
    return total_profit;
}
int main()
{
    int n;
    cout << "Enter number of elements";
    cin >> n;
    item a[n];
    cout << "enter items in pairs of profit, weight";
    for (int i = 0; i < n; i++)
    {
        int p, w;
        cin >> p;
        cin >> w;
        a[i] = {p, w};
    }
    int capa;
    cout << "Enter sack capacity";
    cin >> capa;
    cout << "max profit by p/w ratio " << knapsack(capa, a, n) << endl;
    cout << "max profit by max profit " << knapsackbyprofit(capa, a, n)<< endl;
    cout << "max profit by min weight " << knapsackbyweight(capa, a, n) << endl;
}
