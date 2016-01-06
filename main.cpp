#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <time.h>
#include <math.h>

#define _hp      100                     //хп гг
#define _mp      50                     //мп гг
#define _ehp     100                     //хп врага

#define _dmg1     1                     //урон 1 способности врага
#define _dmg2     2                     //урон 2 способности врага

using namespace std;                    //хз что такое, но без него не работает

int hp = _hp, mp = _mp, ehp = _ehp;     //инты
//int x = 3, y = 3;                     //Х - способность, Y - значение характеристики
int ac[3][3] =
{
    {  1,  0, 0 },                      //1 способность - урон врагу / мана / урон себе
    {  2,  1, 0 },                      //2 способность - урон врагу / мана / урон себе
    { 10, 15, 1 }                       //3 способность - урон врагу / мана / урон себе
};
int e1 = 0, e2 = 0;                     //опыт
int a1 = 0, a2 = 0, a3 = 0;             //амплификаторы урона

char action;                            //чары

int random (int _min, int _max)         //мегарандом от Димона
{
    int a = rand() % 1000+1;
    int b = time(NULL);
    srand (a*b);
    int r = rand() % _max+_min;
    return r;
}
void win ()                             //вин месседж
{
    cout << "You win." << endl << endl;
    system("pause");
}
void lose ()                            //луз месседж
{
    cout << "You lose." << endl << endl;
    system("pause");
}
void nomana ()                          //нет маны месседж
{
    cout << "Not enough mana." << endl << endl;
    system("pause");
}

    int p_attack (string weapon)            //атака игрока
{
    if (weapon == "sword")
        {
        cout << "You sliced the enemy with your sword for " << ac [0][0] + a1 << " damage." << endl;
        ehp -= ac [0][0] + a1;
        mp -= ac [0][1];
        hp -= ac [0][2];
        e1 += 1;
        cout << "Experience with swords is " << e1 << "." << endl << endl;
        }
    if (weapon == "magic")
        {
        cout << "You cast a devastating magic missile for " << ac [1][0] + a2 << " damage." << endl;
        ehp -= ac [1][0] + a2;
        mp -= ac [1][1];
        hp -= ac [1][2];
        e2 += 1;
        cout << "Experience with magic is " << e2 << "." << endl << endl;
        }
    if (weapon == "ult")
        {
        cout << "You summoned Ultima! It dealt " << ac [2][0] + a3 << " damage to the enemy and " << ac [2][2] << " damage to you." << endl;
        ehp -= ac [2][0] + a3;
        mp -= ac [2][1];
        hp -= ac [2][2];
        e2 += 5;
        cout << "Experience with magic is " << e2 << "." << endl << endl;
        }
    return 0;
}
    int e_attack (string weapon)            //атака врага
{
        if (weapon == "sword")
        {
        cout << "The enemy used his sword for " << _dmg1 << " damage." << endl << endl;
        hp -= _dmg1 /*ac[0][0]*/;
        }
        if (weapon == "magic")
        {
        cout << "The enemy casts a magic missile for " << _dmg2 << " damage." << endl << endl;
        hp -= _dmg2 /*ac[1][0]*/;
        }
    system("pause");
    return 0;
}

int main()
{

while (1==1)
{
system("cls");

a1 = e1/10;
a2 = a3 = e2/10;

cout << "Enemy HP: " << ehp << endl
<< "Your HP: " << hp << endl
<< "Your MP: " << mp << endl
<< endl
<< "(1) Attack with sword (Damage: " << ac[0][0] + a1 << ", Mana cost: " << ac[0][1] << ", SelfDamage: " << ac [0][2] << ")" << endl
<< "(2) Use magic missile (Damage: " << ac[1][0] + a2 << ", Mana cost: " << ac[1][1] << ", SelfDamage: " << ac [1][2] << ")" << endl
<< "(3) Summon demon    (Damage: " << ac[2][0] + a3 << ", Mana cost: " << ac[2][1] << ", SelfDamage: " << ac [2][2] << ")" << endl << endl;
cin >> action;
cout << endl << "Status:" << endl;

switch (action)
{
    case '1':
    {
        if (mp >= ac[0][1])
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
                e1 += 5;
                cout << "You smashed the enemy with your sword. Experience with swords is now " << e1 << "." << endl;
                win();
                return 0;
            }
            if (hp <= 0)
            {
                lose();
                return 0;
            }
                break;
        }
        else
        {
            nomana();
            break;
        }
    }
    case '2':
    {
        if (mp >= ac[1][1])
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
                e2 += 5;
                cout << "The eneny was destroyed. Experience with magic is now " << e2 << "." << endl;
                win();
                return 0;
            }
            if (hp <= 0)
            {
                lose();
                return 0;
            }
                break;
        }
        else
        {
            nomana();
            break;
        }
    }
    case '3':
    {
        if (mp >= ac[2][1])
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
                e2 += 15;
                cout << "The enemy was annihilated. Experience with magic is now " << e2 << "." << endl;
                win();
                return 0;
            }
            if (hp <= 0)
            {
                lose();
                return 0;
            }
                break;
        }
        else
        {
            nomana();
            break;
        }
    }
    default:
    {
        cout << "Ability not learned." << endl << endl;
        break;
    }

    system("pause");
} //switch

} //while
return 0;
} //main

