#include <iostream>
using namespace std;

#include "class.h"

float hocsinh::diem_trung_binh()
{
	return (diem_toan + diem_van) / 2;
}

hocsinh::hocsinh()
{
	ten = nullptr;
	diem_toan = 0;
	diem_van = 0;
}

hocsinh::hocsinh(const char* _ten, float _diem_toan, float _diem_van)
{
	ten = (char*)_ten;
	diem_toan = _diem_toan;
	diem_van = _diem_van;
}

