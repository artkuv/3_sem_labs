#include"class.h"

//����������� �� ��������� 
mass::mass()
{
	size=0;
	ms=NULL;
}

//����������� � ���������� 
mass::mass(int n)
{
	this->size = n;
	this->ms = new int[n];
}

//���������� 
mass::~mass()
{
	delete[] ms;
}

//���� ������� � ���������� 
void mass::setmass()
{
	for (int i = 0; i < size; i++)
	{
		cin >> ms[i];
	}
}

//�������� ��������� ��������� � �������
mass mass::Repeating()
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j= i + 1; j < size; j++)
		{
			if (ms[i]==ms[j])
			{
				for (int k = j; k < size-1; k++)
				{
					ms[k] = ms[k + 1];
				}
				size--;
				j--;
			}
		}
	}
	return *this;
}

//����� ������� 
void mass::getmass()
{
	//cout << "Array: ";

	for (int i = 0; i < size; i++)
	{
		cout << ms[i] << " ";
	}
	cout << endl;
}

//����������� �����������	 														
mass::mass(const mass &obj)
{
	this->size = obj.size;
	ms = new int[size];

	for (int i = 0; i < size; i++)
	{
		ms[i] = obj.ms[i];
	}
	//this->ms = new_mass;
}

//������������� �������� ������������	 									
mass mass::operator = (const mass a)
{
	if (this == &a)
	{
		return *this;
	}

	delete[] this->ms;
	this->ms = new int[a.size];
	this->size = a.size;

	for (int i = 0; i < this->size; i++)
	{
		this->ms[i] = a.ms[i];
	}

	return *this;
}

//������������� �������� ����������� �������� 
mass mass::operator * (mass a)
{
	int temp_size = this->size;;

	mass temp(temp_size);

	int k = 0;
	temp.size = 0;

	for (int i = 0; i < temp_size; i++)
	{
		for (int j = 0; j < a.size; j++)
		{
			if (this->ms[i] == a.ms[j])
			{
				temp.size++;
				temp.ms[k] = a.ms[j];
				k++;
			}
		}
	}

	return temp;
}

//������������� �������� �������� �������� 
const mass mass::operator + (mass a)
{
	int j, k = 0;
	int temp_size = this->size + a.size;

	mass temp(temp_size);

	for(j = 0; j < this->size; j++)
		temp.ms[j] = this->ms[j];

	for(int i = j; i < (temp_size); i++)
	{
		temp.ms[i] = a.ms[k];
		k++;
	}

	return temp;
}

//������������� �������� ��������� �������� 
mass mass::operator > (mass a)
{
	int z = 0;
	z = this->size - a.size;
	if(z < 0) cout << "Array 2 bigger then array 1 for " << z*(-1) << " elements" << endl;
	else if(z == 0) cout << "Array 2 = Array 1" << endl;
		else cout << "Array 1 bigger then array 2 for " << z << " elements" << endl;
	return *this;
}

//������������� �������� ���������� ��������� ������� �� 1 
mass mass::operator ++ ()
{
	for(int i = 0; i < this->size; i++)
	{
		this->ms[i]++;
	}
	return *this;
}

//������������� �������� ���������� ��������� ������� �� 1 
mass mass::operator -- ()
{
	for(int i = 0; i < this->size; i++)
	{
		this->ms[i]--;
	}
	return *this;
}

//������������� �������� ���������� ��������� ������� �� 1 
mass mass::operator ++ (int x)
{
	for(int i = 0; i < this->size; i++)
	{
		this->ms[i]++;
	}
	return *this;
}

//������������� �������� ���������� ��������� ������� �� 1 
mass mass::operator -- (int x)
{
	for(int i = 0; i < this->size; i++)
	{
		this->ms[i]--;
	}
	return *this;
}