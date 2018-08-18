#include "exeption.h"

class Input : public exeption
{
public:
	Input(int i, char *name) : exeption(i, name)
	{
	}
};