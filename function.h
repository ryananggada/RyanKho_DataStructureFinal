#ifndef function_h
#define function_h

#include "class.h"

string InputName()
{
    string name;
    cout << "Enter name: ";
    cin >> name;
    return name;
}

// choosing the difficulty
string DiffPick()
{
    int choice;
    string diff;
    
    while (true)
    {
        cout << "Select your difficulty" << endl;
        cout << "[1] Normal" << endl;
        cout << "[2] Hard (not recommended if you don't play Normal before)" << endl;
        cout << ">> ";
        cin >> choice;
        cout << endl;
        
        if (choice == 1)
        {
            diff = "N";
            break;
        }
        
        else if (choice == 2)
        {
            diff = "H";
            break;
        }
        
        else
        {
            cout << "Please input again!" << endl;
        }
    }
    
    return diff;
}

// chossing the job of player
Player ChooseJob(string name)
{
    Player p;
    int job_no;
    
    while (true)
    {
        cout << endl << "Select your class" << endl;
        cout << "[1] Warrior" << endl;
        cout << "[2] Mage" << endl;
        cout << "[3] Berserker" << endl;
        cout << ">> ";
        cin >> job_no;
        cout << endl;
    
        if (job_no == 1)
        {
            p = Player(name, "Warrior", 1, 25, 25, 4, 5, 2, 7);
            break;
        }
    
        else if (job_no == 2)
        {
            p = Player(name, "Mage", 1, 20, 20, 4, 3, 5, 9);
            break;
        }
    
        else if (job_no == 3)
        {
            p = Player(name, "Berserker", 1, 28, 28, 5, 4, 1, 5);
            break;
        }
    
        else
        {
            cout << "Please input again!" << endl;
        }
    }
    
    return p;
}

// used to make the unique ID for player weapon assignment
int JobNumber(Player p)
{
    int num = 0;
    
    if (p.GetJob() == "Warrior")
    {
        num = 1;
    }
    
    else if (p.GetJob() == "Mage")
    {
        num = 2;
    }
    
    else if (p.GetJob() == "Berserker")
    {
        num = 3;
    }
    
    return num;
}

// when player attacks the enemy
void PlayerAttack(Player p, CurrentEnemy &e, CurrentWeapon pw[3], int choice)
{
    int damage = 0;
    int attack = pw[choice-1].GetMight() + p.GetPower();
    
    cout << endl << "You used " << pw[choice-1].GetName() << endl;
    
    if (rand() % 100 + 1 <= pw[choice-1].GetHitRate() - e.GetSpeed())
    {
        if (pw[choice-1].GetType() == "Physical")
        {
            damage = attack - e.GetDefense();
        }
        
        else if (pw[choice-1].GetType() == "Magical")
        {
            damage = attack - e.GetResist();
        }
        
        if (rand() % 100 + 1 <= pw[choice-1].GetCritical())
        {
            cout << "CRITICAL!" << endl;
            damage *= 3;
        }
        
        if (damage > 0)
        {
            cout << damage << " damage!" << endl;
        }
        
        else
        {
            cout << "No damage!" << endl;
            damage = 0;
        }
    }
    
    else
    {
        cout << "Miss!" << endl;
    }
    
    e.TakeDamage(damage);
}

// when enemy attacks the player
void EnemyAttack(Player &p, CurrentEnemy e, CurrentWeapon ew)
{
    int damage = 0;
    int attack = ew.GetMight() + e.GetPower();
    
    if (e.GetHealth() > 0)
    {
        cout << endl << e.GetName() << " used " << ew.GetName() << endl;
        
        if (rand() % 100 + 1 <= ew.GetHitRate() - p.GetSpeed())
        {
            if (ew.GetType() == "Physical")
            {
                damage = attack - p.GetDefense();
            }
                
            else if (ew.GetType() == "Magical")
            {
                damage = attack - p.GetResist();
            }
                
            if (rand() % 100 + 1 <= ew.GetCritical())
            {
                cout << "CRITICAL!" << endl;
                damage *= 3;
            }
                
            if (damage > 0)
            {
                cout << damage << " damage!" << endl;
            }
                
            else
            {
                cout << "No damage!" << endl;
                damage = 0;
            }
        }
        
        else
        {
            cout << "Miss!" << endl;
        }
        
        p.TakeDamage(damage);
    }
    
    else
    {
        cout << endl << "Enemy died!" << endl;
    }
}

// choosing weapon from the weapon inventory
int ChooseWeapon(CurrentWeapon pi[3])
{
    int choice;
    
    while (true)
    {
        cout << endl << "Choose your weapon" << endl;
    
        for (int i = 0; i < 3; i++)
        {
            cout << "[" << i+1 << "] ";
            pi[i].SeeAWeapon();
        }
    
        cout << ">> ";
        cin >> choice;
        cout << endl;
        
        if (choice >= 1 && choice <= 3)
        {
            break;
        }
        
        else
        {
            cout << endl << "Please input again!" << endl;
        }
    }
    
    return choice;
}

// use the item
int UsingItems(Item items[3])
{
    int choice;
    
    while (true)
    {
        cout << endl << "Choose your items" << endl;
        
        for (int i = 0; i < 3; i++)
        {
            cout << "[" << i+1 << "] ";
            items[i].SeeAnItem();
        }
        
        cout << ">> ";
        cin >> choice;
        cout << endl;
        
        if (choice >= 1 && choice <= 3)
        {
            break;
        }
        
        else
        {
            cout << "Please input again!" << endl;
        }
    }
    
    return choice;
}

// item is going to be used by player
bool ItemGettingUsed(Player &p, Item *items, int choice)
{
    bool canuse = false;
    
    if (items[choice-1].GetStock() > 0)
    {
        items[choice-1].UseItem();
        cout << "You ate a " << items[choice-1].GetName() << "!" << endl;
        cout << "Health is restored!" << endl;
        p.RestoreHealth(items[choice-1].GetEffect());
        canuse = true;
    }
    
    else
    {
        cout << "You do not have these items!" << endl;
    }
    
    return canuse;
}

// battle phase
void Battle(Player &p, CurrentEnemy &e, CurrentWeapon pw[3], CurrentWeapon ew, Item *items)
{
    int choice, weapon_no;
    
    while (true)
    {
        p.BattlePhaseStats();
        e.BattlePhaseStats();
    
        cout << endl << "[1] Attack" << endl;
        cout << "[2] Use items" << endl;
        cout << ">> ";
        cin >> choice;
        
        if (choice == 1)
        {
            weapon_no = ChooseWeapon(pw);
            PlayerAttack(p, e, pw, weapon_no);
            EnemyAttack(p, e, ew);
        }
        
        else if (choice == 2)
        {
            int temp = UsingItems(items);
            bool temp_bool = ItemGettingUsed(p, items, temp);
            
            if (temp_bool == true)
            {
                EnemyAttack(p, e, ew);
            }
        }
        
        else
        {
            cout << endl << "Please input again!" << endl;
        }
        
        if (e.GetHealth() <= 0 or p.GetCurrentHealth() <= 0)
        {
            break;
        }
    }
}

#endif
