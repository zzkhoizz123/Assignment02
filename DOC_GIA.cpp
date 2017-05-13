#include "DOC_GIA.h"


int KiemTraMatkhauDocGia(char *MK, DanhSachDocGia DanhSach) {
	int ret = -1;
	for (int i = 0; i < DanhSach.n; i++) {
		if (strcmp(MK, DanhSach.MangChuaDocGia[i].MatKhau) == 0) {
			if (DanhSach.MangChuaDocGia[i].active == 1) {
				ret = i;
				break;
			}
		}
	}
	return ret;
}


void NhapThongTinDocGia(ThongTinDocGia &tt) {

	cout << "Nhap ma so Doc Gia: " << endl;
	cin.getline(tt.MaDocGia, 10);
	cout << "Nhap ho ten Doc Gia: " << endl;
	cin.getline(tt.HoTen, 40);
	cout << "Nhap gioi tinh Doc Gia: " << endl;
	cin.getline(tt.GioiTinh, 10);
	cout << "Nhap Email Doc Gia: " << endl;
	cin.getline(tt.Email, 50);
	cout << "Nhap dia chi Doc Gia : " << endl;
	cin.getline(tt.DiaChi, 50);
	cout << "Nhap vao "; // chuwa xong !!!!!!!!!!!!
}


void DocDuLieuVaoDSDG(DanhSachDocGia &DanhSach) { //Ham doc du lieu tu file vao Danh Sach doc gia
	int k = 0;
	char ch;
	string str, strsub;
	fstream File;
	File.open("DanhSachDocGia.txt", ios::in);

	if (!File) {
		cout << "Khong doc duoc file !!!" << endl;
	}
	else {
		
		while (!File.eof()) {
			getline(File, str);
			if (str.empty()) {
				break;
			}

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

			strsub = str.substr(160, 179);
			for (int i = 0; i < 20; i++) {
				if (strsub[i] == ';') {
					break;
				}
				else {
					DanhSach.MangChuaDocGia[k].MatKhau[i] = strsub[i];
				}
			}
			strsub = str.substr(180, 229);
			for (int i = 0; i < 20; i++) {
				if (strsub[i] == ';') {
					break;
				}
				else {
					DanhSach.MangChuaDocGia[k].SachDaMuon[i] = strsub[i];
				}
			}

			strsub = str.substr(230, 300);
			stringstream ss(strsub);
			ss >> DanhSach.MangChuaDocGia[k].active >> ch
				>> DanhSach.MangChuaDocGia[k].NgaySinh >> ch >> DanhSach.MangChuaDocGia[k].ThangSinh >> ch >> DanhSach.MangChuaDocGia[k].NamSinh >> ch
				>> DanhSach.MangChuaDocGia[k].NgayMuon >> ch >> DanhSach.MangChuaDocGia[k].ThangMuon >> ch >> DanhSach.MangChuaDocGia[k].NamMuon >> ch
				>> DanhSach.MangChuaDocGia[k].NgayHet >> ch >> DanhSach.MangChuaDocGia[k].ThangHet >> ch >> DanhSach.MangChuaDocGia[k].NamHet >> ch
				>> DanhSach.MangChuaDocGia[k].TienPhat;
			k++;
			str.clear();
		}
		DanhSach.n = k;
	}
	File.close();
}



void LuuDanhSachDocGiaVaoTepTin(DanhSachDocGia DanhSach) {

	fstream File;
	File.open("DanhSachDocGia.txt", ios::out);
	for (int i = 0; i < DanhSach.n; i++) {
		if (i != DanhSach.n - 1) {
			File << DanhSach.MangChuaDocGia[i].MaDocGia << setw(10 - strlen(DanhSach.MangChuaDocGia[i].MaDocGia)) << left << ";"
				<< DanhSach.MangChuaDocGia[i].HoTen << setw(40 - strlen(DanhSach.MangChuaDocGia[i].HoTen)) << left << ";"
				<< DanhSach.MangChuaDocGia[i].GioiTinh << setw(10 - strlen(DanhSach.MangChuaDocGia[i].GioiTinh)) << left << ";"
				<< DanhSach.MangChuaDocGia[i].Email << setw(50 - strlen(DanhSach.MangChuaDocGia[i].Email)) << left << ";"
				<< DanhSach.MangChuaDocGia[i].DiaChi << setw(50 - strlen(DanhSach.MangChuaDocGia[i].DiaChi)) << left << ";"
				<< DanhSach.MangChuaDocGia[i].MatKhau << setw(20 - strlen(DanhSach.MangChuaDocGia[i].MatKhau)) << left << ";"
				<< DanhSach.MangChuaDocGia[i].SachDaMuon << setw(50 - strlen(DanhSach.MangChuaDocGia[i].SachDaMuon)) << left << ";"
				<< DanhSach.MangChuaDocGia[i].active << setw(10) << left << ";"
				<< DanhSach.MangChuaDocGia[i].NgaySinh << "/" << DanhSach.MangChuaDocGia[i].ThangSinh << "/" << DanhSach.MangChuaDocGia[i].NamSinh << setw(6) << left << ";"
				<< DanhSach.MangChuaDocGia[i].NgayMuon << "/" << DanhSach.MangChuaDocGia[i].ThangMuon << "/" << DanhSach.MangChuaDocGia[i].NamMuon << setw(6) << left << ";"
				<< DanhSach.MangChuaDocGia[i].NgayHet << "/" << DanhSach.MangChuaDocGia[i].ThangHet << "/" << DanhSach.MangChuaDocGia[i].NamHet << setw(6) << left << ";"
				<< DanhSach.MangChuaDocGia[i].TienPhat << ";"
				<< endl;
		}
		else {
			File << DanhSach.MangChuaDocGia[i].MaDocGia << setw(10 - strlen(DanhSach.MangChuaDocGia[i].MaDocGia)) << left << ";"
				<< DanhSach.MangChuaDocGia[i].HoTen << setw(40 - strlen(DanhSach.MangChuaDocGia[i].HoTen)) << left << ";"
				<< DanhSach.MangChuaDocGia[i].GioiTinh << setw(10 - strlen(DanhSach.MangChuaDocGia[i].GioiTinh)) << left << ";"
				<< DanhSach.MangChuaDocGia[i].Email << setw(50 - strlen(DanhSach.MangChuaDocGia[i].Email)) << left << ";"
				<< DanhSach.MangChuaDocGia[i].DiaChi << setw(50 - strlen(DanhSach.MangChuaDocGia[i].DiaChi)) << left << ";"
				<< DanhSach.MangChuaDocGia[i].MatKhau << setw(20 - strlen(DanhSach.MangChuaDocGia[i].MatKhau)) << left << ";"
				<< DanhSach.MangChuaDocGia[i].SachDaMuon << setw(50 - strlen(DanhSach.MangChuaDocGia[i].SachDaMuon)) << left << ";"
				<< DanhSach.MangChuaDocGia[i].active << setw(10) << left << ";"
				<< DanhSach.MangChuaDocGia[i].NgaySinh << "/" << DanhSach.MangChuaDocGia[i].ThangSinh << "/" << DanhSach.MangChuaDocGia[i].NamSinh << setw(6) << left << ";"
				<< DanhSach.MangChuaDocGia[i].NgayMuon << "/" << DanhSach.MangChuaDocGia[i].ThangMuon << "/" << DanhSach.MangChuaDocGia[i].NamMuon << setw(6) << left << ";"
				<< DanhSach.MangChuaDocGia[i].NgayHet << "/" << DanhSach.MangChuaDocGia[i].ThangHet << "/" << DanhSach.MangChuaDocGia[i].NamHet << setw(6) << left << ";"
				<< DanhSach.MangChuaDocGia[i].TienPhat << ";";
		}
	}
	File.close();
}

void XemThongTinCuaMotDocGia(DanhSachDocGia DanhSach, int i) {
	cout << "Ma So : " << DanhSach.MangChuaDocGia[i].MaDocGia << "." << endl;
	cout << "Ho Ten : " << DanhSach.MangChuaDocGia[i].HoTen << "." << endl;
	cout << "Gioi Tinh : " << DanhSach.MangChuaDocGia[i].GioiTinh << "." << endl;
	cout << "Email : " << DanhSach.MangChuaDocGia[i].Email << "." << endl;
	cout << "Dia Chi : " << DanhSach.MangChuaDocGia[i].DiaChi << "." << endl;
	cout << "Sach da muon : ";
	if (strcmp(DanhSach.MangChuaDocGia[i].SachDaMuon , "") == 0) {
		cout << "Chua muon quyen nao." << endl;	
	}
	else {
		cout << DanhSach.MangChuaDocGia[i].SachDaMuon << "." << endl;
	}
	cout << "Ngay, thang, nam sinh : "
		<< DanhSach.MangChuaDocGia[i].NgaySinh << "/" << DanhSach.MangChuaDocGia[i].ThangSinh << "/" << DanhSach.MangChuaDocGia[i].NamSinh << endl;
	cout << "Ngay, thang, nam muon sach : "
		<< DanhSach.MangChuaDocGia[i].NgayMuon << "/" << DanhSach.MangChuaDocGia[i].ThangMuon << "/" << DanhSach.MangChuaDocGia[i].NamMuon << endl;
	cout << "Ngay, thang, nam tra ( Theo qui dinh ) : "
		<< DanhSach.MangChuaDocGia[i].NgayHet << "/" << DanhSach.MangChuaDocGia[i].ThangHet << "/" << DanhSach.MangChuaDocGia[i].NamHet << endl;
	cout << "Tien bi phat ( do tre han ) : "
		<< DanhSach.MangChuaDocGia[i].TienPhat << "." << endl;
}


int KiemTraMaSoDocGia(DanhSachDocGia DanhSach) {

	int check = -1;
	char q[11];
	cout << "Nhap vao ma so doc gia." << endl;
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

void InThongTinDocGia(DanhSachDocGia DanhSach, int i) {


	cout << "| " << setw(6) << left << i + 1 << setw(13) << left << DanhSach.MangChuaDocGia[i].MaDocGia
		<< setw(26) << left << DanhSach.MangChuaDocGia[i].HoTen
		<< setw(12) << left << DanhSach.MangChuaDocGia[i].GioiTinh
		<< setw(25) << left << DanhSach.MangChuaDocGia[i].Email
		<< setw(30) << left << DanhSach.MangChuaDocGia[i].DiaChi
		<< setw(40) << left << DanhSach.MangChuaDocGia[i].SachDaMuon
		<< DanhSach.MangChuaDocGia[i].NgaySinh << "/" << DanhSach.MangChuaDocGia[i].ThangSinh << "/" << DanhSach.MangChuaDocGia[i].NamSinh

		<< " |" << endl;
}

int KiemTraHoTenDocGia(DanhSachDocGia DanhSach) {

	int check = -1;
	char q[41];
	cout << "Nhap vao Ho Ten doc gia." << endl;
	cin.ignore(INT_MAX, '\n');
	cin.getline(q, 40);

	for (int i = 0; i < DanhSach.n; i++) {
		if (strcmp(q, DanhSach.MangChuaDocGia[i].HoTen) == 0) {
			check = i;
			break;
		}

	}
	return check;
}


