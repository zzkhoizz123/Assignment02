#include"HAM_PHU.h"


void NhapMatKhau(char *a){
	char ch;
	int dem = 0;

	cout << "Nhap vao mat khau." << endl;
	while ((ch = _getch()) != 13) {
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9')) {
			cout << "*";
			a[dem++] = ch;
		}
		else
			if (ch == 8)
				if (dem>0) {
					cout << "\b \b";
					dem--;
				}
	}

}


void DangkyMatKhau(DanhSachDocGia &DanhSach) {
	DanhSach.n += 1;
	Menu:
	char a1[21] = "\0", a2[21] = "\0";
	char ch;
	int dem1 = 0 , dem2 = 0;
	
	cout << "Nhap vao mat khau : ";
	while ((ch = _getch()) != 13) {
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9')) {
			cout << "*";
			a1[dem1++] = ch;
		}
		else
			if (ch == 8)
				if (dem1>0) {
					cout << "\b \b";
					dem1--;
				}
	}

	cout << endl;

	cout << "Nhap lai mat khau lan nua : ";
	while ((ch = _getch()) != 13) {
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9')) {
			cout << "*";
			a2[dem2++] = ch;
		}
		else
			if (ch == 8)
				if (dem2>0) {
					cout << "\b \b";
					dem2--;
				}
	}

	cout << endl;

	if (strcmp(a1, a2) == 0) {
		char ch;
		strcpy_s(DanhSach.MangChuaDocGia[DanhSach.n - 1].MatKhau, a1);

		cout << "Nhap vao ma so : ";
		cin.ignore(INT_MAX, '\n');
		cin.getline(DanhSach.MangChuaDocGia[DanhSach.n - 1].MaDocGia, 10); cout << endl;

		cout << "Nhap Ho ten : ";
		cin.getline(DanhSach.MangChuaDocGia[DanhSach.n - 1].HoTen, 40); cout << endl;

		cout << "Mhap vao gioi tinh : ";
		cin.getline(DanhSach.MangChuaDocGia[DanhSach.n - 1].GioiTinh, 10); cout << endl;

		cout << "Nhap vao Email : ";
		cin.getline(DanhSach.MangChuaDocGia[DanhSach.n - 1].Email, 50); cout << endl;

		cout << "Nhap vao dia chi : ";
		cin.getline(DanhSach.MangChuaDocGia[DanhSach.n - 1].DiaChi, 50); cout << endl;

		cout << "Nhap vao ngay, thang, nam sinh (dd/mm/yyyy) : ";
		cin >> DanhSach.MangChuaDocGia[DanhSach.n - 1].NgaySinh >> ch >> DanhSach.MangChuaDocGia[DanhSach.n - 1].ThangSinh >> ch >> DanhSach.MangChuaDocGia[DanhSach.n - 1].NamSinh;
		cout << endl;

		LuuDanhSachDocGiaVaoTepTin(DanhSach);
	}
	else {
		cout << "Nhap khong dung!!! " << endl;
		_getch();
		goto Menu;
	}

}