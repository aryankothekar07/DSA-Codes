#include <iostream>
#include <vector>
using namespace std;
void knapsack(int i, vector<int>& wt, vector<int>& val, int W, int curr_wt, int curr_val, int& max_val) 
{
    if (curr_wt > W) 
        return;
    if (i == wt.size()) 
    {
        max_val = max(max_val, curr_val);
        return;
    }
    knapsack(i + 1, wt, val, W, curr_wt, curr_val, max_val);
    knapsack(i + 1, wt, val, W, curr_wt + wt[i], curr_val + val[i], max_val);
}
int main() 
{
    int n;
    cout << "Total number of items: ";
    cin >> n;
    vector<int> wt(n);
    vector<int> val(n);
    cout << "Enter the weights of each item: ";
    for(int i = 0; i < n; i++)
        cin >> wt[i];
    cout << "Enter the values of each item: ";
    for(int i = 0; i < n; i++)
        cin >> val[i];
    int W;
    cout << "Enter weight of knapsack: ";
    cin >> W;
    int max_val = 0;
    knapsack(0, wt, val, W, 0, 0, max_val);
    cout << "Maximum value: " << max_val << endl;
}
