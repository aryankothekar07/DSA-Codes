#include <iostream>
using namespace std;
int n, target;
int w[20], x[20];
void sumOfSubsets(int s, int k, int r)
{
    x[k] = 1;
    if (s + w[k] == target) 
    {
        // Found a subset
        cout << "Subset: ";
        for (int i = 0; i <= k; i++) 
        {
            if (x[i] == 1)
                cout << w[i] << " ";
        }
        cout << endl;
    }
    else if (s + w[k] + w[k + 1] <= target) 
        sumOfSubsets(s + w[k], k + 1, r - w[k]);
    if ((s + r - w[k] >= target) && (s + w[k + 1] <= target)) 
    {
        x[k] = 0;
        sumOfSubsets(s, k + 1, r - w[k]);
    }
}
int main() 
{
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) 
        cin >> w[i];
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(w[i] > w[j])
            {
                int temp = w[i];
                w[i] = w[j];
                w[j] = temp;
            }
        }
    }
    cout << "Enter target sum: ";
    cin >> target;
    int total = 0;
    for (int i = 0; i < n; i++)
        total += w[i];
    sumOfSubsets(0, 0, total);
    return 0;
}