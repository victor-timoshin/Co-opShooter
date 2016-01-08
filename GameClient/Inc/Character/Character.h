#ifndef CHARACTER_H
#define CHARACTER_H

#include "../Creature/Creature.h"

namespace Character
{
	class CharacterBase : public Creature::CreatureBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		CharacterBase(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~CharacterBase(void);
	};
}

#endif // CHARACTER_H