#include "../Inc/Player.h"

DEF_PROPERTY_INT(Player, Id, _id)
DEF_PROPERTY_STRING(Player, Name, _name)
DEF_PROPERTY_INT(Player, Score, _score)

/// <summary>Конструктор класса.</summary>
Player::Player(void)
{
	SetId(0);
	SetName("undefined");
	SetScore(0);
}

/// <summary>Деструктор класса.</summary>
Player::~Player(void)
{
}