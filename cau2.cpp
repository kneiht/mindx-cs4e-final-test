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


// Lớp Hanhkhach kế thừa từ Nguoi
class Hanhkhach : public Nguoi {
private:
    // Em không dùng con trỏ như đề bài vì chưa rành lắm nên dùng mảng
    Vemaybay ve[100];
    int soluong;
    
public:
    // Hàm tạo mặc định
    Hanhkhach() : Nguoi() {
        soluong = 0;
    }
    
    // Hàm hủy
    ~Hanhkhach() {}
    
    // Hàm nhập
    void Nhap() {
        // Nhập thông tin người
        Nguoi::Nhap();
        
        // Nhập số lượng vé
        cout << "Nhap so luong ve: ";
        cin >> soluong;
        
        // Nhập thông tin từng vé
        for (int i = 0; i < soluong; i++) {
            cout << "- Nhap thong tin ve thu " << i + 1 << endl;
            ve[i].Nhap();
        }
    }
    
    // Hàm xuất
    void Xuat() {
        // Xuất thông tin người
        Nguoi::Xuat();
        
        // Xuất vé
        cout << "So luong ve: " << soluong << endl;
        for (int i = 0; i < soluong; i++) {
            cout << "- Ve " << i + 1 << ": ";
            ve[i].Xuat();
        }
    }
    
    // Hàm tính tổng số tiền phải trả
    long tongtien() {
        long tong = 0;
        
        // Chạy for để tính tổng giá vé
        for (int i = 0; i < soluong; i++) {
            tong = tong + ve[i].getgiave();
        }
        
        return tong;
    }
};


int main() {
    Hanhkhach hanhkhach;
    hanhkhach.Nhap();
    cout << endl;
    
    hanhkhach.Xuat();
    cout << "Tong tien phai tra: " << hanhkhach.tongtien() << endl;
    
    return 0;
}