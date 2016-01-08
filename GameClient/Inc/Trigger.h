#ifndef TRIGGER_H
#define TRIGGER_H

#include "StdAfx.h"

namespace Logic
{
	class TriggerEvent
	{
	public:
		/// <summary>Конструктор класса.</summary>
		TriggerEvent(void);

		/// <summary>Деструктор класса.</summary>
		~TriggerEvent(void);
	};

	class Trigger
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Trigger(void);

		/// <summary>Деструктор класса.</summary>
		~Trigger(void);

	private:
		bool _enable;
	};

	class AreaTrigger : public Trigger
	{
	public:
		/// <summary>Конструктор класса.</summary>
		AreaTrigger(void);

		/// <summary>Деструктор класса.</summary>
		~AreaTrigger(void);
	};
}

#endif // TRIGGER_H