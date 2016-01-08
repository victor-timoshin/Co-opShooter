#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include "StdAfx.h"

class PlayerInput
{
public:
	//static int const NUM_WEAPON_SLOT = 4;

	/// <summary>Конструктор класса.</summary>
	PlayerInput(void);

	/// <summary>Деструктор класса.</summary>
	~PlayerInput(void);

	void Spawn(void);

	//void TakeDamage(Bullet* bullet);

	//void AddWeapon(Weapon* weapon);

	//void ClearWeapons(void);

private:
	//Weapon* _weaponSlot[NUM_WEAPON_SLOT];

	float _verticalSensitivity;
	float _horizontalSensitivity;
};

#endif // PLAYERINPUT_H