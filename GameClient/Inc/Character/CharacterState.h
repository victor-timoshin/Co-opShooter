#ifndef CHARACTERSTATE_H
#define CHARACTERSTATE_H

namespace Character
{
	typedef enum CharacterState
	{
		None        = 0x3470, // Неопределенное состояние.
		Idle        = 0x085D, // Стоять.
		WalkForward = 0x3E44, // Ходить вперед.
		WalkBack    = 0x6678, // Ходить назад.
		WalkLeft    = 0x0D78, // Ходить налево.
		WalkRight   = 0xACCB, // Ходить вправо.
		RunForward  = 0x0C0D, // Бежать вперед.
		RunBack     = 0xDFA1, // Бежать назад.
		RunLeft     = 0x9901, // Бежать налево.
		RunRight    = 0x8CF4, // Бежать вправо.
		TurnLeft    = 0xA06D, // Поворот налево.
		TurnRight   = 0x20F4, // Поворот вправо.
		Jump        = 0x9F35, // Прыгать.
		Hit         = 0x886A, // Нанести удар.
		Block       = 0x5416, // Блок.
		Death       = 0x0C74
	} CHARACTER_STATE;

	typedef enum JumpState
	{
		InAir   = 0x518B,
		Landing = 0x1EB6
	} JUMP_STATE;
}

#endif // CHARACTERSTATE_H