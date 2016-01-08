#ifndef WEAPON_H
#define WEAPON_H

#include "Projectile.h"
#include "../StdAfx.h"

typedef struct WeaponInfo
{
	int Icon;
	int Model;
} WEAPON_INFO;

class Crosshair
{

};

class Weapon
{
	DECL_PROPERTY_FLOAT(RechargeTime, _rechargeTime) // Время перезарядки.

public:
	/// <summary>Конструктор класса.</summary>
	Weapon(void);

	/// <summary>Деструктор класса.</summary>
	~Weapon(void);

	void ChangeWeapon(void);

	void Drop(void);

	void Crosshair(void);

	void OnFireBullet(Bullet* bullet);

	void Fire(const Math::Vec3F& position, const Math::Vec3F& direction);

	//virtual std::string GetName(void) const;

private:
	Scene::ISceneGraphBase* _sceneGraph;
	Scene::ICameraBase* _camera;

	std::vector<Bullet*> _bullets;
};

class MeleeWeaponController : public Weapon
{
public:
	/// <summary>Конструктор класса.</summary>
	MeleeWeaponController(void) {}

	/// <summary>Деструктор класса.</summary>
	~MeleeWeaponController(void) {}
};

class ProjectileWeaponController : public Weapon
{
public:
	/// <summary>Конструктор класса.</summary>
	ProjectileWeaponController(void) {}

	/// <summary>Деструктор класса.</summary>
	~ProjectileWeaponController(void) {}
};

#endif // WEAPON_H