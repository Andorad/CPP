#include "WaveManager.h"

WaveManager::WaveManager()
{

};

//On instancie tous les ennemies de la vague
void WaveManager::InstantiateWaves(std::vector<Character*>& enemyList, int x, int y, int enemiesToSpawn)
{
    for (int i = 0; i < enemiesToSpawn; i++)
    {
        BasicEnemy* b = new BasicEnemy();
        enemyList.push_back(b);
        b->Spawn(x, y);
    }
}