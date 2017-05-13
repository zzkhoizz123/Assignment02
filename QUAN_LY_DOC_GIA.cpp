
#include "QUAN_LY_DOC_GIA.h"



void DocDuLieuVaoDSQLDG(DanhSachQuanLyDocGia &DanhSach) {

	int k = 0;
	string str, strsub;
	fstream File;
	File.open("DanhSachQuanLyDocGia.txt", ios::in);

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
					DanhSach.MangchuaQuanLyDocGia[k].MaSoQuanLyDocGia[i] = strsub[i];
				}
			}

			strsub = str.substr(10, 49);
			for (int i = 0; i < 40; i++) {
				if (strsub[i] == ';') {
					break;
				}
				else {
					DanhSach.MangchuaQuanLyDocGia[k].HoTen[i] = strsub[i];
				}
			}

			strsub = str.substr(50, 59);
			for (int i = 0; i < 10; i++) {
				if (strsub[i] == ';') {
					break;
				}
				else {
					DanhSach.MangchuaQuanLyDocGia[k].GioiTinh[i] = strsub[i];
				}
			}

			strsub = str.substr(60, 109);
			for (int i = 0; i < 50; i++) {
				if (strsub[i] == ';') {
					break;
				}
				else {
					DanhSach.MangchuaQuanLyDocGia[k].Email[i] = strsub[i];
				}
			}

			strsub = str.substr(110, 159);
			for (int i = 0; i < 50; i++) {
				if (strsub[i] == ';') {
					break;
				}
				else {
					DanhSach.MangchuaQuanLyDocGia[k].DiaChi[i] = strsub[i];
				}
			}

			strsub = str.substr(160, 179);
			for (int i = 0; i < 20; i++) {
				if (strsub[i] == ';') {
					break;
				}
				else {
					DanhSach.MangchuaQuanLyDocGia[k].MatKhau[i] = strsub[i];
				}
			}
	
			k++;
			str.clear();

		}
		DanhSach.n = k;
	}
	File.close();
}




int KiemTranMaKhauQuanLyDocGia(char* MK, DanhSachQuanLyDocGia DanhSach) {
	int ret = -1;
	for (int i = 0; i < DanhSach.n; i++) {
		if (strcmp(MK, DanhSach.MangchuaQuanLyDocGia[i].MatKhau) == 0) {
				ret = i;
				break;
			}
		}
	return ret;
}
	


void XuatDanhSachDocGiaChuaDuocHichHoat(DanhSachDocGia DanhSach) {
	
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "| STT   Ma Doc Gia   Ho ten                    Gioi Tinh   Email                    Dia Chi                       Sach Da Muon                            Ngay Sinh |" << endl;
			for (int i = 0; i < DanhSach.n; i++) {
				if (DanhSach.MangChuaDocGia[i].active == 0) {
				cout << "| " << setw(6) << left << i + 1 << setw(13) << left << DanhSach.MangChuaDocGia[i].MaDocGia
					<< setw(26) << left << DanhSach.MangChuaDocGia[i].HoTen
					<< setw(12) << left << DanhSach.MangChuaDocGia[i].GioiTinh
					<< setw(25) << left << DanhSach.MangChuaDocGia[i].Email
					<< setw(30) << left << DanhSach.MangChuaDocGia[i].DiaChi
					<< setw(40) << left << DanhSach.MangChuaDocGia[i].SachDaMuon
					<< DanhSach.MangChuaDocGia[i].NgaySinh << "/" << DanhSach.MangChuaDocGia[i].ThangSinh << "/" << DanhSach.MangChuaDocGia[i].NamSinh
					<< " |" << endl;
				}
			}
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;			
}

void KichHoatMatKhauChoMotDG(DanhSachDocGia &DanhSach) {
	int i = KiemTraMaSoDocGia(DanhSach);
	if (i == -1) {
		cout << "Khong tim thay !!!" << endl;
	}
	else {
		DanhSach.MangChuaDocGia[i].active = 1;
		LuuDanhSachDocGiaVaoTepTin(DanhSach);
		cout << "Kich hoat thanh cong." << endl;
	}	
}

void KichHoatMatKhauChoToanBoDocGia(DanhSachDocGia &DanhSach) {
	for (int i = 0; i < DanhSach.n; i++) {
		DanhSach.MangChuaDocGia[i].active = 1;
	}
	LuuDanhSachDocGiaVaoTepTin(DanhSach);
}

void XoaThongTinMotDocGia(DanhSachDocGia &DanhSach) {
	int i = KiemTraMaSoDocGia(DanhSach);
	if (i == -1) {
		cout << "Khong tim thay !!!" << endl;
	}
	else {
		DanhSach.n = DanhSach.n - 1;
		for (int k = i; k < DanhSach.n; k++) {
			strcpy_s(DanhSach.MangChuaDocGia[k].MaDocGia, DanhSach.MangChuaDocGia[k + 1].MaDocGia);
			strcpy_s(DanhSach.MangChuaDocGia[k].HoTen, DanhSach.MangChuaDocGia[k + 1].HoTen);
			strcpy_s(DanhSach.MangChuaDocGia[k].GioiTinh, DanhSach.MangChuaDocGia[k + 1].GioiTinh);
			strcpy_s(DanhSach.MangChuaDocGia[k].Email, DanhSach.MangChuaDocGia[k + 1].Email);
			strcpy_s(DanhSach.MangChuaDocGia[k].DiaChi, DanhSach.MangChuaDocGia[k + 1].DiaChi);
			strcpy_s(DanhSach.MangChuaDocGia[k].MatKhau, DanhSach.MangChuaDocGia[k + 1].MatKhau);
			strcpy_s(DanhSach.MangChuaDocGia[k].SachDaMuon, DanhSach.MangChuaDocGia[k + 1].SachDaMuon);
			DanhSach.MangChuaDocGia[k].active = DanhSach.MangChuaDocGia[k + 1].active;
			DanhSach.MangChuaDocGia[k].NgaySinh = DanhSach.MangChuaDocGia[k + 1].NgaySinh;
			DanhSach.MangChuaDocGia[k].ThangSinh = DanhSach.MangChuaDocGia[k + 1].ThangSinh;
			DanhSach.MangChuaDocGia[k].NamSinh = DanhSach.MangChuaDocGia[k + 1].NamSinh;
			DanhSach.MangChuaDocGia[k].NgayMuon = DanhSach.MangChuaDocGia[k + 1].NgayMuon;
			DanhSach.MangChuaDocGia[k].ThangMuon = DanhSach.MangChuaDocGia[k + 1].ThangMuon;
			DanhSach.MangChuaDocGia[k].NamMuon = DanhSach.MangChuaDocGia[k + 1].NamMuon;
			DanhSach.MangChuaDocGia[k].NgayHet = DanhSach.MangChuaDocGia[k + 1].NgayHet	;
			DanhSach.MangChuaDocGia[k].ThangHet = DanhSach.MangChuaDocGia[k + 1].ThangHet;
			DanhSach.MangChuaDocGia[k].NamHet = DanhSach.MangChuaDocGia[k + 1].NamHet;
		}
		LuuDanhSachDocGiaVaoTepTin(DanhSach);
		cout << "Thanh cong." << endl;
	}
}