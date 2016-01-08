#include "../../Inc/Creature/CreatureModel.h"

namespace Creature
{
	DEF_PROPERTY_INT(CreatureModel, BaseDamage, _baseDamage)
	DEF_PROPERTY_INT(CreatureModel, BaseAttackSpeed, _baseAttackSpeed)
	DEF_PROPERTY_INT(CreatureModel, BaseHealth, _baseHealth)
	DEF_PROPERTY_INT(CreatureModel, BaseMana, _baseMana)
	DEF_PROPERTY_INT(CreatureModel, BaseEnergy, _baseEnergy)

	/// <summary>Конструктор класса.</summary>
	CreatureModel::CreatureModel(void)
	{
		_attributes.Strength = 14;
		_attributes.Vitality = 12;
		_attributes.Dexterity = 12;
		_attributes.Intelligence = 10;
		_attributes.Charisma = 8;
		_attributes.Perception = 8;

		_baseDamage = 20;
		_baseAttackSpeed = 400;
		_baseHealth = 200;
		_baseMana = 30;
		_baseEnergy = 600;

		_health = 200;
		_healthMax = 200;
		_healthRegenerationRate = 1.5f;
		_healthRegenerationDelay = 3.0f;
		_healthAccumulation = 0.0f;
		_healthRegenerationEnabled = true;
		_unlimitedHealth = false;

		_mana = 100;
		_manaMax = 100;
		_manaRegenerationRate = 1.5;
		_manaRegenerationDelay = 3.0f;
		_manaAccumulation = 0.0f;
		_manaRegenerationEnabled = true;
		_unlimitedMana = false;

		_energy = 600;
		_energyMax = 600;
		_energyRegenerationRate = 20.0f;
		_energyRegenerationDelay = 5.0f;
		_energyRegenerationEnabled = true;
		_unlimitedEnergy = false;

		_experience = 0;
	}

	/// <summary>Деструктор класса.</summary>
	CreatureModel::~CreatureModel(void)
	{
	}

	void CreatureModel::SetHealth(int health)
	{
		_health = health;
		_health = Math::MinI(_health, _healthMax);
		_health = Math::MaxI(_health, 0);
	}

	/// <summary>Получает текущий запас здоровья.</summary>
	int CreatureModel::GetHealth(void) const
	{
		return _health;
	}

	float CreatureModel::GetHealthPercentage() const
	{
		return static_cast<float>(GetHealth()) / static_cast<float>(GetHealthMax());
	}

	void CreatureModel::SetHealthMax(int healthMax)
	{
		_healthMax = healthMax;
		_health = Math::MinI(_health, _healthMax);
	}

	/// <summary>Получает максимальный запас здоровья.</summary>
	int CreatureModel::GetHealthMax(void) const
	{
		return _healthMax;
	}

	void CreatureModel::SetHealthRegenerationRate(float regenerationRate)
	{
		_healthRegenerationRate = regenerationRate;
	}

	/// <summary>Получает текущий запас энергии.</summary>
	int CreatureModel::GetEnergy(void) const
	{
		return _energy;
	}

	/// <summary>Получает максимальный запас энергии.</summary>
	int CreatureModel::GetEnergyMax(void) const
	{
		return _energyMax;
	}

	void CreatureModel::SetExperience(int experience)
	{
		_experience = experience;
	}

	int CreatureModel::GetExperience(void) const
	{
		return _experience;
	}
}