#ifndef BULLET_H
#define BULLET_H

#include "../StdAfx.h"

class Bullet
{
	DECL_PROPERTY_FLOAT(LifeTime, _lifeTime) // Время жизни.
	DECL_PROPERTY_FLOAT(Speed, _speed) // Скорость.
	DECL_PROPERTY_FLOAT(Damage, _damage) // Урон.

public:
	/// <summary>Конструктор класса.</summary>
	Bullet(void);

	/// <summary>Деструктор класса.</summary>
	~Bullet(void);
};

#endif // BULLET_H