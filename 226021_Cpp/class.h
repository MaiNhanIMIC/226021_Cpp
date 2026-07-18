#pragma once


class hocsinh
{
public:
	char* ten;
	float diem_toan;
	float diem_van;

	float diem_trung_binh();
	hocsinh();
	hocsinh(const char* _ten, float _diem_toan, float _diem_van);
};