#include "../../Inc/Character/Character.h"

namespace Character
{
	/// <summary>Конструктор класса.</summary>
	CharacterBase::CharacterBase(void)
	{
		SetType(Creature::CREATURE_TYPE::Player);
	}

	/// <summary>Деструктор класса.</summary>
	CharacterBase::~CharacterBase(void)
	{
	}
}