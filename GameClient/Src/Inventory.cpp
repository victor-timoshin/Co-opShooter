#include "../Inc/Inventory.h"

/// <summary>Конструктор класса.</summary>
Inventory::Inventory(void)
{
}

/// <summary>Деструктор класса.</summary>
Inventory::~Inventory(void)
{
}

void Inventory::Add(InventoryItem* item)
{
	InventoryItem* existingItem = Find(item->GetType());
	if (existingItem)
		existingItem->IncreaseQuantity(item->GetQuantity());
	else
		_items.push_back(item);
}

void Inventory::Remove(Item::ITEM_TYPE type, int quantity)
{
	InventoryItem* item = Find(type);
	if (NOT item)
		return;

	if (item->GetQuantity() < quantity)
		return;

	if (item->GetQuantity() == quantity)
	{
		for (std::vector<InventoryItem*>::iterator iter = _items.begin(); iter < _items.end(); iter++)
		{
			if ((*iter)->GetType() == type)
			{
				_items.erase(iter);
				break;
			}
		}
	}
	else
		item->ReduceQuantity(quantity);
}

InventoryItem* Inventory::Find(Item::ITEM_TYPE type)
{
	for (UInt i = 0; i < _items.size(); i++)
	{
		if (_items.at(i)->GetType() == type)
			return _items.at(i);
	}
}

std::vector<InventoryItem*> Inventory::FindKeys(void)
{
	std::vector<InventoryItem*> keys;
	for (UInt i = 0; i < _items.size(); i++)
	{
		if (_items.at(i)->GetType() == Item::ITEM_TYPE::Key)
			keys.push_back(_items.at(i));
	}

	return keys;
}

std::vector<InventoryItem*> Inventory::GetItems(void)
{
	return _items;
}

bool Inventory::HasItem(Item::ITEM_TYPE type)
{
	return Find(type) != nullptr;
}

bool Inventory::HasKey(int doorID)
{
	//std::vector<InventoryItem*> keys = FindKeys();
	//for (UInt i = 0; i < keys.size(); i++)
	//{
	//	if (keys.at(i))->GetDoorId() == doorID)
	//		return true;
	//}

	return false;
}