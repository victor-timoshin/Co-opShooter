#include "../../Inc/Data/DataObject.h"

/// <summary>Конструктор класса.</summary>
DataObject::DataObject(void)
{
	_position = Math::Vec3F(VEC3F_ZERO);
}

/// <summary>Деструктор класса.</summary>
DataObject::~DataObject(void)
{
}

void DataObject::Load(void)
{

}

void DataObject::Save(void)
{

}

Math::Vec3F DataObject::GetPosition(void) const
{
	return _position;
}