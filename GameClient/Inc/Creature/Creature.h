#ifndef CREATURE_H
#define CREATURE_H

#include "CreatureType.h"
#include "CreatureGender.h"
#include "CreatureRace.h"
#include "../StdAfx.h"

namespace Creature
{
	class CreatureBase
	{
		DECL_PROPERTY_VIRTUAL_STRING(Name, _name) // Имя существа.
		DECL_PROPERTY_VIRTUAL_STRING(Description, _description) // Описание.
		DECL_PROPERTY_VIRTUAL(CREATURE_TYPE, Type, _type) // Тип.
		DECL_PROPERTY_VIRTUAL(CREATURE_GENDER, Gender, _gender) // Пол.
		DECL_PROPERTY_VIRTUAL(CREATURE_RACE, Race, _race) // Раса.

	public:
		/// <summary>Конструктор класса.</summary>
		CreatureBase(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~CreatureBase(void);

	protected:
		/// <summary>Генерирует полное имя существа.</summary>
		std::string GetRandomName(void) const;

	private:
		//CharacterModel _model;
		//CharacterView _view;
		//CharacterState _state;
	};
}

#endif // CREATURE_H