/*Balog Mate 4405 iem1, kiralynokk
Helyezzünk el 𝑛 darab királynőt egy 𝑛 × 𝑛-es sakktáblán minden lehetséges
módon, úgy, hogy ne üssék egymást. Számoljuk meg, hogy hányféleképpen
lehetséges ez és írassuk ki a megadott sorszámú konfigurációkat a lexikografikus
sorrendet tekintve.*/

#include <iostream>
#include <cstdlib>
using namespace std;

void kiir(int a[16], int n)
{
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
            if (a[i] == j)
                cout << "Q";
            else
                cout << ".";
        cout << '\n';
    }
    cout << '\n';
}

bool megfelel(int a[16], int n, int x)
{
    for (int i = 1;i <= n;i++)
        if (a[i] == x || n + 1 - i == abs(x - a[i]))
            return false;
    return true;
}

void atrak(int b[16][12], int a[16], int i, int n)
{
    for (int j = 1;j <= n;j++)
        b[i][j] = a[j];
}

void kiralyno(int a[16], int k, int n, int p[11], int& j, int& s, int b[16][12])
{
    if (k == n + 1)
    {
        s = s + 1;
        if (s == p[j])
        {
            //kiir(a, n);
            atrak(b, a, j, n);
            b[j][n + 1] = p[j];
            j++;
        }
    }
    else 
        for (int i=1;i<=n;i++)
            if (megfelel(a, k - 1, i))
            {
                a[k] = i;
                kiralyno(a, k + 1, n,p,j,s,b);
            }
}

int main()
{
    int  a[16], n, q, p[11], o[11], s = 0, j = 1, sz, i, l,b[16][12];
    cin >> n;
    cin >> q;
    if (q > 0)
    {
        cin >> p[1];
        o[1] = p[1];
        for (i = 2;i <= q;i++)
        {
            cin >> sz;
            o[i] = sz;
            l = i - 1;
            while (l > 0 && p[l] > sz)
            {
                p[l + 1] = p[l];
                l--;
            }
            p[l+1] = sz;
        }
    }
    kiralyno(a, 1, n, p, j, s, b);
    for (i = 1;i <= q;i++)
    {
        j = 1;
        while (o[i] != b[j][n + 1])
            j++;
        kiir(b[j], n);
    }
    cout << s;
}

