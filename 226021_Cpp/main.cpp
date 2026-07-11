#include <stdio.h>
#include <iostream>

using namespace std;

// xây dựng struct để miêu tả đối tượng là hình chữ nhật
//	+ chiều dài
//	+ chiều rộng
struct hinh_chu_nhat_s
{
	int dai;
	int rong;
};

class hinh_chu_nhat_c
{
public:
	// bien: - mieu ta dac diem doi tuong
	int dai;
	int rong;
	// ham: - mieu ta hanh dong/hanh vi cua doi tuong
	int tinh_dien_tich()
	{
		return dai * rong;
	}
	int tinh_chu_vi()
	{
		return (dai + rong) * 2;
	}
};


class phan_so
{
public:
	// dac diem cua doi tuong
	int tu;
	int mau;

	// hanh vi/hanh dong
	phan_so nhan_phan_so_khac(phan_so khac)
	{
		phan_so ketqua;
		ketqua.tu = tu * khac.tu;
		ketqua.mau = mau * khac.mau;
		return ketqua;
	}


	phan_so operator*(phan_so khac)
	{
		phan_so ketqua;
		ketqua.tu = tu * khac.tu;
		ketqua.mau = mau * khac.mau;
		return ketqua;
	}

	// hàm tạo: tự động được gọi khi đối tướng được tạo ra
	//		+ tên: trùng với tên class
	//		+ input: có thể có 0,1,2,3... input
	//		+ output: không có output
	phan_so()
	{
		cout << "Ham tao 0 input" << endl;
		tu = 0;
		mau = 0;
	}

	phan_so(int _tu, int _mau)
	{
		cout << "Ham tao 2 input" << endl;
		tu = _tu;
		mau = _mau;
	}

	// hàm hủy: Tự động được gọi khi đối tượng bị hủy (bị giải phòng vùng nhớ)
	//		+ tên: trùng với tên class và thêm ~ ở phía trước
	//		+ input: không có
	//		+ output: không có
	~phan_so()
	{
		cout << "doi da giai phong vung nho" << endl;
	}
};

#include <malloc.h>
#include <initializer_list>

template <class T>
class mang
{
public:
	T* vung_nho;
	int so_luong_phan_tu;

	mang(int len)
	{
		vung_nho = (T*)calloc(len, sizeof(T));
		if (vung_nho == NULL)
		{
			throw("cap phat memory that bai");
		}
		so_luong_phan_tu = len;
	}

	mang(initializer_list<T> init_list)
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
	
	// thêm phần tử vào cuối mãng
	void them_phan_tu_cuoi_mang(T gia_tri_phan_tu)
	{
		// cấp phát vùng nhớ mới lớn hơn vùng nhớ củ 1 phần tử
		T* vung_nho_moi = (T*)calloc(so_luong_phan_tu + 1, sizeof(T));

		// copy dữ liệu từ vùng nhớ củ vào vùng nhớ mới
		for (int i = 0; i < so_luong_phan_tu; i++)
		{
			vung_nho_moi[i] = vung_nho[i];
		}

		// set giá trị cho phần tử cuối mãng
		vung_nho_moi[so_luong_phan_tu] = gia_tri_phan_tu;

		// giải phóng vùng nhớ củ
		free(vung_nho);

		// cập nhật vùng nhớ mới vào `vung_nho` và `so_luong_phan_tu`
		vung_nho = vung_nho_moi;
		so_luong_phan_tu++;
	}
	// insert phần tử vào vị trí bất kỳ của mãng
	void chen_phan_tu_vao_mang(int vi_tri, T gia_tri_pha_tu)
	{
		// cấp phát vùng nhớ mới lớn hơn vùng nhớ củ 1 phần tử
		T* vung_nho_moi = (T*)calloc(so_luong_phan_tu + 1, sizeof(T));

		// copy dữ liệu từ vùng nhớ củ vào vùng nhớ mới
		for (int i = 0; i < vi_tri; i++)
		{
			vung_nho_moi[i] = vung_nho[i];
		}
		vung_nho_moi[vi_tri] = gia_tri_pha_tu;
		for (int i = vi_tri; i < so_luong_phan_tu; i++)
		{
			vung_nho_moi[i + 1] = vung_nho[i];
		}
		// giải phóng vùng nhớ củ
		free(vung_nho);
		// cập nhật vùng nhớ mới vào `vung_nho` và `so_luong_phan_tu`
		vung_nho = vung_nho_moi;
		so_luong_phan_tu++;
	}
	

	T& operator[](int index)
	{
		return vung_nho[index];
	}

	~mang()
	{
		free(vung_nho);
	}
};

ostream& operator<<(ostream& os, mang<int>& arr)
{
	os << "{ ";
	for (int i = 0; i < arr.so_luong_phan_tu; i++)
	{
		os << arr[i] << " ";
	}
	os << "}";
	return os;
}

#include <array>
#include <vector>
int main()
{
	mang<int> arr = { 1,2,3,4,5 };

	cout << "Mang: " << arr << endl;
	arr.chen_phan_tu_vao_mang(2, 6);
	cout << "Mang: " << arr << endl;
	return 0;
}