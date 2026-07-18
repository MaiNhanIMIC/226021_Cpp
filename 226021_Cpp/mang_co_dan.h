#pragma once
#include <initializer_list>
using namespace std;

template <class T>
class mang
{
public:
	T* vung_nho;
	int so_luong_phan_tu;
	mang(int len);
	mang(initializer_list<T> init_list);
	T& operator[](int index);
	T* begin();
	T* end();
	//~mang();
};

template <typename T>
T* mang<T>::begin()
{
	return &vung_nho[0];
}

template <typename T>
T* mang<T>::end()
{
	return &vung_nho[so_luong_phan_tu - 1];
}

template<typename T>
mang<T>::mang(int len)
{
	vung_nho = (T*)calloc(len, sizeof(T));
	if (vung_nho == NULL)
	{
		throw("cap phat memory that bai");
	}
	so_luong_phan_tu = len;
}

template<typename T>
mang<T>::mang(initializer_list<T> init_list)
{
	vung_nho = (T*)calloc(init_list.size(), sizeof(T));
	if (vung_nho == NULL)
	{
		throw("cap phat memory that bai");
	}
	int index = 0;
	for (T phan_tu_trong_init_list : init_list)
	{
		vung_nho[index++] = phan_tu_trong_init_list;
	}
	so_luong_phan_tu = init_list.size();
}

template<typename T>
T& mang<T>::operator[](int index)
{
	return vung_nho[index];
}