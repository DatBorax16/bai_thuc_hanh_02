#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

class phuong_tien {
private:
    int ma_xe;
    string loai_xe;
    int gio_vao;
    int tg_do;

public:
    phuong_tien();
    phuong_tien(int ma, string loai, int gio, int tg);

    int lay_ma_xe() const;
    string lay_loai_xe() const;
    double tinh_phi() const;
    void hien_thi() const;
};

phuong_tien::phuong_tien() : ma_xe(0), loai_xe(""), gio_vao(0), tg_do(0) {}

phuong_tien::phuong_tien(int ma, string loai, int gio, int tg)
    : ma_xe(ma), loai_xe(loai), gio_vao(gio), tg_do(tg) {}

int phuong_tien::lay_ma_xe() const { return ma_xe; }
string phuong_tien::lay_loai_xe() const { return loai_xe; }

double phuong_tien::tinh_phi() const {
    double gia = (loai_xe == "Car") ? 6.0 : (loai_xe == "Motorcycle") ? 4.0 : 2.0;
    bool cao_diem = (gio_vao >= 6 && gio_vao <= 9) || (gio_vao >= 15 && gio_vao <= 18);
    double tong = 0;
    for (int h = 0; h < tg_do; ++h) {
        if (h < 2) tong += gia * (cao_diem ? 1.30 : 0.95);
        else       tong += gia * 0.90;
    }
    return tong;
}

void phuong_tien::hien_thi() const {
    cout << "  ID: " << ma_xe << " | " << loai_xe
         << " | " << gio_vao << "h | " << tg_do << "h"
         << " | Phi: $" << fixed << setprecision(2) << tinh_phi() << "\n";
}

class bai_xe {
private:
    int ma_bai;
    char kich_thuoc;
    static const int so_xe_toi_da = 3;
    phuong_tien phuong_Tien[so_xe_toi_da];
	int so_xe_dang_do;
public:
    bai_xe();
    bai_xe(int ma, char kt);

	bool isFull() const;
	
    int lay_ma() const;
    bool them(phuong_tien v);
    bool xoa(int ma_xe);
    int tim_xe(int ma_xe);
    bool chua(int ma_xe) const;
    int check() const;
    void hien_thi() const;
    void tim_loai_xe(string loai);
    bool co_loai_c(int& demC, double& tongC) const;
    bool co_loai_m(int& demM, double& tongM) const;
    bool co_loai_b(int& demB, double& tongB) const;
};
bai_xe::bai_xe() : ma_bai(0), kich_thuoc('S'), so_xe_dang_do(0) {}

bai_xe::bai_xe(int ma, char kt) : ma_bai(ma), kich_thuoc(kt), so_xe_dang_do(0) {}

int bai_xe::lay_ma() const { return ma_bai; }


bool bai_xe::isFull() const {
	int cap = (kich_thuoc == 'S') ? 1 : (kich_thuoc == 'M') ? 2 : 3;
	if(so_xe_dang_do == cap) {
		return true;
	}
	else {
		return false;
	}
}

bool bai_xe::them(phuong_tien v) {
    if(!isFull()) {
		phuong_Tien[so_xe_dang_do] = v;
		so_xe_dang_do += 1; 
		return true;   	
	}
    return false;
}

bool bai_xe::xoa(int ma) {
    for(int i = 0; i < so_xe_dang_do; i++) {
    	if(phuong_Tien[i].lay_ma_xe() == ma) {
    		for(int j = i; j < so_xe_dang_do - 1; j++) {
    			phuong_Tien[j] = phuong_Tien[j + 1];
			}
			so_xe_dang_do -=1;
			return true;
		}
	}
	return false;
}
int bai_xe::tim_xe(int ma) {
	for(int i = 0; i < so_xe_dang_do; i++) {
		if(phuong_Tien[i].lay_ma_xe() == ma) {
			return i;
		}
	}
	return -1;
}

void bai_xe::tim_loai_xe(string loai) {
	for(int i = 0; i < so_xe_dang_do; i++) {
		if(phuong_Tien[i].lay_loai_xe() == loai) {
			phuong_Tien[i].hien_thi();
		}
	}
}
 
bool bai_xe::chua(int ma) const {
    for(int i = 0; i < so_xe_dang_do; i++) {
    	if(phuong_Tien[i].lay_ma_xe() == ma) {
    		return true;
		}
	}
    return false;
}

void bai_xe::hien_thi() const {
    int cap = (kich_thuoc == 'S') ? 1 : (kich_thuoc == 'M') ? 2 : 3;
    cout << "Bai " << ma_bai << " [" << kich_thuoc << "] "
         << so_xe_dang_do << "/" << cap << " xe\n";
	for(int i = 0; i < so_xe_dang_do; i++) {
		phuong_Tien[i].hien_thi();
	}
}

bool bai_xe::co_loai_c(int& demC, double& tongC) const {
	for(int i = 0; i < so_xe_dang_do; i++) {
		if(phuong_Tien[i].lay_loai_xe() == "Car") {
			demC++;
			tongC += phuong_Tien[i].tinh_phi();
		}
	}
	if(demC > 0) return true;
	else return false;
}
bool bai_xe::co_loai_m(int& demM, double& tongM) const {
	for(int i = 0; i < so_xe_dang_do; i++) {
		if(phuong_Tien[i].lay_loai_xe() == "Motorcycle") {
			demM++;
			tongM += phuong_Tien[i].tinh_phi();
		}
	}
	if(demM > 0) return true;
	else return false;
}
bool bai_xe::co_loai_b(int& demB, double& tongB) const {
	for(int i = 0; i < so_xe_dang_do; i++) {
		if(phuong_Tien[i].lay_loai_xe() == "Bicycle") {
			demB++;
			tongB += phuong_Tien[i].tinh_phi();
		}
	}
	if(demB > 0) return true;
	else return false;
}

class SystemInterface {
private:
    static const int bai_xe_max = 10;   
   	bai_xe bai_Xe[bai_xe_max]; 
   	int so_bai_dang_co;
public:
    SystemInterface();
    void runMenu();
    bool checkMaBai(int ma);
    bool checkMaXe(int ma);
    int randomID();
    int checkHopLe(int ma);
};

SystemInterface::SystemInterface() : so_bai_dang_co(0) {}
bool SystemInterface::checkMaBai(int ma) {
	int cnt = 0;
	for(int i = 0; i < so_bai_dang_co; i++) {
		if(bai_Xe[i].lay_ma() == ma) {
			cnt++;
		}
		if(cnt >= 2) return true;
	}
	return false;
}
bool SystemInterface::checkMaXe(int ma) {
	for(int i = 0; i < so_bai_dang_co; i++) {
		if(bai_Xe[i].chua(ma)) return true;
	} 
	return false;
}
int SystemInterface::randomID() {
	int x = rand();
	return x;
}
int SystemInterface::checkHopLe(int ma) {
	while(true) {
    	cin >> ma;
    	if(cin.fail()) {
        	cin.clear();
        	cin.ignore(10000, '\n');
        	cout << "Du lieu khong hop le, vui long nhap lai!" << endl;
			}
		else {
			return ma;
			break;
		}
	}
}
void SystemInterface::runMenu() {
    int chon;
    do {
        cout << "\n===== QUAN LY BAI DO XE =====\n";
        cout << "1. Tao bai do\n";
        cout << "2. Them xe\n";
        cout << "3. Xoa bai do\n";
        cout << "4. Lay xe ra\n";
        cout << "5. Hien thi tat ca bai do\n";
        cout << "6. Hien thi xe theo bai\n";
        cout << "7. Liet ke xe theo loai\n";
        cout << "8. Bao cao phi trung binh\n";
        cout << "9. Thoat\n";
        cout << "Chon: ";
        cin >> chon;
		switch(chon) {
        case 1: {
        	if(so_bai_dang_co < 10) {
        		int ma;
        		char kt;
        		cout << "Nhap ma bai: ";
				ma = checkHopLe(ma);
        		if(checkMaBai(ma)) {
        			cout << "Ma bai da ton tai, he thong tu dong tao ma bai khac...";
        			ma = randomID();
        			cout << "Ma bai: " << ma << endl;
				}
				cout << "Nhap kich thuoc bai(S/M/L): ";
				cin >> kt;
				bai_xe v(ma, kt);
				bai_Xe[so_bai_dang_co] = v;
				so_bai_dang_co++;
				cout << "Da tao bai xe! - ID: " << ma << " - Size: " << kt << endl;
			}
			break;
		}
        case 2: {
            int ma, gio, tg; string loai;
            cout << "Ma xe: "; 
            ma = checkHopLe(ma);
            if(checkMaXe(ma)) {
        		cout << "Ma xe da ton tai, he thong tu dong tao ma bai khac...";
        		ma = randomID();
        		cout << "Ma xe: " << ma << endl;
			}
            cout << "Loai (Car/Motorcycle/Bicycle): "; cin >> loai;
            cout << "Gio vao (0-23): "; 
            gio = checkHopLe(gio);
            cout << "Thoi luong (1-23): "; 
            tg = checkHopLe(tg);
            phuong_tien v(ma, loai, gio, tg);
            bool ok = false;
			for(int i = 0; i < so_bai_dang_co; i++) {
				if(bai_Xe[i].isFull()) {
					continue;
				}
				else {
					bai_Xe[i].them(v);
					ok = true;
					break;
				}
			}
            if (ok) cout << "Da them xe " << ma << " | Phi: $" << fixed << setprecision(2) << v.tinh_phi() << "\n";
            else    cout << "Tat ca bai da day!\n";
            break;
    	}
        case 3: {
            int ma;
            cout << "Ma bai can xoa: "; 
            ma = checkHopLe(ma);
            for(int i = 0; i < so_bai_dang_co; i++) {
		    	if(bai_Xe[i].lay_ma() == ma) {
		    		for(int j = i; j < so_bai_dang_co - 1; j++) {
		    			bai_Xe[j] = bai_Xe[j + 1];
						}
				so_bai_dang_co -=1;
				break;
				}
			}
			break;
		}
        case 4: { 
            int ma;
            cout << "Ma xe can lay ra: "; 
            ma = checkHopLe(ma);
            bool ok = false;
            for(int i = 0; i < so_bai_dang_co; i++) {
            	if(bai_Xe[i].tim_xe(ma) != -1) {
					bai_Xe[i].xoa(ma);
					ok = true;	
					break;
				}
			}
            cout << (ok ? "Da lay xe ra\n" : "Khong tim thay xe\n");
            break;
        }
        case 5: {
        	for(int i = 0; i < so_bai_dang_co; i++) {
        		bai_Xe[i].hien_thi();
			}
			break;
		}
        case 6: {
            int ma;
            cout << "Ma bai: "; 
            ma = checkHopLe(ma);
            bool ok = false;
            for(int i = 0; i < so_bai_dang_co; i++) {
        		if(bai_Xe[i].lay_ma() == ma) {
        			bai_Xe[i].hien_thi();
        			ok = true;
        			break;
				}
			}
			if(ok == false) cout << ("Khong tim thay bai\n");
			break;
		}
		case 7: {
			string loai;
			cout << "Loai (Car/Motorcycle/Bicycle): ";
			cin >> loai;
			for(int i = 0; i < so_bai_dang_co; i++) {
				bai_Xe[i].tim_loai_xe(loai);
			}
			break; 
		}
		case 8: {
			int demC = 0, demM = 0, demB = 0; 
			bool checkC = false,checkM = false,checkB = false;
			double tongC = 0, tongM = 0, tongB = 0;
			for(int i = 0; i < so_bai_dang_co; i++) {
				if(bai_Xe[i].co_loai_c(demC, tongC)) {
					checkC = true;
				}
				if(bai_Xe[i].co_loai_m(demM, tongM)) {
					checkM = true;
				}
				if(bai_Xe[i].co_loai_b(demB, tongB)) {
					checkB = true;
				}
			}
			if(checkC == false && checkM == false && checkB == false) {
				cout << "khong co xe\n";
			}
			else {
				if(checkC == true) {
					cout << "Car: " << demC << " xe | TB: $" << fixed << setprecision(2) << tongC / demC << "\n";
				}
				if(checkM == true) {
					cout << "Motorcycle: " << demM << " xe | TB: $" << fixed << setprecision(2) << tongM / demM << "\n";
				}
				if(checkB == true) {
					cout << "Bicycle: " << demB << " xe | TB: $" << fixed << setprecision(2) << tongB / demB << "\n";
				}
			}
			break;
		}
        case 9: {
			break;
		}
    	}
    }while (chon != 9);
}

int main() {
    SystemInterface sys;
    sys.runMenu();
    return 0;
}
