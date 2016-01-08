#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include "CharacterModel.h"
#include "../StdAfx.h"

class CharacterView
{
public:
	/// <summary>Конструктор класса.</summary>
	CharacterView(void);

	/// <summary>Деструктор класса.</summary>
	~CharacterView(void);

private:
	CharacterModel* _model;
};

#endif // CHARACTERVIEW_H