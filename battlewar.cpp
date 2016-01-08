#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <time.h>
#include <math.h>
#include <conio.h>

using namespace std;

#define _hp      100                     //your HP
#define _mp      50                      //your MP
#define _ehp     100                     //enemy HP

#define _dmg1     1                      //enemy's 1 ability damage
#define _dmg2     2                      //enemy's 2 ability damage

#define x 20                             // room rows
#define y 45                             // room columns
#define q 10                             // quantity of enemies

int a = 0, b = 0;                        // player position variables
int field [x][y] = {};                   //field array
int _swap [q];                           //swap array for enemy positions

int hp = _hp, mp = _mp, ehp = _ehp;
//int x = 3, y = 3;                     //’ - способность, Y - значение характеристики
int ac[3][3] =
{
    {  1,  0, 0 },                      //1 ability - damage to enemy / mana cost / self damage
    {  2,  1, 0 },                      //2 ability - damage to enemy / mana cost / self damage
    { 10, 15, 1 }                       //3 ability - damage to enemy / mana cost / self damage
};
int e1 = 0, e2 = 0;                     //experience - swords / magic
int a1 = 0, a2 = 0, a3 = 0;             //damage increase due to certain experience - swords / missile / summon

char action;

void win ()                             //battle win message
{
    cout << "You win." << endl << endl;
    system("pause");
}
void lose ()                            //battle lose message
{
    cout << "You lose." << endl << endl;
    system("pause");
}
void nomana ()                          //no mana message
{
    cout << "Not enough mana." << endl << endl;
    system("pause");
}



int random (int _min, int _max)         //megarandom by Dimonasdf
{
        srand ((rand() % 10000+1)*time(0)*clock());
        int r = rand() % _max+_min;
        return r;
}



int main()
{
for (int p=0; p<q; p++)
{
    _swap [p] = random(0,x);
    field [_swap[p]][random (0,y)] = 2;
}

label:
{
    {
    field [a][b] = 1;
    system("cls");
    for (int i=0;i<x;i++)
        {
        for (int j=0;j<y;j++)
            {
            cout << field [i][j];
            }
        cout << endl;
        }
        switch (getch())
        {
            case '4':
            {
                field [a][b] = 0;
                if (b>0)
                {
                b--;
                break;
                }
                else
                {
                break;
                }
            }
            case '8':
            {
                field [a][b] = 0;
                if (a>0)
                {
                a--;
                break;
                }
                else
                {
                break;
                }
            }
            case '6':
            {
                field [a][b] = 0;
                if (b<y-1)
                {
                b++;
                break;
                }
                else
                {
                break;
                }
            }
            case '2':
            {
                field [a][b] = 0;
                if (a<x-1)
                {
                a++;
                break;
                }
                else
                {
                break;
                }
            }
            default:
            {
                break;
            }
        }
    }
goto label;
}

return 0;
}
    int p_attack (string weapon)            //player's attack
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
    int e_attack (string weapon)            //enemy's attack
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

int fight()                                 //fight module (works well standalone but is not yet implemented in the moving sequence)
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

switch (getch())
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
        system("pause");
        break;
    }

    system("pause");
} //switch

} //while
return 0;
} //fight


