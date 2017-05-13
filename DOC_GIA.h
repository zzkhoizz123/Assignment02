
#ifndef DOC_GIA
#define DOC_GIA

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<sstream>

#define DocGiaMax 100

using namespace std;

struct ThongTinDocGia {
	char MaDocGia[11] = "\0", HoTen[41] = "\0", GioiTinh[11] = "\0", Email[51] = "\0", DiaChi[51] = "\0", MatKhau[21] = "\0";
	char SachDaMuon[51] = "\0";
	int NgaySinh, ThangSinh, NamSinh, NgayMuon = 0, ThangMuon = 0, NamMuon = 0, NgayHet = 0 , ThangHet = 0 , NamHet = 0;
	double TienPhat = 0;
	int active = 0;
};



struct DanhSachDocGia {
	int n = 0;
	ThongTinDocGia MangChuaDocGia[DocGiaMax];
};


void XemThongTinCuaMotDocGia(DanhSachDocGia DanhSach, int i);

int KiemTraMatkhauDocGia(char *MK, DanhSachDocGia DanhSach);

void NhapThongTinDocGia(ThongTinDocGia &tt);

void InThongTinDocGia(DanhSachDocGia DanhSach, int i);


void DocDuLieuVaoDSDG(DanhSachDocGia &DanhSach);

int KiemTraMaSoDocGia(DanhSachDocGia DanhSach);

int KiemTraHoTenDocGia(DanhSachDocGia DanhSach);

void LuuDanhSachDocGiaVaoTepTin(DanhSachDocGia DanhSach);






#endif // !DOC_GIA

