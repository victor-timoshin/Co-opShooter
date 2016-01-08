#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item/Item.h"
#include "StdAfx.h"

class InventoryItem
{
	DECL_PROPERTY_INLINE(Item::ITEM_TYPE, Type, _type)
	DECL_PROPERTY_INLINE(int, Quantity, _quantity)

public:
	/// <summary>Конструктор класса.</summary>
	InventoryItem(void) {}

	/// <summary>Деструктор класса.</summary>
	~InventoryItem(void) {}

	void IncreaseQuantity(int amount)
	{
		SetQuantity(_quantity + amount);
	}

	void ReduceQuantity(int amount)
	{
		SetQuantity(_quantity - amount);
	}
};

class Inventory
{
public:
	/// <summary>Конструктор класса.</summary>
	Inventory(void);

	/// <summary>Деструктор класса.</summary>
	~Inventory(void);

	void Add(InventoryItem* item);

	void Remove(Item::ITEM_TYPE, int quantity);

	InventoryItem* Find(Item::ITEM_TYPE itemType);

	std::vector<InventoryItem*> FindKeys(void);

	std::vector<InventoryItem*> GetItems(void);

	bool HasItem(Item::ITEM_TYPE itemType);

	bool HasKey(int doorID);

private:
	std::vector<InventoryItem*> _items;
};

#endif // INVENTORY_H