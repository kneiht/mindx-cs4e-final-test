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
        cout << "Nhập tên chuyến: ";
        cin.ignore();
        getline(cin, tenchuyen);
        cout << "Nhập ngày bay: ";
        getline(cin, ngaybay);
        cout << "Nhập giá vé: ";
        cin >> giave;
    }
    
    // Hàm xuất
    void Xuat() {
        cout << "Tên chuyến: " << tenchuyen << ", Ngày bay: " << ngaybay 
             << ", Giá vé: " << giave << endl;
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
        cout << "Nhập họ tên: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhập giới tính: ";
        getline(cin, gioitinh);
        cout << "Nhập tuổi: ";
        cin >> tuoi;
    }
    
    // Hàm xuất
    void Xuat() {
        cout << "Họ tên: " << hoten << ", Giới tính: " << gioitinh << ", Tuổi: " << tuoi << endl;
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
        cout << "Nhập số lượng vé: ";
        cin >> soluong;
        
        // Nhập thông tin từng vé
        for (int i = 0; i < soluong; i++) {
            cout << "- Nhập thông tin vé thứ " << i + 1 << endl;
            ve[i].Nhap();
        }
    }
    
    // Hàm xuất
    void Xuat() {
        // Xuất thông tin người
        Nguoi::Xuat();
        
        // Xuất vé
        cout << "Số lượng vé: " << soluong << endl;
        for (int i = 0; i < soluong; i++) {
            cout << "- Vé " << i + 1 << ": ";
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

// Sắp xếp danh sách hành khách theo chiều giảm dần của Tổng tiền.
void sapXepGiamDanTongTien(Hanhkhach danhSach[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (danhSach[j].tongtien() < danhSach[j + 1].tongtien()) {
                Hanhkhach temp = danhSach[j];
                danhSach[j] = danhSach[j + 1];
                danhSach[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Nhập khách hàng
    cout << "\n=== NHẬP THÔNG TIN HÀNH KHÁCH ===" << endl;
    int n;
    cout << "Nhập số lượng hành khách: ";
    cin >> n;
    
    // Tạo mảng chứa n hành khách
    Hanhkhach danhSach[100];
    
    // Nhập thông tin cho từng hành khách
    for (int i = 0; i < n; i++) {
        cout << "\n- Nhập thông tin hành khách thứ " << i + 1 << endl;
        danhSach[i].Nhap();
    }
    
    // Hiển thị hành khách
    cout << "\n=== DANH SÁCH HÀNH KHÁCH ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\n>> Hành khách thứ " << i + 1 << endl;
        danhSach[i].Xuat();
        cout << "=> Tổng tiền phải trả: " << danhSach[i].tongtien() << endl;
    }
    
    
    // Hiển thị danh sách sau khi sắp xếp
    cout << "\n=== DANH SÁCH SAU KHI SẮP XẾP GIẢM DẦN THEO TỔNG TIỀN ===" << endl;
    sapXepGiamDanTongTien(danhSach, n);
    for (int i = 0; i < n; i++) {
        cout << "\n>> Hành khách thứ " << i + 1 << endl;
        danhSach[i].Xuat();
        cout << "=> Tổng tiền phải trả: " << danhSach[i].tongtien() << endl;
    }
    
    return 0;
}