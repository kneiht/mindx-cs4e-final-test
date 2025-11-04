#include <iostream>
using namespace std;

// Lớp Vemaybay
class Vemaybay {
private:
    string tenchuyen;
    string ngaybay;
    long giave;
    
public:
    // Hàm tạo
    Vemaybay() {
        tenchuyen = "";
        ngaybay = "";
        giave = 0;
    }
    
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

int main() {
    Vemaybay ve;
    ve.Nhap();
    ve.Xuat();
    return 0;
}