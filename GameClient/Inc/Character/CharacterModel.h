#ifndef CHARACTERMODEL_H
#define CHARACTERMODEL_H

#include "../Creature/CreatureAttribute.h"

#include "../StdAfx.h"

class CharacterModel
{
	DECL_PROPERTY_INT(BaseDamage, _baseDamage) // Базовый урон.
	DECL_PROPERTY_INT(BaseAttackSpeed, _baseAttackSpeed) // Базовая скорость атаки.
	DECL_PROPERTY_INT(BaseHealth, _baseHealth) // Базовый запас здоровья.
	DECL_PROPERTY_INT(BaseMana, _baseMana) // Базовый запас маны.
	DECL_PROPERTY_INT(BaseEnergy, _baseEnergy) // Базовый запас энергии.

public:
	/// <summary>Конструктор класса.</summary>
	CharacterModel(void);

	/// <summary>Деструктор класса.</summary>
	~CharacterModel(void);

	void SetHealth(int health);

	/// <summary>Получает текущий запас здоровья.</summary>
	int GetHealth(void) const;

	/// <summary>Получает текущий запас здоровья в процентах.</summary>
	float GetHealthPercentage(void) const;

	void SetHealthMax(int healthMax);

	/// <summary>Получает максимальный запас здоровья.</summary>
	int GetHealthMax(void) const;

	void SetHealthRegenerationRate(float regenerationRate);

	/// <summary>Получает текущий запас энергии.</summary>
	int GetEnergy(void) const;

	/// <summary>Получает максимальный запас энергии.</summary>
	int GetEnergyMax(void) const;

	void SetExperience(int experience);

	int GetExperience(void) const;

protected:
	std::string GetRandomName(std::vector<std::string> names)
	{
		return names[Math::RandRangeI(0, names.size() - 1)];
	}

private:
	//Creature::LCREATURE_DEMOGRAPHIC _demographics;
	Creature::LCREATURE_ATTRIBUTE _attributes;

	int _health; // Запас здоровья.
	int _healthMax; // Максимальный запас здоровья.
	float _healthRegenerationRate; // Скорость регенерации здоровья.
	float _healthRegenerationDelay; // Задержка регенерации здоровья.
	float _healthAccumulation;
	bool _healthRegenerationEnabled;
	bool _unlimitedHealth; // Неограниченный запас здоровья.

	int _mana; // Запас маны.
	int _manaMax; // Максимальный запас маны.
	float _manaRegenerationRate;
	float _manaRegenerationDelay;
	float _manaAccumulation;
	bool _manaRegenerationEnabled;
	bool _unlimitedMana; // Неограниченный запас маны.

	int _energy; // Запас энергии.
	int _energyMax; // Максимальный запас энергии.
	float _energyRegenerationRate; // Скорость регенерации энергии.
	float _energyRegenerationDelay; // Задержка регенерации энергии.
	bool _energyRegenerationEnabled;
	bool _unlimitedEnergy; // Неограниченный запас энергии.

	int _experience; // Опыт.

	Math::Vec3F _position;
	Math::Vec3F _direction;

	std::vector<std::string> _maleNames;
	std::vector<std::string> _femaleNames;
};

#endif // CHARACTERMODEL_H