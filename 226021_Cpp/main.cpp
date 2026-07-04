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
template <class T>
class mang
{
public:
	T* memory;
	int lenght;

	mang(int len)
	{
		memory = (T*)calloc(len, sizeof(T));
		lenght = len;
	}

	T& operator[](int index)
	{
		return memory[index];
	}

	~mang()
	{
		free(memory);
	}
};



//int cong(int x, int y)
//{
//	cout << "ham cong int" << endl;
//	return x + y;
//}
//float cong(float x, float y)
//{
//	cout << "ham cong float" << endl;
//	return x + y;
//}
//double cong(double x, double y)
//{
//	cout << "ham cong double" << endl;
//	return x + y;
//}

template <typename kieu_du_lieu_mau>
kieu_du_lieu_mau cong(kieu_du_lieu_mau x, kieu_du_lieu_mau y)
{
	return x + y;
}



int main()
{

	mang<int> A(3);
	mang<phan_so> B(3);

	return 0;
}