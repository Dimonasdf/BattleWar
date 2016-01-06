#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <time.h>

#define _hp      20
#define _mp      20
#define _ehp     20

#define _dmg1     1
#define _mcos1    0
#define _selfdmg1 0

#define _dmg2     2
#define _mcos2    1
#define _selfdmg2 0

#define _dmg3     10
#define _mcos3    15
#define _selfdmg3 1

using namespace std;
int hp = _hp, mp = _mp, ehp = _ehp;
char action;

int random (int _min, int _max)
{
    int a = rand() % 1000+1;
    int b = time(NULL);
    srand (a*b);
    int r = rand() % _max+_min;
    return r;
}
int p_attack (string weapon)
{
    if (weapon == "sword")
        {
        cout << "You sliced the enemy with your sword." << endl;
        ehp -= _dmg1;
        mp -= _mcos1;
        hp -= _selfdmg1;
        }
    if (weapon == "magic")
        {
        cout << "You cast a devastating Magic Missile." << endl;
        ehp -= _dmg2;
        mp -= _mcos2;
        hp -= _selfdmg2;
        }
    if (weapon == "ult")
        {
        cout << "You summoned Ultima!" << endl;
        ehp -= _dmg3;
        mp -= _mcos3;
        hp -= _selfdmg3;
        }
    return 0;
}
int e_attack (string weapon)
{
        if (weapon == "sword")
        {
        cout << "The enemy used his sword." << endl << endl;
        hp -= _dmg1;
        }
        if (weapon == "magic")
        {
        cout << "The enemy casts a Magic Missile." << endl << endl;
        hp -= _dmg2;
        }
    return 0;
}
void win ()
{
    cout << "You win." << endl << endl;
    system("pause");
}
void lose ()
{
    cout << "You lose." << endl << endl;
    system("pause");
}
void nomana ()
{
    cout << "Not enough mana." << endl << endl;
    system("pause");
}





int main()
{

label:
system("cls");
cout << "Enemy HP: " << ehp << endl
<< "Your HP: " << hp << endl
<< "Your MP: " << mp << endl
<< endl
<< "(1) Attack with sword" << endl
<< "(2) Use magic missile" << endl
<< "(3) Summon demon" << endl << endl;
cin >> action;
cout << endl << "Status:" << endl;

switch (action)
{
case '1':
{
if (mp >= _mcos1)
{
    p_attack ("sword");

    if (ehp > 0)
    {
        switch (random (1,2) + '0')
        {
        case '1':
        {
        e_attack ("sword");
        break;
        }
        case '2':
        {
        e_attack ("magic");
        break;
        }
        }
    }
    else
    {
        win();
        return 0;
    }
    if (hp <= 0)
    {
        lose();
        return 0;
    }
}
else
    {
        nomana();
        goto label;
    }
break;
}

case '2':
{
if (mp >= _mcos2)
{
    p_attack ("magic");

    if (ehp > 0)
    {
        switch (random (1,2) + '0')
        {
        case '1':
        {
        e_attack ("sword");
        break;
        }
        case '2':
        {
        e_attack ("magic");
        break;
        }
        }
    }
    else
    {
        win();
        return 0;
    }

    if (hp <= 0)
    {
        lose();
        return 0;
    }
}
else
    {
        nomana();
        goto label;
    }
break;
}

case '3':
{
if (mp >= _mcos3)
{
    p_attack ("ult");

    if (ehp > 0)
    {
        switch (random (1,2) + '0')
        {
        case '1':
        {
        e_attack ("sword");
        break;
        }
        case '2':
        {
        e_attack ("magic");
        break;
        }
        }
    }
    else
    {
        win();
        return 0;
    }

    if (hp <= 0)
    {
        lose();
        return 0;
    }
}
else
    {
        nomana();
        goto label;
    }
break;
}

default:
{
    cout << "Ability not learned." << endl << endl;
    system("pause");
    goto label;
    break;
}
}
system("pause");
goto label;
return 0;
}
