#include "../../Inc/Character/CharacterModel.h"

DEF_PROPERTY_INT(CharacterModel, BaseDamage, _baseDamage)
DEF_PROPERTY_INT(CharacterModel, BaseAttackSpeed, _baseAttackSpeed)
DEF_PROPERTY_INT(CharacterModel, BaseHealth, _baseHealth)
DEF_PROPERTY_INT(CharacterModel, BaseMana, _baseMana)
DEF_PROPERTY_INT(CharacterModel, BaseEnergy, _baseEnergy)

/// <summary>Конструктор класса.</summary>
CharacterModel::CharacterModel(void)
{
	//_demographics.Firstname = "";
	//_demographics.Lastname = "";
	//_demographics.Gender = Creature::GENDER_TYPE::Male;

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

	static const std::string maleNames[] = {
		"Tom", "John", "Bill", "Allan", "Patrik", "Frank", "Mike"
	};

	
	maleNames[Math::RandRangeI(0, sizeof(maleNames) - 1)];

	_maleNames.push_back("Tom");
	_maleNames.push_back("John");
	_maleNames.push_back("Bill");
	_maleNames.push_back("Allan");
	_maleNames.push_back("Patrik");
	_maleNames.push_back("Frank");
	_maleNames.push_back("Mike");

	_femaleNames.push_back("Monika");
	_femaleNames.push_back("Maria");
	_femaleNames.push_back("Julia");
	_femaleNames.push_back("Alice");
	_femaleNames.push_back("Margret");
	_femaleNames.push_back("Diana");
	_femaleNames.push_back("Jane");
}

/// <summary>Деструктор класса.</summary>
CharacterModel::~CharacterModel(void)
{
}

void CharacterModel::SetHealth(int health)
{
	_health = health;
	_health = Math::MinI(_health, _healthMax);
	_health = Math::MaxI(_health, 0);
}

/// <summary>Получает текущий запас здоровья.</summary>
int CharacterModel::GetHealth(void) const
{
	return _health;
}

float CharacterModel::GetHealthPercentage() const
{
	return static_cast<float>(GetHealth()) / static_cast<float>(GetHealthMax());
}

void CharacterModel::SetHealthMax(int healthMax)
{
	_healthMax = healthMax;
	_health = Math::MinI(_health, _healthMax);
}

/// <summary>Получает максимальный запас здоровья.</summary>
int CharacterModel::GetHealthMax(void) const
{
	return _healthMax;
}

void CharacterModel::SetHealthRegenerationRate(float regenerationRate)
{
	_healthRegenerationRate = regenerationRate;
}

/// <summary>Получает текущий запас энергии.</summary>
int CharacterModel::GetEnergy(void) const
{
	return _energy;
}

/// <summary>Получает максимальный запас энергии.</summary>
int CharacterModel::GetEnergyMax(void) const
{
	return _energyMax;
}

void CharacterModel::SetExperience(int experience)
{
	_experience = experience;
}

int CharacterModel::GetExperience(void) const
{
	return _experience;
}