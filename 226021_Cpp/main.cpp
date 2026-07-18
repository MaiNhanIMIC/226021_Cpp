#include <stdio.h>
#include <iostream>
#include "mang_co_dan.h"

using namespace std;

#include "class.h"

ostream& operator<<(ostream& os, hocsinh& A)
{
	os << "ten: " << A.ten << endl;
	os << "diem toan: " << A.diem_toan << endl;
	os << "diem van: " << A.diem_van << endl;
	os << "diem trung binh: " << A.diem_trung_binh() << endl;
	return os;
}


template<typename T, typename ham>
void sap_xep_mang(mang<T>& mang, ham ham_so_sanh)
{
	for (int i = 0; i < mang.so_luong_phan_tu - 1; i++)
	{
		for (int j = i; j < mang.so_luong_phan_tu; j++)
		{
			if (ham_so_sanh(mang[i], mang[j]))
			{
				auto temp = mang[i];
				mang[i] = mang[j];
				mang[j] = temp;
			}
		}
	}
}

#include <algorithm>
#include <vector>
int main()
{
	vector<hocsinh> A = {
		hocsinh("Nguyen Van A", 6,7),
		hocsinh("Nguyen Van B", 7,5),
		hocsinh("Nguyen Van C", 6,5),
		hocsinh("Nguyen Van D", 7,8),
		hocsinh("Nguyen Van E", 8,4)
	};
	sort(A.begin(), A.end(), [](hocsinh A, hocsinh B) {
		return (A.diem_trung_binh() < B.diem_trung_binh());
		});
	//sap_xep_mang(A, [](hocsinh A, hocsinh B) {
	//		return (A.diem_trung_binh() > B.diem_trung_binh());
	//	});

	for (auto hs : A)
	{
		cout << hs << endl;
	}

	return 0;
}