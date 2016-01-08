#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include "../StdAfx.h"

class DataObject
{
public:
	/// <summary>Конструктор класса.</summary>
	DataObject(void);

	/// <summary>Деструктор класса.</summary>
	~DataObject(void);

	void Load(void);

	void Save(void);

	Math::Vec3F GetPosition(void) const;

private:
	Math::Vec3F _position;
};

#endif // DATAOBJECT_H