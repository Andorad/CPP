#pragma once
#include "Weapon.h"

class Pistol : public Weapon
{
private:
	float firerate = 3;
	int magazine = 7;
	int damage = 1;
public:
	Pistol();
	~Pistol();

};

