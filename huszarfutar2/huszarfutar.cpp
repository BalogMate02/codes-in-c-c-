//Balog Mate iem1 4405 huszarfutar
/*Egy 𝑛 × 𝑛 méretű sakktáblán az (𝑥, 𝑦) pozíción található egy futár és az
(𝑥0, 𝑦0) pozíción egy ló. A lónak el kell jutnia erről a helyről az (𝑥1, 𝑦1) pozícióra,
anélkül, hogy egy bizonyos négyzetre többször lépne illetve, hogy olyan helyen
állna meg, ahonnan a futár kiütheti. Írjuk ki, hogy hányféleképpen lehetséges ez!
*/
#include <iostream>
using namespace std;

struct poz
{
    short x, y;
};

void kiir(short a[7][7])
{
    for (short i = 1;i <= 6;i++)
    {
        for (short j = 1;j <= 6;j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
    cout << '\n';
}

//void futo(short a[7][7], poz f)

bool okes(short n, poz f, short x,short y, short a[7][7])
{
    if (x<1 || y<1 || x>n || y>n)
        return false;//kilep 
    if (x - y == f.x - f.y || x + y == f.x + f.y)
        return false;//futar utjaban van
    if (a[x][y] == 1)
        return false;//volt mar ott
    return true;
}

void huszar(short n, poz f, short x, short y, poz c, short xl[8],short yl[8], int &s, short a[7][7])
{
    //cout << "faszom";
    if (x == c.x && y == c.y)
    {
        //cout << s;
        s = s + 1;
    }
    else
    {
        if (okes(n, f, x, y, a))
        {
            //kiir(a);
                /*6
                4 4
                6 4
                4 6*/
                /*short x, y;
                x = l.x + xl[i];
                y = l.y + yl[i];*/
            a[x][y] = 1;
            for (short i = 0;i < 8;i++)
            {
               // kiir(a);
                //l.x = l.x + xl[i];
                //l.y = l.y + yl[i];
                huszar(n, f, x+xl[i],y+yl[i], c, xl, yl, s, a);
            }
            a[x][y] = 0;
        }
    }
}

int main()
{
    short n, a[7][7] = {};
    int s = 0;
    poz futar, lo, cel;
    short xl[8] = { 2, 1,-1,-2, -2, -1, 1, 2 };
    short yl[8] = { 1, 2, 2, 1, -1, -2,-2,-1 };
    cin >> n;
    cin >> futar.x >> futar.y;
    cin >> lo.x >> lo.y;
    cin >> cel.x >> cel.y;
   // a[lo.x][lo.y] = 1;
   /* cout << "most";
    cout << futar.x << futar.y;
    cout << lo.x << lo.y;
    cout << cel.x << cel.y;*/
    huszar(n, futar, lo.x, lo.y, cel, xl, yl, s, a);
    cout << s;
}

