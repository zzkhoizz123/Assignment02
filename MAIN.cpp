#include"QUAN_LY_DOC_GIA.h"



int main() {

	DanhSachDocGia DS;
	DocDuLieuVaoDanhSach(DS);
	
	int a;

MenuChinh:		// O menu nay minh se them lua chon dang nhap la Quan Ly Doc Gia hay Thu Thu 
				// thuat toan do can suy nghi them.
	system("cls");
	cout << "********************************************************************" << endl;
	cout << "-------------------- PHAN MEM QUAN LY THU VIEN ---------------------" << endl;
	cout << "********************************************************************" << endl;

	cout << endl;
	cout << "De lam viec voi phan mem xin vui long lam theo cac yeu cau ben duoi !!!!!" << endl;

	cout << "LUU Y: De thuc hien cac lenh can lam. Hay nhap cac  ky tu o dau moi dong trong cac menu lenh." << endl;
	cout << endl;

	cout << "-----------------------------MENU Chinh------------------------------" << endl;
	cout << "[1] : Quan ly doc gia." << endl;

	cout << "Nhap vao chuc nang." << endl;
	cin >> a;

	switch (a) {
	case 1: {
	Menu1:	//Menu quan ly nguoi dung 
			//Menu cua Quan ly nguoi dung
		cout << "------------------------MENU Quan Ly Doc Gia------------------------------" << endl;
		cout << "[1] : Xem danh sach doc gia trong thu vien."	<< endl;
		cout << "[2] : Them doc gia."							<< endl;
		cout << "[3] : Chinh sua thong tin mot doc gia."		<< endl;
		cout << "[4] : Xoa thong tin mot doc gia."				<< endl;
		cout << "[5] : Tim kiem danh sach doc gia theo cmnd"	<< endl;
		cout << "[6] : Tim kiem doc gia theo ho ten."			<< endl;
		cout << "[7] : Quay lai Menu chinh. "					<< endl;
		int chucnang;
		cout << "Chon chu nang." << endl;
		cin >> chucnang;

		switch (chucnang) {
		case 1: {	// xem danh sach doc gia
			system("cls");
			XuatDanhSachDocGia(DS);
			_getch();
			goto Menu1;
		}
		case 2: {	//them doc gia
			system("cls");
			NhapDanhSachDocGia(DS);
			_getch();
			goto Menu1;
		}
		case 3: {	//chinh sua thong tin doc gia
				//LUU Y : trong case 3 nay can co them mot menu nua de sua tung loai thong tin!!!
				//VD: case 1: sua MaDocGia
				//case 2: sua HoTen ...vv

			cout << "========================CHUC NANG CHINH SUA THONG TIN DOC GIA=========================" << endl;

			int q = KiemTraMaSoDocGia(DS);

			if (q == -1) { // khong tim thay ma so doc gia trong thu vien
				cout << "Khong cos MSDG can tim !!!"		<< endl;
				cout << "Nhan Enter de chon chuc nang:"		<< endl;
				_getch();
				system("cls");
				cout << "[1] : Tro lai Menu quan ly Doc Gia."				<< endl;
				cout << "[2] : Thoat khoi chuong trinh."	<< endl;
				cout << "Nhap chuc nang."					<< endl;
				int chucnang2;
				cin >> chucnang2;
				if (chucnang2 == 1) {
					goto Menu1;
				}
				else
					exit(0);
			}
			else { // co tim thay ma so doc gia trong thu vien
				system("cls");
			Menu3:
				cout << "==========================CHUC NANG CHINH SUA THONG TIN DOC GIA=========================" << endl;
				cout << "[1] : Chinh sua ma so."		<< endl;
				cout << "[2] : Chinh sua ho ten."		<< endl;
				cout << "[3] : Chinh sua gioi tinh."	<< endl;
				cout << "[4] : Chinh sua email."		<< endl;
				cout << "[5] : Chinh sua dia chi."		<< endl;
				cout << "[6] : Quay lai MENU quan ly Doc Gia." << endl;
				cout << "Nhap vao chuc nang."			<< endl;
				int chucnang3;
				cin >> chucnang3;
				
				switch (chucnang3) {

				case 1: {
					//*** chuc nang chinh sua ma so doc gia 
						// Nhan vao ma so doc gia moi *****

					system("cls");
					cin.ignore(INT_MAX, '\n');
					cout << "Nhap vao ma so moi." << endl;
					cin.getline(DS.MangChuaDocGia[q].MaDocGia, 10);

					LuuDanhSachDocGiaVaoTepTin(DS);

					cout << "Chinh sua thanh cong !!!" << endl;
					_getch();
					system("cls");
					cout << "[1] : Tro lai Menu chinh sua thong tin Doc Gia." << endl;
					cout << "[2] : Thoat khoi chuong trinh." << endl;
					cout << "Nhap vao chuc nang." << endl;
					int chucnang2;
					cin >> chucnang2;
					if (chucnang2 == 1) {
						goto Menu3;
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
					cin.getline(DS.MangChuaDocGia[q].HoTen, 40);

					LuuDanhSachDocGiaVaoTepTin(DS);

					cout << "Chinh sua thanh cong !!!" << endl;
					_getch();
					system("cls");
					cout << "[1] : Tro lai Menu chinh sua thong tin Doc Gia." << endl;
					cout << "[2] : Thoat khoi chuong trinh." << endl;
					cout << "Nhap vao chuc nang." << endl;
					int chucnang2;
					cin >> chucnang2;
					if (chucnang2 == 1) {
						goto Menu3;
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
					cin.getline(DS.MangChuaDocGia[q].GioiTinh, 10);

					LuuDanhSachDocGiaVaoTepTin(DS);

					cout << "Chinh sua thanh cong !!!" << endl;
					_getch();
					system("cls");
					cout << "[1] : Tro lai Menu chinh sua thong tin Doc Gia." << endl;
					cout << "[2] : Thoat khoi chuong trinh." << endl;
					cout << "Nhap vao chuc nang." << endl;
					int chucnang2;
					cin >> chucnang2;
					if (chucnang2 == 1) {
						goto Menu3;
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
					cin.getline(DS.MangChuaDocGia[q].Email, 50);

					LuuDanhSachDocGiaVaoTepTin(DS);

					cout << "Chinh sua thanh cong. " << endl;

					_getch();
					system("cls");
					cout << "[1] : Tro lai Menu chinh sua thong tin Doc Gia." << endl;
					cout << "[2] : Thoat khoi chuong trinh." << endl;
					cout << "Nhap vao chuc nang." << endl;
					int chucnang2;
					cin >> chucnang2;
					if (chucnang2 == 1) {
						goto Menu3;
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
					cin.getline(DS.MangChuaDocGia[q].DiaChi, 50);

					LuuDanhSachDocGiaVaoTepTin(DS);

					cout << "Chinh sua thanh cong. " << endl;
					_getch();
					system("cls");
					cout << "[1] : Tro lai Menu chinh sua thong tin Doc Gia." << endl;
					cout << "[2] : Thoat khoi chuong trinh." << endl;
					cout << "Nhap vao chuc nang." << endl;
					int chucnang2;
					cin >> chucnang2;
					if (chucnang2 == 1) {
						goto Menu3;
					}
					else
						exit(0);
				}
				case 6: {
					// ********Tro lai MENU quan ly doc gia*********
					goto Menu1;
				}
				default: {
					system("cls");
					cout << "Khong co chuc nang nay." << endl;
					_getch();
					goto Menu3;
				}

				}//ket thuc switch
			}//ket thuc else 

		}//ket thuc case3



		case 4: {	//xoa thong tin mot doc gia
				
			system("cls");
			int q = KiemTraMaSoDocGia(DS);
			if (q == -1) {
				system("cls");
				cout << "Khong ton tai doc gia!!!" << endl;
				_getch();
				goto Menu1;
			}
			else {
				DS.n = DS.n - 1;

				for (int i = q; i < DS.n; i++) {
					strcpy_s(DS.MangChuaDocGia[i].MaDocGia,DS.MangChuaDocGia[i + 1].MaDocGia);
					strcpy_s(DS.MangChuaDocGia[i].HoTen, DS.MangChuaDocGia[i + 1].HoTen);
					strcpy_s(DS.MangChuaDocGia[i].GioiTinh, DS.MangChuaDocGia[i + 1].GioiTinh);
					strcpy_s(DS.MangChuaDocGia[i].Email, DS.MangChuaDocGia[i + 1].Email);
					strcpy_s(DS.MangChuaDocGia[i].DiaChi, DS.MangChuaDocGia[i + 1].DiaChi);

				}//ket thuc vong lap for

				LuuDanhSachDocGiaVaoTepTin(DS);
				system("cls");
				cout << "Xoa thanh cong." << endl;
				_getch();
				goto Menu1;

			}//ket thuc else

		}//ket thuc case4



		case 5: {	//tim kiem doc gia bang CMND

		}
		case 6: {	//tim kiem doc gia theo hoc ten

		}
		case 7: {	// quay lai menu chinh

			goto MenuChinh;
		}
		default: {
			system("cls");
			cout << "Khong co chuc nang nay!!!" << endl;
			goto Menu1;
		}

		}

		}// ket thuc case 1 cua quan ly doc gia




	}







	system("pause");
	return 0;
}