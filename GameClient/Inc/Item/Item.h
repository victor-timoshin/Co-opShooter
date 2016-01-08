#ifndef ITEM_H
#define ITEM_H

#include "UsableObject.h"
#include "../StdAfx.h"

class Item : public UsableObject
{
public:

	typedef enum ArmorType
	{
		Chainmail, // Кольчуга.
		Boots,     // Сапоги.
		Gloves,    // Перчатки.
		Helmet,    // Шлем.
		Shield     // Щит.
	} ARMOR_TYPE;

	typedef enum ItemType
	{
		Common,   // Общий.
		Weapon,   // Оружие.
		Armor,    // Броня.
		Medicine, // Лекарственное средство.
		Book,     // Книга.
		Potion,   // Зелье.
		Scroll,   // Свиток.
		Key,      // Ключ.
		Other     // Другие.
	} ITEM_TYPE;

	typedef enum ItemTarget
	{
		Single,
		All
	} ITEM_TARGET;

	/// <summary>Конструктор класса.</summary>
	Item(std::string name, Controller::CharacterController* controller);

	/// <summary>Деструктор класса.</summary>
	virtual ~Item(void);

	void SetDisplayName(std::string displayName);
	std::string GetDisplayName(void) const;

	void SetDescription(std::string description);
	std::string GetDescription(void) const;

	void SetUsePrompt(std::string usePrompt);
	std::string GetUsePrompt(void) const;

	void SetPickupPrompt(std::string pickupPrompt);
	std::string GetPickupPrompt(void) const;

	//virtual float GetWeight(void) const; // Вес.

	//virtual bool CanSell(void) const; // Можно продать.

	//virtual bool HasToolTip(void) const;
	//virtual Gui::ToolTipInfo GetToolTipInfo(void) const;

	//virtual std::pair<std::vector<int>, bool> GetEquipmentSlots(void) const;
	//virtual int GetEquipmentSkill(void) const;

private:
	//Picture
	//Image* _displayThumbnail;
	std::string _displayName; // Наименование объекта.
	std::string _useDescription; // Краткое описание того, что делает этот объект.
	std::string _usePrompt; // Подсказка игроку, что это может быть использовано.
	std::string _pickupPrompt; // Подсказка игроку, что это может быть взято.

	ITEM_TYPE _type;
	float _price;

};

#endif // ITEM_H