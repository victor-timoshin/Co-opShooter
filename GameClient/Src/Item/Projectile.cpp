#include "../../Inc/Item/Projectile.h"

DEF_PROPERTY_FLOAT(Bullet, LifeTime, _lifeTime)
DEF_PROPERTY_FLOAT(Bullet, Speed, _speed)
DEF_PROPERTY_FLOAT(Bullet, Damage, _damage)

/// <summary>Конструктор класса.</summary>
Bullet::Bullet(void)
{
	SetLifeTime(0.6f);
	SetSpeed(100.0f);
	SetDamage(20.0f);
}

/// <summary>Деструктор класса.</summary>
Bullet::~Bullet(void)
{
}