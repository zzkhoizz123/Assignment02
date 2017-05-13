
#include"QUAN_LY_DOC_GIA.h"
#include"HAM_PHU.h"


int main() {

	ThongTinDocGia			DG;
	DanhSachDocGia			DSDG;
	DanhSachQuanLyDocGia	DSQLDG;

	int ViTriDocGiaTrongDanhSach;
	int ViTriQuanLyDocGia;
		int a;
		char MK[21] = "\0";

	MenuChinh:		// O menu nay minh se them lua chon dang nhap la Quan Ly Doc Gia hay Thu Thu 
					
		system("cls");
		cout << "********************************************************************" << endl;
		cout << "-------------------- PHAN MEM QUAN LY THU VIEN ---------------------" << endl;
		cout << "********************************************************************" << endl;

		cout << endl;
		cout << "De lam viec voi phan mem xin vui long lam theo cac yeu cau ben duoi !!!!!" << endl;

		cout << "LUU Y: De thuc hien cac lenh can lam. Hay nhap cac  ky tu o dau moi dong trong cac menu lenh." << endl;
		cout << endl;

		cout << "Nhap lua chon." << endl;
		cout << "[1] : Dang nhap mat khau." << endl;
		cout << "[2] : Dang ky mat khau." << endl;
		cout << "[3] : Thoat." << endl;
		cin >> a;
		switch (a) {

		case 1: { // dang nhap mat khau
			NhapMatKhau(MK);
			cout << endl;
		Menu0:
			cout << "Nhap lua chon:" << endl;
			cout << "Mat khau ban :" << endl;
			cout << "[1] : Dang nhap theo kieu doc gia." << endl;
			cout << "[2] : Dang nhap theo kieu quan ly doc gia" << endl;
			cout << "[3] : Dang nhap theo kieu thu thu." << endl;
			cout << "Nhap lua chon:" << endl;
			int luachon1;
			cin >> luachon1;
			switch (luachon1) {

//=============================================================================================================================
//****************************************************** D O C   G I A ********************************************************
//=============================================================================================================================

			case 1: { // dang nhap kieu doc gia
				DocDuLieuVaoDSDG(DSDG);
				ViTriDocGiaTrongDanhSach = KiemTraMatkhauDocGia(MK,DSDG);
				if (ViTriDocGiaTrongDanhSach == -1) {
					cout << "Nhap sai!!!" << endl;
					cout << "Ban co muon nhap lai khong ? " << endl;
					cout << "[1] : Nhap lai." << endl;
					cout << "[2] : thoat khoi chuong trinh." << endl;
					int luachon2;
					cin >> luachon2;
					switch (luachon2) {
					case 1: {
						system("cls");
						goto MenuChinh;
					}
					case 2: {
						exit(0);
					}
					}
					
				}
				
				else {
					cout << "Dang nhap thanh cong !!!" << endl;
					_getch();
					system("cls");
					
				Menu1:
					cout << "========================= M E N U    D O C    G I A =========================" << endl;
					cout << "[1] : Xem thong tin cua ban" << endl;
					cout << "[2] : Chinh sua thong tin" << endl; // chinh sua ten, MK ...v.v
					cout << "[3] : Tim kiem sach." << endl; // tim kiem theo ten , tac gia ...v.v
					cout << "[4] : Dat mua Sach." << endl;
					cout << "[5] : Quay lai de dang nhap mat khau moi" << endl;
					cout << "Nhap lua chon." << endl;
					int luachon2;
					cin >> luachon2;
					switch (luachon2) {
					case 1: {
						system("cls");
						cout << "-----------------Thong Tin Cua Ban---------------------" << endl;
						XemThongTinCuaMotDocGia(DSDG, ViTriDocGiaTrongDanhSach);
						_getch();
						system("cls");
						cout << "[1] : Quay lai Menu Doc Gia." << endl;
						cout << "[2] : Thoat khoi chuong trinh." << endl;
						cout << "Nhap lua chon : " << endl;
						int luachon3;
						cin >> luachon3;
						switch (luachon3) {
						case 1: {
							system("cls");
							goto Menu1;
						}
						case 2: {
							exit(0);
						}
						}
					case 2: { // chinh sua thong tin doc gia

						system("cls");
					Menu2:
						system("cls");
						cout << "==========================CHUC NANG CHINH SUA THONG TIN DOC GIA========================" << endl;
						cout << "[1] : Chinh sua ma so." << endl;
						cout << "[2] : Chinh sua ho ten." << endl;
						cout << "[3] : Chinh sua gioi tinh." << endl;
						cout << "[4] : Chinh sua email." << endl;
						cout << "[5] : Chinh sua dia chi." << endl;
						cout << "[6] : Chinh sua mat khau" << endl;
						cout << "[7] : Quay lai MENU quan ly Doc Gia." << endl;
						cout << "Nhap vao chuc nang." << endl;
						int luachon3;
						cin >> luachon3;

						switch (luachon3) {

						case 1: {
							//*** chuc nang chinh sua ma so doc gia
							// Nhan vao ma so doc gia moi *****

							system("cls");
							cin.ignore(INT_MAX, '\n');
							cout << "Nhap vao ma so moi." << endl;
							cin.getline(DSDG.MangChuaDocGia[ViTriDocGiaTrongDanhSach].MaDocGia, 10);

							LuuDanhSachDocGiaVaoTepTin(DSDG);

							cout << "Chinh sua thanh cong !!!" << endl;
							_getch();
							system("cls");
							cout << "[1] : Tro lai Menu chinh sua thong tin Doc Gia." << endl;
							cout << "[2] : Thoat khoi chuong trinh." << endl;
							cout << "Nhap vao chuc nang." << endl;
							int chucnang2;
							cin >> chucnang2;
							if (chucnang2 == 1) {
								goto Menu2;
							}
							else
								exit(0);
						}
						case 2: {
							//*** chuc nang chinh sua Ho Ten
							// Nhap vao : Ho ten  *****

							system("cls");
							cin.ignore(INT_MAX, '\n');
							cout << "Nhap vao Ho Ten moi." << endl;
							cin.getline(DSDG.MangChuaDocGia[ViTriDocGiaTrongDanhSach].HoTen, 40);

							LuuDanhSachDocGiaVaoTepTin(DSDG);

							cout << "Chinh sua thanh cong !!!" << endl;
							_getch();
							system("cls");
							cout << "[1] : Tro lai Menu chinh sua thong tin Doc Gia." << endl;
							cout << "[2] : Thoat khoi chuong trinh." << endl;
							cout << "Nhap vao chuc nang." << endl;
							int chucnang2;
							cin >> chucnang2;
							if (chucnang2 == 1) {
								goto Menu2;
							}
							else
								exit(0);

						}
						case 3: {
							// ::::::::Chinh sua gioi tinh:::::::::
							// ::::::::nhap vao: gioi tinh:::::::::

							system("cls");
							cin.ignore(INT_MAX, '\n');
							cout << "Nhap vao gioi tinh moi." << endl;
							cin.getline(DSDG.MangChuaDocGia[ViTriDocGiaTrongDanhSach].GioiTinh, 10);

							LuuDanhSachDocGiaVaoTepTin(DSDG);

							cout << "Chinh sua thanh cong !!!" << endl;
							_getch();
							system("cls");
							cout << "[1] : Tro lai Menu chinh sua thong tin Doc Gia." << endl;
							cout << "[2] : Thoat khoi chuong trinh." << endl;
							cout << "Nhap vao chuc nang." << endl;
							int chucnang2;
							cin >> chucnang2;
							if (chucnang2 == 1) {
								goto Menu2;
							}
							else
								exit(0);

						}

						case 4: {
							//******Chinh sua email*****
							//*****Nhap vao: Email ******

							system("cls");
							cin.ignore(INT_MAX, '\n');
							cout << "Nhap vao Email moi." << endl;
							cin.getline(DSDG.MangChuaDocGia[ViTriDocGiaTrongDanhSach].Email, 50);

							LuuDanhSachDocGiaVaoTepTin(DSDG);

							cout << "Chinh sua thanh cong. " << endl;

							_getch();
							system("cls");
							cout << "[1] : Tro lai Menu chinh sua thong tin Doc Gia." << endl;
							cout << "[2] : Thoat khoi chuong trinh." << endl;
							cout << "Nhap vao chuc nang." << endl;
							int chucnang2;
							cin >> chucnang2;
							if (chucnang2 == 1) {
								goto Menu2;
							}
							else
								exit(0);

						}

						case 5: {
							// ::::::: Chinh sua dia chi :::::::::
							//::::::::Nhap vao: dia chi moi:::::::::

							system("cls");
							cin.ignore(INT_MAX, '\n');
							cout << "Nhap vao Dia Chi moi." << endl;
							cin.getline(DSDG.MangChuaDocGia[ViTriDocGiaTrongDanhSach].DiaChi, 50);

							LuuDanhSachDocGiaVaoTepTin(DSDG);

							cout << "Chinh sua thanh cong. " << endl;
							_getch();
							system("cls");
							cout << "[1] : Tro lai Menu chinh sua thong tin Doc Gia." << endl;
							cout << "[2] : Thoat khoi chuong trinh." << endl;
							cout << "Nhap vao chuc nang." << endl;
							int chucnang2;
							cin >> chucnang2;
							if (chucnang2 == 1) {
								goto Menu2;
							}
							else
								exit(0);
						}
						case 6: { // chinh sua mat khau

							system("cls");
							cin.ignore(INT_MAX, '\n');
							cout << "Nhap vao Mat Khau moi." << endl;
							cin.getline(DSDG.MangChuaDocGia[ViTriDocGiaTrongDanhSach].MatKhau, 20);

							LuuDanhSachDocGiaVaoTepTin(DSDG);

							cout << "Chinh sua thanh cong. " << endl;
							_getch();
							system("cls");
							cout << "[1] : Tro lai Menu chinh sua thong tin Doc Gia." << endl;
							cout << "[2] : Thoat khoi chuong trinh." << endl;
							cout << "Nhap vao chuc nang." << endl;
							int chucnang2;
							cin >> chucnang2;
							if (chucnang2 == 1) {
								goto Menu2;
							}
							else
								exit(0);

						}

						case 7: {
							// ********Tro lai MENU quan ly doc gia*********
							goto Menu1;
						}
						default: {
							system("cls");
							cout << "Khong co chuc nang nay." << endl;
							_getch();
							goto Menu2;
						}
						}//ket thuc case 1 : chinh sua thong tin doc gia
					}

					case 3: { // tim kiem sach




					}//ket thuc case 3 : tim kiem sach

					case 4: { // dat mua sach  //* luu y 1: khi dat mua sach thi can mot danh sach dat mua
											//va tat nhien se tru lai trong danh sach sach.
											   //* luu y 2: ta cung can them mot danh sach cac doc gia dat mua sach






					}//ket thuc case 4 : Dat mua sach

					case 5: { // quay lai dang nhap mat khau moi
						system("cls");
						goto MenuChinh;
					}

					default: {
						system("cls");
						cout << "Nhap khong dung !!!!!!" << endl;
						_getch();
						goto Menu1;
					}
					}
					}//ket thuc switch

				}//ket thuc else

				}//het case 1

//=============================================================================================================================
//******************************************* Q U A N    LY    D O C     G I A ************************************************
//=============================================================================================================================
			
			case 2: { // dang nhap kieu quan ly doc gia
				DocDuLieuVaoDSDG(DSDG);
				DocDuLieuVaoDSQLDG(DSQLDG);
				ViTriQuanLyDocGia = KiemTranMaKhauQuanLyDocGia(MK, DSQLDG);
				if (ViTriQuanLyDocGia == -1) {
					cout << "Nhap sai!!!" << endl;
					cout << "Ban co muon nhap lai khong ? " << endl;
					cout << "[1] : Nhap lai." << endl;
					cout << "[2] : thoat khoi chuong trinh." << endl;
					int luachon2;
					cin >> luachon2;
					switch (luachon2) {
					case 1: {
						system("cls");
						goto MenuChinh;
					}
					case 2: {
						exit(0);
					}
					}
				}
				else {
					cout << "Dang nhap thanh cong !!!" << endl;
					_getch();
					
				Menu3:
					system("cls");
					cout << "=================== M E N U    Q U A N    L Y    D O C    G I A ==================" << endl;
					cout << "[1] : In ra danh sach doc gia." << endl;
					cout << "[2] : Kich hoat mat khau cho doc gia." << endl; // tim kiem theo ten , tac gia ...v.v
					cout << "[3] : Xoa thong tin mot doc gia." << endl;
					cout << "[4] : Tim kiem doc gia theo ma so." << endl;
					cout << "[5] : Tim kiem doc gia theo ho ten." << endl;
					cout << "[6] : Quay lai de dang nhap mat khau moi. " << endl;
					cout << "Nhap lua chon." << endl;
					int luachon2;
					cin >> luachon2;
					switch (luachon2) {
					case 1: { // in ra danh sach doc gia
						system("cls");
						int tam = 0;
						cout << "---------------------------------------------------------------------------- DANH SACH DOC GIA ----------------------------------------------------------------------" << endl;				
						cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
						cout << "| STT   Ma Doc Gia   Ho ten                    Gioi Tinh   Email                    Dia Chi                       Sach Da Muon                            Ngay Sinh |" << endl;

						for (int i = 0; i < DSDG.n; i++) {
							if (i != tam + 10) {
								InThongTinDocGia(DSDG, i);

							}
							else {
								Menu5:
								cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
								cout << "[1] : Xem tiep." << endl;
								cout << "[2] : Quay lai." << endl;
								cout << "[3] : Thoat." << endl;
								int luachon3;
								cin >> luachon3;
								switch (luachon3) {
								case 1: {
									system("cls");
									
										InThongTinDocGia(DSDG, i);
										tam = i;
										break;								
								}
								case 2: {
									goto Menu3;
								}
								case 3: {
									exit(0);
								}
								default: {
									goto Menu3;
								}
								}
							}
						}
						cout << "Het!!!" << endl;
						goto Menu5;
						
					}//het case 1

					case 2: { // Kich hoat mat khau mot doc gia
						Menu4:
						system("cls");
						cout << "[1] : Kich hoat mat khau cho 1 doc gia." << endl;
						cout << "[2] : Kich hoat mat khau cho toan bo doc gia." << endl ;
						cout << "[3] : Quay lai." << endl << endl;
						cout << "Nhap lua chon : ";
						int luachon3;
						cin >> luachon3;
						switch (luachon3) {
						case 1: {
							system("cls");
							XuatDanhSachDocGiaChuaDuocHichHoat(DSDG);
							_getch();
							KichHoatMatKhauChoMotDG(DSDG);
							_getch();
							goto Menu3;
						}
						case 2: {
							system("cls");
							KichHoatMatKhauChoToanBoDocGia(DSDG);
							cout << "kich hoat thanh cong." << endl;
							_getch();
							goto Menu3;
						}
						default: {
							_getch();
							goto Menu3;
						}

						}//ket thuc switch			
					
					}//het case 2
	
					case 3: { // Xoa thong tin mot doc gia
						
						_getch();
						XoaThongTinMotDocGia(DSDG);
						_getch();
						system("cls");
						cout << "[1] : Quay lai Menu Quan ly doc gia." << endl;
						cout << "[2] : Thoat khoi chuong trinh. " << endl;
						cout << "Nhap lua chon." << endl;
						int luachon3;
						cin >> luachon3;
						switch (luachon3) {
						case 1:
							goto Menu3;
						case 2:
							exit(0);
						default:
							goto Menu3;
						}	

					} // het case 3
					case 4: {//Tim kiem doc gia theo ma so

						system("cls");

						int ret = KiemTraMaSoDocGia(DSDG);
						if (ret != -1) {
							cout << "================= Thong Tin Cua Doc Gia Can Tim ==================" << endl;
							XemThongTinCuaMotDocGia(DSDG, ret);
							Menu6:
							_getch();
							cout << "[1] : Quay lai." << endl;
							cout << "[2] : Thoat." << endl;
							cout << "Nhap lua chon : " << endl;
							int luachon3;
							cin >> luachon3;
							switch (luachon3) {
							case 1: {
								goto Menu3;
							}
							case 2:
								exit(0);
							}
						}
						else {
							cout << "Khong tim thay!!!" << endl;
							_getch();
							goto Menu6;
						}

					}//het case 4
					
					case 5: {//Tim kiem doc gia theo ho ten

						system("cls");

						int ret = KiemTraHoTenDocGia(DSDG);
						if (ret != -1) {
							cout << "================= Thong Tin Cua Doc Gia Can Tim ==================" << endl;
							XemThongTinCuaMotDocGia(DSDG, ret);
						Menu7:
							_getch();
							cout << "[1] : Quay lai." << endl;
							cout << "[2] : Thoat." << endl;
							cout << "Nhap lua chon : " << endl;
							int luachon3;
							cin >> luachon3;
							switch (luachon3) {
							case 1: {
								goto Menu3;
							}
							case 2:
								exit(0);
							}
						}
						else {
							cout << "Khong tim thay!!!" << endl;
							_getch();
							goto Menu7;
						}

					}//het case 5

					case 6: { // quay lai de dang nhap mat khau moi

						goto MenuChinh;
					}
					default: {
						cout << "Nhap khong dung !!!!" << endl;
						cout << "Nhao lai." << endl;
						_getch();
						system("cls");
						goto Menu3;

					}

					}//het switch

				}//het else

			}//het case 2


//=============================================================================================================================
//**************************************************** T H U      T H U *******************************************************
//=============================================================================================================================

			case 3: { // dang nhap kieu thu thu



			}// het case 3

			default: {

			}


			}//het switch


		}//ket thuc case 1


		case 2: { //dang ky mat khau
			DocDuLieuVaoDSDG(DSDG);
			system("cls");
			DangkyMatKhau(DSDG);
			_getch();
			cout << "[1] : Quay lai dang nhap." << endl;
			cout << "[2] : Thoat." << endl;
			cout << "Nhap lua chon." << endl;
			int luachon1;
			cin >> luachon1;
			switch (luachon1) {
			case 1: {
				goto MenuChinh;
			}
			case 2: {
				exit(0);
			}
			default: {
				goto MenuChinh;
			}

			}

		}//ket thuc case 2

		case 3: { //thoat
			exit(0);
		}

		default: {

		}


		}//ket thuc switch dang nhap
		


		

	system("pause");
	return 0;
}