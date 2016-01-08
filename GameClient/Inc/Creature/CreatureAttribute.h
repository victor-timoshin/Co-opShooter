#ifndef CREATUREATTRIBUTE_H
#define CREATUREATTRIBUTE_H

namespace Creature
{
	typedef struct CreatureAttribute
	{
		int Strength;     // Сила.
		int Vitality;     // Живучесть.
		int Dexterity;    // Ловкость.
		int Intelligence; // Интеллект.
		int Charisma;     // Харизма.
		int Perception;   // Восприятие.
	} LCREATURE_ATTRIBUTE, *PCREATURE_ATTRIBUTE;
}

#endif // CREATUREATTRIBUTE_H