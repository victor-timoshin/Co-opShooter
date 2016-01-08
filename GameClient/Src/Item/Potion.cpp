#include "../../Inc/Item/Potion.h"

/// <summary>Конструктор класса.</summary>
Potion::Potion(std::string name, Controller::CharacterController* controller) : Item(name, controller)
{
}

/// <summary>Деструктор класса.</summary>
Potion::~Potion(void)
{
}