//Balog Mate 4405 gi1 l5 4 
/*Adott egy 𝑛 elem˝u t¨omb, mely 32 bites el˝ojeles eg´esz sz´amokat tartalmaz
´es egy 𝑥 32 bites el˝ojeles eg´esz sz´am. Hat´arozzuk meg, hogy l´etezik-e k´et olyan
eleme a t¨ombnek, melyek ¨osszege pontosan 𝑥. Alkalmazzunk bin´aris keres´est!*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct elem
{
    int sz, i;
}sza;

void binkeres(elem a[100000], int e, int u, int i, int &k, int x)
{
    if (e > u)
        k = -1;
    else
    {
        k = (e + u) / 2;
        if (a[k].sz + a[i].sz < x)
            binkeres(a, k + 1, u, i, k, x);
        else
            if (a[k].sz + a[i].sz > x)
                binkeres(a, e, k - 1, i, k, x);
    }
}

void keres(elem a[100000], int n, int x)
{
    int i = 0, k = n/2;
    while (i<n)
    {
        binkeres(a, 0, n, i, k, x);
        if (k != -1 && i != k)
        {
            cout << 1 << '\n' << a[i].i + 1 << " " << a[k].i + 1;
            i = n + 2;
        }
        i++;
    }
    if (k == -1)
        cout << 0;
}
bool szam(sza a, sza b)
{
    return a.sz < b.sz;
}

int main()
{
    int n, x, i;
    cin >> n >> x;
    elem a[100000];
    for (i = 0;i < n;i++)
    {
        cin >> a[i].sz;
        a[i].i = i;
    }
    sort(a, a + n, szam);
   
    keres(a, n, x);
}

