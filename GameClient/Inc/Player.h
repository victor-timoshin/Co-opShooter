#ifndef PLAYER_H
#define PLAYER_H

#include "Character/Character.h"
#include "StdAfx.h"

#define MAX_CHARACTER_COUNT 4 // Максимальное количество персонажей у игрока.

class Player
{
	DECL_PROPERTY_INT(Id, _id) // Уникальный идентификатор.
	DECL_PROPERTY_STRING(Name, _name) // Имя игрока.
	DECL_PROPERTY_INT(Score, _score) // Счет игрока.

public:
	/// <summary>Конструктор класса.</summary>
	Player(void);

	/// <summary>Деструктор класса.</summary>
	~Player(void);

private:
	typedef std::vector<Character::CharacterBase*> CharacterList;
	CharacterList _characters;
};

#endif // PLAYER_H