#pragma once
class Weapon
{
private:
	float firerate = 0;
	int magazine = 0;
	int damage = 0;

public:
	Weapon();
	~Weapon();
	float Getfirerate(){ return firerate;}
	int Getmagazine(){ return magazine; }
	int Getdamage() { return damage; }
};

