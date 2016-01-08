#include "../../Inc/Creature/Creature.h"

namespace Creature
{
	static const std::string maleNames[] = { "Tom", "John", "Bill", "Allan", "Patrik", "Frank", "Mike" };
	static const std::string femaleNames[] = { "Monika", "Maria", "Julia", "Alice", "Margret", "Diana", "Jane" };

	DEF_PROPERTY_STRING(CreatureBase, Name, _name)
	DEF_PROPERTY_STRING(CreatureBase, Description, _description)
	DEF_PROPERTY(CreatureBase, CREATURE_TYPE, Type, _type)
	DEF_PROPERTY(CreatureBase, CREATURE_GENDER, Gender, _gender)
	DEF_PROPERTY(CreatureBase, CREATURE_RACE, Race, _race)

	/// <summary>Конструктор класса.</summary>
	CreatureBase::CreatureBase(void)
	{
	}

	/// <summary>Деструктор класса.</summary>
	CreatureBase::~CreatureBase(void)
	{
	}

	/// <summary>Генерирует полное имя существа.</summary>
	std::string CreatureBase::GetRandomName(void) const
	{
		return (GetGender() == CREATURE_GENDER::Male) ? maleNames[Math::RandRangeI(0, sizeof(maleNames) - 1)] : femaleNames[Math::RandRangeI(0, sizeof(femaleNames) - 1)];
	}
}