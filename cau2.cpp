#include <iostream>
using namespace std;

// Lớp Vemaybay
class Vemaybay {
private:
    string tenchuyen;
    string ngaybay;
    long giave;
    
public:
    // Hàm tạo mặc định
    Vemaybay() {
        tenchuyen = "";
        ngaybay = "";
        giave = 0;
    }
    
    // Hàm tạo có tham số
    Vemaybay(string ten, string ngay, long gia) {
        tenchuyen = ten;
        ngaybay = ngay;
        giave = gia;
    }
    
    // Hàm hủy 
    ~Vemaybay() {}
    
    // Hàm nhập
    void Nhap() {
        cout << "Nhap ten chuyen: ";
        cin.ignore();
        getline(cin, tenchuyen);
        cout << "Nhap ngay bay: ";
        getline(cin, ngaybay);
        cout << "Nhap gia ve: ";
        cin >> giave;
    }
    
    // Hàm xuất
    void Xuat() {
        cout << "Ten chuyen: " << tenchuyen << ", Ngay bay: " << ngaybay 
             << ", Gia ve: " << giave << endl;
    }
    
    // Hàm trả về giá vé
    long getgiave() {
        return giave;
    }
};


// Lớp Nguoi
class Nguoi {
protected:
    string hoten;
    string gioitinh;
    int tuoi;
    
public:
    // Hàm tạo mặc định
    Nguoi() {
        hoten = "";
        gioitinh = "";
        tuoi = 0;
    }
    
    // Hàm tạo có tham số
    Nguoi(string ten, string gt, int t) {
        hoten = ten;
        gioitinh = gt;
        tuoi = t;
    }
    
    // Hàm hủy
    ~Nguoi() {}
    
    // Hàm nhập
    void Nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap gioi tinh: ";
        getline(cin, gioitinh);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }
    
    // Hàm xuất
    void Xuat() {
        cout << "Ho ten: " << hoten << ", Gioi tinh: " << gioitinh << ", Tuoi: " << tuoi << endl;
    }
};
    

int main() {
    Vemaybay ve;
    ve.Nhap();
    ve.Xuat();

    Nguoi nguoi;
    nguoi.Nhap();
    nguoi.Xuat();
    return 0;
    
}