#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<conio.h>

#define DocGiaMAx 100

using namespace std;

struct ThongTinDocGia {
	char MaDocGia[11] = "\0", HoTen[41] = "\0" , GioiTinh[11] = "\0",Email[51] = "\0", DiaChi[51] = "\0";
	int NgaySinh, ThangSinh, NamSinh, NgayMuon, ThangMuon, NamMuon, NgayHet, ThangHet, NamHet;
};

void NhapThongTinDocGia(ThongTinDocGia &tt);


struct DanhSachDocGia {
	int n= 0;
	ThongTinDocGia MangChuaDocGia[DocGiaMAx];
};

void NhapDanhSachDocGia(DanhSachDocGia &DanhSach);

void XuatDanhSachDocGia(DanhSachDocGia &DanhSach);


void DocDuLieuVaoDanhSach(DanhSachDocGia &DanhSach);


void LuuThongTinDocGiaVaoTepTin(ThongTinDocGia tt); 

int KiemTraMaSoDocGia(DanhSachDocGia DanhSach);

void LuuDanhSachDocGiaVaoTepTin(DanhSachDocGia DanhSach);
