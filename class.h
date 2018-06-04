#ifndef class_h
#define class_h

#include <iostream>
#include <cstdlib>

// using "using namespace std" is considered a bad practice
using std::string;
using std::cout;
using std::cin;
using std::endl;

// class of weapon
class CurrentWeapon
{
    private:
        string idn;
        string name;
        string type;
        int might;
        int hit_rate;
        int critical;
    
    public:
        CurrentWeapon()
        {
            idn = "";
            name = "";
            type = "";
            might = 0;
            hit_rate = 0;
            critical = 0;
        }
    
        CurrentWeapon(string idn, string name, string type, int might, int hit_rate, int critical)
        {
            this->idn = idn;
            this->name = name;
            this->type = type;
            this->might = might;
            this->hit_rate = hit_rate;
            this->critical = critical;
        }
    
        string GetName()
        {
            return this->name;
        }
    
        string GetType()
        {
            return this->type;
        }
    
        int GetMight()
        {
            return this->might;
        }
    
        int GetHitRate()
        {
            return this->hit_rate;
        }
    
        int GetCritical()
        {
            return this->critical;
        }
    
        void SeeAWeapon()
        {
            cout << this->name << " | Type: " << this->type << " | Might: " << this->might << " | Hit Rate: " << this->hit_rate << " | Crit: " << this->critical << endl;
        }
};

// creates a linked list of weapon
struct WeaponNode
{
    string idn;
    string name;
    string type;
    int might;
    int hit_rate;
    int critical;
    WeaponNode *next;
};

class WeaponList
{
    private:
        WeaponNode *head, *tail;
    
    public:
        WeaponList()
        {
            head = NULL;
            tail = NULL;
        }
    
        // create new linked list of weapon
        void CreateWeapon(string idn, string name, string type, int might, int hit_rate, int critical)
        {
            WeaponNode *temp = new WeaponNode;
            temp->idn = idn;
            temp->name = name;
            temp->type = type;
            temp->might = might;
            temp->hit_rate = hit_rate;
            temp->critical = critical;
            temp->next = NULL;
            
            if (head == NULL)
            {
                head = temp;
                tail = temp;
                temp = NULL;
            }
            
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
    
        // this will take out a data from the linked list and assign it to the class CurrentWeapon
        CurrentWeapon AssignWeapon(string idn)
        {
            CurrentWeapon weapon;
            WeaponNode *temp = new WeaponNode;
            temp = head;
            bool found = false;
            
            while (found == false && temp != NULL)
            {
                if (temp->idn == idn)
                {
                    weapon = CurrentWeapon(temp->idn, temp->name, temp->type, temp->might, temp->hit_rate, temp->critical);
                    found = true;
                }
                
                else
                {
                    temp = temp->next;
                }
            }
            
            if (found == false)
            {
                cout << "Weapon not found!" << endl;
            }
            
            return weapon;
        }
};

// class of enemy
class CurrentEnemy
{
    private:
        string name;
        int health;
        int power;
        int defense;
        int resist;
        int speed;
    
    public:
        CurrentEnemy()
        {
            name = "";
            health = 0;
            power = 0;
            defense = 0;
            resist = 0;
            speed = 0;
        }
    
        CurrentEnemy(string name, int health, int power, int defense, int resist, int speed)
        {
            this->name = name;
            this->health = health;
            this->power = power;
            this->defense = defense;
            this->resist = resist;
            this->speed = speed;
        }
    
        string GetName()
        {
            return this->name;
        }
    
        int GetHealth()
        {
            return this->health;
        }
    
        int GetPower()
        {
            return this->power;
        }
    
        int GetDefense()
        {
            return this->defense;
        }
    
        int GetResist()
        {
            return this->resist;
        }
    
        int GetSpeed()
        {
            return this->speed;
        }
    
    
        // take damage from player
        void TakeDamage(int damage)
        {
            this->health -= damage;
        }
    
        void BattlePhaseStats()
        {
            cout << endl << this->name << endl;
            cout << "HP " << this->health << endl;
        }
};

// create enemy linked list
struct EnemyNode
{
    string idn;
    string name;
    int health;
    int power;
    int defense;
    int resist;
    int speed;
    EnemyNode *next;
};

class EnemyList
{
    private:
        EnemyNode *head, *tail;
    
    public:
        EnemyList()
        {
            head = NULL;
            tail = NULL;
        }
    
        // create linked list data of enemy
        void CreateEnemy(string idn, string name, int health, int power, int defense, int resist, int speed)
        {
            EnemyNode *temp = new EnemyNode;
            temp->idn = idn;
            temp->name = name;
            temp->health = health;
            temp->power = power;
            temp->defense = defense;
            temp->resist = resist;
            temp->speed = speed;
            
            if (head == NULL)
            {
                head = temp;
                tail = temp;
                temp = NULL;
            }
            
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
    
        // this will take out data from linked list and assign it to the class CurrentEnemy
        CurrentEnemy SpawnEnemy(string idn)
        {
            CurrentEnemy enemy;
            EnemyNode *temp = new EnemyNode;
            temp = head;
            bool found = false;
            
            while (found == false && temp != NULL)
            {
                if (temp->idn == idn)
                {
                    enemy = CurrentEnemy(temp->name, temp->health, temp->power, temp->defense, temp->resist, temp->speed);
                    found = true;
                }
                
                else
                {
                    temp = temp->next;
                }
            }
            
            if (found == false)
            {
                cout << "Enemy not found!" << endl;
            }
            
            return enemy;
        }
};

// class of player
class Player
{
    private:
        string name;
        string job;
        int level;
        int current_health;
        int max_health;
        int power;
        int defense;
        int resist;
        int speed;
    
    public:
        Player()
        {
            name = "";
            job = "";
            level = 0;
            current_health = 0;
            max_health = 0;
            power = 0;
            defense = 0;
            resist = 0;
            speed = 0;
        }
    
        Player(string name, string job, int level, int current_health, int max_health, int power, int defense, int resist, int speed)
        {
            this->name = name;
            this->job = job;
            this->level = level;
            this->current_health = current_health;
            this->max_health = max_health;
            this->power = power;
            this->defense = defense;
            this->resist = resist;
            this->speed = speed;
        }
    
        string GetJob()
        {
            return this->job;
        }
    
        int GetLevel()
        {
            return this->level;
        }
    
        int GetCurrentHealth()
        {
            return this->current_health;
        }
    
        int GetPower()
        {
            return this->power;
        }
    
        int GetDefense()
        {
            return this->defense;
        }
    
        int GetResist()
        {
            return this->resist;
        }
    
        int GetSpeed()
        {
            return this->speed;
        }
    
        // take damage from enemy
        void TakeDamage(int damage)
        {
            this->current_health -= damage;
        }
    
        // when an area is cleared, reset the health to max
        void ResetHealth()
        {
            this->current_health = this->max_health;
        }
    
        // restore the player's health
        void RestoreHealth(int restored)
        {
            if (this->current_health + restored >= this->max_health)
            {
                this->current_health = this->max_health;
            }
            
            else
            {
                this->current_health += restored;
            }
        }
    
        void BattlePhaseStats()
        {
            cout << endl << this->name << " | " << this->job << endl;
            cout << "HP " << this->current_health << "/" << this->max_health << endl;
        }
    
        void ViewPlayerStats()
        {
            cout << endl << "Name: " << this->name << endl;
            cout << "Job: " << this->job << endl;
            cout << "Level: " << this->level << endl;
            cout << "HP: " << this->max_health << endl;
            cout << "Power: " << this->power << endl;
            cout << "Defense: " << this->defense << endl;
            cout << "Resist: " << this->resist << endl;
            cout << "Speed: " << this->speed << endl;
        }
    
        // level up the player by random
        void LevelUp()
        {
            cout << "Level up!" << endl;
            this->level += 1;
            
            if (this->job == "Warrior")
            {
                if (rand() % 100 + 1 <= 85)
                {
                    cout << "Health increased by 2!" << endl;
                    this->current_health += 2;
                    this->max_health += 2;
                }
                
                if (rand() % 100 + 1 <= 70)
                {
                    cout << "Power increased by 1!" << endl;
                    this->power += 1;
                }
                
                if (rand() % 100 + 1 <= 65)
                {
                    cout << "Defense increased by 1!" << endl;
                    this->defense += 1;
                }
                
                if (rand() % 100 + 1 <= 50)
                {
                    cout << "Resist increased by 1!" << endl;
                    this->resist += 1;
                }
                
                if (rand() % 100 + 1 <= 65)
                {
                    cout << "Speed increased by 1!" << endl;
                    this->speed += 1;
                }
            }
            
            else if (this->job == "Mage")
            {
                if (rand() % 100 + 1 <= 80)
                {
                    cout << "Health increased by 2!" << endl;
                    this->current_health += 2;
                    this->max_health += 2;
                }
                
                if (rand() % 100 + 1 <= 70)
                {
                    cout << "Power increased by 1!" << endl;
                    this->power += 1;
                }
                
                if (rand() % 100 + 1 <= 55)
                {
                    cout << "Defense increased by 1!" << endl;
                    this->defense += 1;
                }
                
                if (rand() % 100 + 1 <= 70)
                {
                    cout << "Resist increased by 1!" << endl;
                    this->resist += 1;
                }
                
                if (rand() % 100 + 1 <= 75)
                {
                    cout << "Speed increased by 1!" << endl;
                    this->speed += 1;
                }
            }
            
            else if (this->job == "Berserker")
            {
                if (rand() % 100 + 1 <= 85)
                {
                    cout << "Health increased by 2!" << endl;
                    this->current_health += 2;
                    this->max_health += 2;
                }
                
                if (rand() % 100 + 1 <= 75)
                {
                    cout << "Power increased by 1!" << endl;
                    this->power += 1;
                }
                
                if (rand() % 100 + 1 <= 75)
                {
                    cout << "Defense increased by 1!" << endl;
                    this->defense += 1;
                }
                
                if (rand() % 100 + 1 <= 50)
                {
                    cout << "Resist increased by 1!" << endl;
                    this->resist += 1;
                }
                
                if (rand() % 100 + 1 <= 60)
                {
                    cout << "Speed increased by 1!" << endl;
                    this->speed += 1;
                }
            }
        }
};

// class of item
class Item
{
    private:
        string name;
        int effect;
        int stock;
    
    public:
        Item()
        {
            name = "";
            effect = 0;
            stock = 0;
        }
    
        Item(string name, int effect, int stock)
        {
            this->name = name;
            this->effect = effect;
            this->stock = stock;
        }
    
        string GetName()
        {
            return this->name;
        }
    
        int GetEffect()
        {
            return this->effect;
        }
    
        int GetStock()
        {
            return this->stock;
        }
    
        // get item stock
        void ReceiveItem()
        {
            this->stock += 1;
        }
    
        // minus the item stock, when it is used
        void UseItem()
        {
            this->stock -= 1;
        }
    
        void SeeAnItem()
        {
            cout << this->name << " | Effect: " << this->effect << " | Stock: " << this->stock << endl;
        }
};

// class of stage
class Stage
{
    private:
        string name;
        int chapter;
        int area;
        int round;
    
    public:
        Stage()
        {
            name = "Grass Valley";
            chapter = 1;
            area = 1;
            round = 1;
        }
    
        string GetName()
        {
            return this->name;
        }
    
        int GetChapter()
        {
            return this->chapter;
        }
    
        int GetArea()
        {
            return this->area;
        }
    
        int GetRound()
        {
            return this->round;
        }
    
        void ResetRound()
        {
            this->round = 1;
        }
    
        void NextRound()
        {
            this->round += 1;
        }
    
        // move to the next area, go to next chapter if 3 areas in a chapter had been cleared
        void MoveToNextArea()
        {
            if (area == 3)
            {
                this->chapter += 1;
                this->area = 1;
            }
            
            else
            {
                this->area += 1;
            }
            
            if (this->chapter == 2)
            {
                this->name = "Breezing Beach";
            }
        }
};

#endif
