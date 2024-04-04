//Balog Mate gi1 4405 l51
/*Legyen a következő játék: az egyik játékos (Játékos1) gondol egy 1 és 1000
közötti természetes számra. A másik játékosnak (Játékos2) ki kell találnia ezt
a számot minél kevesebb próbálgatással. A titkos szám „birtokosa” (Játékos1)
egy-egy találgatásra csak annyit válaszol, hogy a titkos szám kisebb vagy nagyobb
mint a másik játékos (Játékos2) által feltételezett szám.
Írjunk programot amely a fenti játékot szimulálja, úgy, hogy a programunk a
Játékos2, azaz ő találja ki a felhasználó titkos számát.
*/

#include <iostream>
using namespace std;

void beolvas(unsigned int a, unsigned int e, unsigned int u)
{

	unsigned int i = 1, k;
	while (i <= 10)
	{
		k = (e + u) / 2;
		cout << k;
		cout << endl;
		cin >> a;
		if (a == 0)
		{
			i = 12;
		}
		if (a == -1)
		{
			u = k - 1;
		}
		if (a == 1)
			e = k + 1;
		i++;
	}
	if (i != 13)
		cout << "Wrong Answer";
}

int main()
{
	unsigned int a = 0, e=1, u=1000;
	beolvas(a, e, u);
}

