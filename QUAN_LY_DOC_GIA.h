#ifndef QUAN_LY_DOC_GIA
#define QUAN_LY_DOC_GIA

#pragma once

#include"DOC_GIA.h"

#define QuanLyDocGiaMax 20

using namespace std;

struct ThongTinQuanLyDocGia {
	char MaSoQuanLyDocGia[11] = "\0", HoTen[41] = "\0", GioiTinh[11] = "\0", Email[51] = "\0", DiaChi[51] = "\0", MatKhau[21] = "\0";
	int NgaySinh, ThangSinh, NamSinh, NgayGiaNhap, ThangGiaNhap, NamGiaNhap;
};

struct DanhSachQuanLyDocGia {
	int n;
	ThongTinQuanLyDocGia MangchuaQuanLyDocGia[QuanLyDocGiaMax];

};


int KiemTranMaKhauQuanLyDocGia(char* MK, DanhSachQuanLyDocGia DanhSach);

void DocDuLieuVaoDSQLDG(DanhSachQuanLyDocGia &DanhSach);


void XuatDanhSachDocGiaChuaDuocHichHoat(DanhSachDocGia DanhSach);

void KichHoatMatKhauChoMotDG(DanhSachDocGia &DanhSach);

void KichHoatMatKhauChoToanBoDocGia(DanhSachDocGia &DanhSach);

void XoaThongTinMotDocGia(DanhSachDocGia &DanhSach);


#endif // !(QUAN_LY_DOC_GIA)
