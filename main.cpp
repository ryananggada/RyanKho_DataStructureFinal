#include <iostream>
#include "class.h"
#include "function.h"

// this std is used to convert from integer to string, to created the unique ID for spawning an enemy or assigning weapons
using std::to_string;

// program called here
int main()
{
    // initialised these linked list
    WeaponList weapons;
    EnemyList enemies;
    
    // initalise the current enemy, enemy's weapon, player's weapon and items and stage
    Item items[3];
    Stage stage = Stage();
    CurrentWeapon current_weapon[3];
    CurrentEnemy current_enemy;
    CurrentWeapon enemy_weapon;
    
    // insert enemy data to the linked list
    enemies.CreateEnemy("A111N", "Slime", 15, 62, 2, 1, 3);
    enemies.CreateEnemy("A111H", "Slime", 20, 4, 2, 1, 4);
    enemies.CreateEnemy("A112N", "Living Bush", 17, 3, 1, 2, 5);
    enemies.CreateEnemy("A112H", "Living Bush", 24, 5, 1, 2, 6);
    enemies.CreateEnemy("A113N", "Crow", 20, 3, 2, 3, 6);
    enemies.CreateEnemy("A113H", "Crow", 25, 5, 3, 3, 8);
    enemies.CreateEnemy("A121N", "Bandit", 20, 3, 3, 2, 8);
    enemies.CreateEnemy("A121H", "Bandit", 25, 5, 3, 3, 10);
    enemies.CreateEnemy("A122N", "Mage Crow", 25, 3, 2, 4, 8);
    enemies.CreateEnemy("A122H", "Mage Crow", 30, 5, 3, 5, 11);
    enemies.CreateEnemy("A123N", "Cat Knight", 23, 4, 4, 2, 6);
    enemies.CreateEnemy("A123H", "Cat Knight", 28, 7, 5, 3, 8);
    enemies.CreateEnemy("A131N", "Cat Knight", 25, 5, 4, 2, 6);
    enemies.CreateEnemy("A131H", "Cat Knight", 30, 8, 5, 3, 8);
    enemies.CreateEnemy("A132N", "Cat Mage", 22, 4, 3, 5, 7);
    enemies.CreateEnemy("A132H", "Cat Mage", 25, 7, 3, 6, 10);
    enemies.CreateEnemy("A133N", "Cat Warrior", 30, 5, 5, 2, 5);
    enemies.CreateEnemy("A133H", "Cat Warrior", 35, 7, 6, 2, 8);
    
    enemies.CreateEnemy("A211N", "Squid", 25, 4, 3, 4, 7);
    enemies.CreateEnemy("A211H", "Squid", 30, 6, 3, 5, 9);
    enemies.CreateEnemy("A212N", "Crab", 24, 3, 5, 2, 5);
    enemies.CreateEnemy("A212H", "Crab", 28, 5, 5, 3, 7);
    enemies.CreateEnemy("A213N", "Yellow Jellyfish", 25, 4, 2, 4, 7);
    enemies.CreateEnemy("A213H", "Yellow Jellyfish", 28, 6, 2, 5, 10);
    enemies.CreateEnemy("A221N", "Yellow Jellyfish", 25, 4, 2, 4, 7);
    enemies.CreateEnemy("A221H", "Yellow Jellyfish", 28, 6, 2, 5, 10);
    enemies.CreateEnemy("A222N", "Blue Jellyfish", 25, 4, 2, 4, 7);
    enemies.CreateEnemy("A222H", "Blue Jellyfish", 28, 6, 2, 5, 10);
    enemies.CreateEnemy("A223N", "Red Jellyfish", 25, 4, 2, 4, 7);
    enemies.CreateEnemy("A223H", "Red Jellyfish", 28, 6, 2, 5, 10);
    enemies.CreateEnemy("A231N", "Shark", 28, 5, 4, 4, 10);
    enemies.CreateEnemy("A231H", "Shark", 33, 7, 5, 5, 14);
    enemies.CreateEnemy("A232N", "Octopus", 30, 4, 5, 3, 7);
    enemies.CreateEnemy("A232H", "Octopus", 35, 6, 6, 4, 10);
    enemies.CreateEnemy("A233N", "Kraken", 40, 5, 3, 2, 5);
    enemies.CreateEnemy("A233H", "Kraken", 45, 7, 3, 2, 7);
    
    // insert weapon data to the linked list
    weapons.CreateWeapon("P101", "Bronze Sword", "Physical", 4, 95, 3);
    weapons.CreateWeapon("P102", "Pocket Knife", "Physical", 3, 98, 5);
    weapons.CreateWeapon("P103", "Wood Dagger", "Magical", 3, 85, 5);
    weapons.CreateWeapon("P111", "Stone Sword", "Physical", 6, 90, 5);
    weapons.CreateWeapon("P112", "Short Sword", "Physical", 4, 90, 7);
    weapons.CreateWeapon("P113", "Flame Dagger", "Magical", 6, 80, 7);
    weapons.CreateWeapon("P121", "Iron Sword", "Physical", 8, 85, 5);
    weapons.CreateWeapon("P122", "Genin Katana", "Physical", 6, 80, 10);
    weapons.CreateWeapon("P123", "Thunder Dagger", "Magical", 8, 80, 7);
    
    weapons.CreateWeapon("P201", "Wind", "Magical", 2, 95, 0);
    weapons.CreateWeapon("P202", "Fire", "Magical", 3, 90, 3);
    weapons.CreateWeapon("P203", "Thunder", "Magical", 4, 85, 5);
    weapons.CreateWeapon("P211", "Elwind", "Magical", 4, 90, 3);
    weapons.CreateWeapon("P212", "Elfire", "Magical", 5, 85, 5);
    weapons.CreateWeapon("P213", "Elthunder", "Magical", 6, 80, 7);
    weapons.CreateWeapon("P221", "Arcwind", "Magical", 6, 85, 5);
    weapons.CreateWeapon("P222", "Arcfire", "Magical", 7, 80, 7);
    weapons.CreateWeapon("P223", "Arcthunder", "Magical", 8, 75, 10);
    
    weapons.CreateWeapon("P301", "Bronze Axe", "Physical", 4, 85, 3);
    weapons.CreateWeapon("P302", "Hand Axe", "Physical", 3, 85, 5);
    weapons.CreateWeapon("P303", "Glass Axe", "Magical", 3, 90, 3);
    weapons.CreateWeapon("P311", "Stone Axe", "Physical", 6, 80, 5);
    weapons.CreateWeapon("P312", "Short Axe", "Physical", 5, 80, 7);
    weapons.CreateWeapon("P313", "Nature Axe", "Magical", 5, 85, 5);
    weapons.CreateWeapon("P321", "Iron Axe", "Physical", 8, 75, 7);
    weapons.CreateWeapon("P322", "Tomahawk", "Physical", 7, 75, 10);
    weapons.CreateWeapon("P333", "Lightning Axe", "Magical", 7, 80, 5);
    
    weapons.CreateWeapon("E111N", "Tackle", "Physical", 3, 90, 5);
    weapons.CreateWeapon("E111H", "Pound", "Physical", 5, 85, 5);
    weapons.CreateWeapon("E112N", "Sweep", "Physical", 3, 95, 3);
    weapons.CreateWeapon("E112H", "Sweep+", "Physical", 5, 90, 5);
    weapons.CreateWeapon("E113N", "Peck", "Physical", 4, 85, 5);
    weapons.CreateWeapon("E113H", "Peck+", "Physical", 6, 80, 5);
    weapons.CreateWeapon("E121N", "Bronze Knife", "Physical", 4, 85, 5);
    weapons.CreateWeapon("E121H", "Stone Knife", "Physical", 6, 80, 7);
    weapons.CreateWeapon("E122N", "Thunder", "Magical", 4, 85, 5);
    weapons.CreateWeapon("E122H", "Elthunder", "Magical", 6, 80, 7);
    weapons.CreateWeapon("E123N", "Bronze Sword", "Physical", 4, 95, 3);
    weapons.CreateWeapon("E123H", "Stone Sword", "Physical", 6, 90, 5);
    weapons.CreateWeapon("E131N", "Bronze Sword", "Physical", 4, 95, 3);
    weapons.CreateWeapon("E131H", "Stone Sword", "Physical", 6, 90, 5);
    weapons.CreateWeapon("E132N", "Fire", "Magical", 3, 90, 3);
    weapons.CreateWeapon("E132H", "Elfire", "Magical", 5, 85, 5);
    weapons.CreateWeapon("E133N", "Stone Sword", "Physical", 6, 90, 5);
    weapons.CreateWeapon("E133H", "Iron Sword", "Physical", 8, 85, 7);
    
    weapons.CreateWeapon("E211N", "Spray", "Physical", 5, 95, 3);
    weapons.CreateWeapon("E211H", "Spray+", "Physical", 8, 90, 5);
    weapons.CreateWeapon("E212N", "Slap", "Physical", 5, 80, 7);
    weapons.CreateWeapon("E212H", "Slap+", "Physical", 8, 75, 10);
    weapons.CreateWeapon("E213N", "Elthunder", "Magical", 6, 80, 7);
    weapons.CreateWeapon("E213H", "Elthunder+", "Magical", 8, 80, 7);
    weapons.CreateWeapon("E221N", "Elthunder", "Magical", 6, 80, 7);
    weapons.CreateWeapon("E221H", "Elthunder+", "Magical", 8, 80, 7);
    weapons.CreateWeapon("E222N", "Elwind", "Magical", 4, 90, 3);
    weapons.CreateWeapon("E222H", "Elwind+", "Magical", 6, 90, 3);
    weapons.CreateWeapon("E223N", "Elfire", "Magical", 5, 85, 5);
    weapons.CreateWeapon("E223H", "Elfire+", "Magical", 7, 85, 5);
    weapons.CreateWeapon("E231N", "Bite", "Physical", 10, 45, 10);
    weapons.CreateWeapon("E231H", "Bite", "Physical", 10, 45, 10);
    weapons.CreateWeapon("E232N", "Strangle", "Physical", 5, 30, 50);
    weapons.CreateWeapon("E232H", "Strangle", "Physical", 5, 30, 50);
    weapons.CreateWeapon("E233N", "Charge", "Physical", 6, 75, 5);
    weapons.CreateWeapon("E233H", "Charge+", "Physical", 8, 75, 5);
    
    // create player's items
    items[0] = Item("Onigiri", 10, 2);
    items[1] = Item("Bento", 25, 1);
    items[2] = Item("Pizza", 99, 1);
    
    // choose difficulty
    string diff = DiffPick();
    Player player;
    
    // initialise the unique ID
    string enemyid, enemyweaponid, playerweaponid;
    
    string name = InputName();
    player = ChooseJob(name);
    
    int jobnum = JobNumber(player);
    
    // assign player weapons
    for (int i = 0; i < 3; i++)
    {
        playerweaponid = string("P") + to_string(jobnum) + "0" + to_string(i+1);
        current_weapon[i] = weapons.AssignWeapon(playerweaponid);
    }
    
    bool alive = true;
    
    int choice;
    
    while (alive)
    {
        cout << endl << "What to do?" << endl;
        cout << "Current Location: " << stage.GetName() << ", Chapter: " << stage.GetChapter() << " - " << stage.GetArea() << endl;
        cout << "[1] Start battle" << endl;
        cout << "[2] View your inventory" << endl;
        cout << "[3] View your stats" << endl;
        cout << ">> ";
        cin >> choice;
        cout << endl;
        
        // battle phase
        if (choice == 1)
        {
            cout << "Start battle!" << endl;
            
            bool battlerun = true;
            
            while (battlerun)
            {
                int chapter = stage.GetChapter();
                int area = stage.GetArea();
                int round = stage.GetRound();

                enemyid = string("A") + to_string(chapter) + to_string(area) + to_string(round) + diff;
                enemyweaponid = string("E") + to_string(chapter) + to_string(area) + to_string(round) + diff;
                current_enemy = enemies.SpawnEnemy(enemyid);
                enemy_weapon = weapons.AssignWeapon(enemyweaponid);
            
                Battle(player, current_enemy, current_weapon, enemy_weapon, items);
                stage.NextRound();
                
                // if player's health is zero
                if (player.GetCurrentHealth() <= 0)
                {
                    cout << endl << "You are dead!" << endl;
                    cout << "GAME OVER!" << endl;
                    battlerun = false;
                    alive = false;
                }
                
                // battle phase ended after 3 rounds are cleared (3 enemies are killed)
                if (stage.GetRound() == 4)
                {
                    battlerun = false;
                    cout << endl << "You completed this area, GREAT!" << endl;
                    
                    player.LevelUp();
                    cout << endl;
                    
                    playerweaponid = string("P") + to_string(jobnum) + to_string(chapter) + to_string(area);
                    current_weapon[area-1] = weapons.AssignWeapon(playerweaponid);
                    cout << "You got a " << current_weapon[area-1].GetName() << " for completing the area!" << endl;
                    
                    items[area-1].ReceiveItem();
                    cout << "Plus, you receive a " << items[area-1].GetName() << "!" << endl;
                    
                    stage.MoveToNextArea();
                    stage.ResetRound();
                    player.ResetHealth();
                }
                
                // end game
                if (stage.GetChapter() == 3)
                {
                    cout << endl << "Thank you for playing our game! Sorry, if it is too short for you :)" << endl;
                    alive = false;
                }
            }
        }
        
        // view your weapon and item inventory
        else if (choice == 2)
        {
            cout << "Your weapons" << endl;
            
            for (int i = 0; i < 3; i++)
            {
                cout << "[" << i+1 << "] ";
                current_weapon[i].SeeAWeapon();
            }
            
            cout << endl << "Your items" << endl;
            
            for (int j = 0; j < 3; j++)
            {
                cout << "[" << j+1 << "] ";
                items[j].SeeAnItem();
            }
        }
        
        // see the player's stats
        else if (choice == 3)
        {
            player.ViewPlayerStats();
        }
        
        else
        {
            cout << "Please input again!" << endl;
        }
    }
    
    return 0;
}
