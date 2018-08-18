#pragma once
#include "exeption.h"

class Input : public Exeption
{
public:
	Input(int i, char *name) : Exeption(i, name)
	{
	}
};