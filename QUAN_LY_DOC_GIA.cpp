
#include"QUAN_LY_DOC_GIA.h"

//Nhap Thong tin Doc Gia

void NhapThongTinDocGia(ThongTinDocGia &tt) {

	cout << "Nhap ma so Doc Gia: " << endl;
	cin.getline(tt.MaDocGia, 10);
	cout << "Nhap ho ten Doc Gia: " << endl;
	cin.getline(tt.HoTen,40 );
	cout << "Nhap gioi tinh Doc Gia: " << endl;
	cin.getline(tt.GioiTinh,10);
	cout << "Nhap Email Doc Gia: " << endl;
	cin.getline(tt.Email,50);
	cout << "Nhap dia chi Doc Gia : " << endl;
	cin.getline(tt.DiaChi, 50);
}



void LuuThongTinDocGiaVaoTepTin(ThongTinDocGia tt) {

	fstream File;
	File.open("DanhSachDocGia.txt", ios::out | ios::app);
	File << endl;
	File << tt.MaDocGia	<< setw(10 - strlen(tt.MaDocGia))	<<  left << ";" 
		 << tt.HoTen	<< setw(40 - strlen(tt.HoTen))		<<  left << ";" 
		 << tt.GioiTinh << setw(10 - strlen(tt.GioiTinh))	<<  left << ";" 
		 << tt.Email	<< setw(50 - strlen(tt.Email))		<<  left << ";"
		 << tt.DiaChi	<< setw(50 - strlen(tt.DiaChi))		<<  left << ";" ;
	
	File.close();
}

void LuuDanhSachDocGiaVaoTepTin(DanhSachDocGia DanhSach) {

	fstream File;
	File.open("DanhSachDocGia.txt", ios::out);
	for (int i = 0; i < DanhSach.n; i++) {
		if (i != DanhSach.n - 1) {
			File << DanhSach.MangChuaDocGia[i].MaDocGia << setw(10 - strlen(DanhSach.MangChuaDocGia[i].MaDocGia))	<< left << ";"
				 << DanhSach.MangChuaDocGia[i].HoTen	<< setw(40 - strlen(DanhSach.MangChuaDocGia[i].HoTen))		<< left << ";"
				 << DanhSach.MangChuaDocGia[i].GioiTinh << setw(10 - strlen(DanhSach.MangChuaDocGia[i].GioiTinh))	<< left << ";"
				 << DanhSach.MangChuaDocGia[i].Email	<< setw(50 - strlen(DanhSach.MangChuaDocGia[i].Email))		<< left << ";"
				 << DanhSach.MangChuaDocGia[i].DiaChi	<< setw(50 - strlen(DanhSach.MangChuaDocGia[i].DiaChi))		<< left << ";"
				 << endl;
		}
		else {
			File << DanhSach.MangChuaDocGia[i].MaDocGia << setw(10 - strlen(DanhSach.MangChuaDocGia[i].MaDocGia))	<< left << ";"
				 << DanhSach.MangChuaDocGia[i].HoTen	<< setw(40 - strlen(DanhSach.MangChuaDocGia[i].HoTen))		<< left << ";"
				 << DanhSach.MangChuaDocGia[i].GioiTinh << setw(10 - strlen(DanhSach.MangChuaDocGia[i].GioiTinh))	<< left << ";"
				 << DanhSach.MangChuaDocGia[i].Email	<< setw(50 - strlen(DanhSach.MangChuaDocGia[i].Email))		<< left << ";"
				 << DanhSach.MangChuaDocGia[i].DiaChi	<< setw(50 - strlen(DanhSach.MangChuaDocGia[i].DiaChi))		<< left << ";";
		}
	}
	File.close();
}



void NhapDanhSachDocGia(DanhSachDocGia &DanhSach) {
	int n;
	cout << "Nhap so luong doc gia can them vao." << endl;
	cin >> n;
	cin.ignore(INT_MAX, '\n');
	for (int i = 0; i < n; i++) {
		DanhSach.n++;
		cout << "Nhap thong tin cua doc gia thu " << i + 1 << endl;
		NhapThongTinDocGia(DanhSach.MangChuaDocGia[i]);
		LuuThongTinDocGiaVaoTepTin(DanhSach.MangChuaDocGia[i]);
	}
}


void DocDuLieuVaoDanhSach(DanhSachDocGia &DanhSach) { //Ham doc du lieu tu file vao Danh Sach doc gia
	int k = 0;
	string str, strsub;
	fstream File;
	File.open("DanhSachDocGia.txt", ios::in);

	if (!File) {
		cout << "Khong doc duoc file !!!" << endl;
	}
	else {
		while (!File.eof()) {
			getline(File, str);

			strsub = str.substr(0, 9);

			for (int i = 0; i < 10; i++) {
				if (strsub[i] == ';') {
					break;
				}
				else {
					DanhSach.MangChuaDocGia[k].MaDocGia[i] = strsub[i];
				}
			}

			strsub = str.substr(10, 49);
			for (int i = 0; i < 40; i++) {
				if (strsub[i] == ';') {
					break;
				}
				else {
					DanhSach.MangChuaDocGia[k].HoTen[i] = strsub[i];
				}
			}

			strsub = str.substr(50, 59);
			for (int i = 0; i < 10; i++) {
				if (strsub[i] == ';') {
					break;
				}
				else {
					DanhSach.MangChuaDocGia[k].GioiTinh[i] = strsub[i];
				}
			}

			strsub = str.substr(60, 109);
			for (int i = 0; i < 50; i++) {
				if (strsub[i] == ';') {
					break;
				}
				else {
					DanhSach.MangChuaDocGia[k].Email[i] = strsub[i];
				}
			}

			strsub = str.substr(110, 159);
			for (int i = 0; i < 50; i++) {
				if (strsub[i] == ';') {
					break;
				}
				else {
					DanhSach.MangChuaDocGia[k].DiaChi[i] = strsub[i];
				}
			}



			k++;
			str.clear();

		}
		DanhSach.n = k;
	}
	File.close();
}

void XuatDanhSachDocGia(DanhSachDocGia &DanhSach) {

	DocDuLieuVaoDanhSach(DanhSach);
	cout << "---------------------------------------------DANH SACH DOC GIA----------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------" << endl;
	cout << "| STT   Ma Doc Gia   Ho ten                    Gioi Tinh   Email                             Dia Chi |" << endl;
	for (int i = 0; i < DanhSach.n; i++) {
		cout << "| " << setw(6) << left << i + 1	<< setw(13) << left		<< DanhSach.MangChuaDocGia[i].MaDocGia
													<< setw(26) << left		<< DanhSach.MangChuaDocGia[i].HoTen
													<< setw(12) << left		<< DanhSach.MangChuaDocGia[i].GioiTinh
													<< setw(25) << left		<< DanhSach.MangChuaDocGia[i].Email 
													<< setw(16) << right	<< DanhSach.MangChuaDocGia[i].DiaChi
			<< " |" << endl;
	}
	cout << "------------------------------------------------------------------------------------------------------" << endl;

}

int KiemTraMaSoDocGia(DanhSachDocGia DanhSach) {

	int check = -1;
	char q[10];
	cout << "Nhap vao ma so can chinh sua." << endl;
	cin.ignore(INT_MAX, '\n');
	cin.getline(q, 10);

	for (int i = 0; i < DanhSach.n; i++) {
		if (strcmp(q, DanhSach.MangChuaDocGia[i].MaDocGia) == 0) {
			check = i;
			break;
		}
		
	}

	return check;
}