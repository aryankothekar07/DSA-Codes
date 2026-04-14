#include <iostream>
using namespace std;
int getLength(int n)
{
    int count = 0;
    while(n > 0)
    {
        count++;
        n /= 10;
    }
    return count;
}
int karatsuba(int x, int y)
{
    if(x < 10 || y < 10)
        return x * y;
    int n = max(getLength(x), getLength(y));
    int m = n / 2;
    int power = 1;
    for(int i = 0; i < m; i++)
        power *= 10;
    int a = x / power;
    int b = x % power;
    int c = y / power;
    int d = y % power;
    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int ad_bc = karatsuba(a+b, c+d) - ac - bd;
    return ac * power * power + ad_bc * power + bd;
}
int main()
{
    int x, y;
    cout << "Enter 1st number: ";
    cin >> x;
    cout << "Enter 2nd number: ";
    cin >> y;
    cout << "Product: " << karatsuba(x, y) << endl;
    return 0;
}
