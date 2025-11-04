#include <iostream>
using namespace std;

// ===============================================
// NOTE: Em chưa biết dùng stack nên dùng cách cơ bản này để thay thế cho stack
// ===============================================


// Hàm mã hóa chuỗi
string maHoaChuoi(const string s) {
    string result = "";
    int n = s.length();

    // Chạy qua từng ký tự trong chuỗi
    for (int i = 0; i < n; i++) {
        char kytu = s[i];
        int dem = 1;

        // Chạy vòng lặp và kiểm tra điều kiện để đếm số lần lặp lại của ký tự
        while (true) {
            if (i + 1 >= n || s[i + 1] != kytu) {
                break;
            }
            dem++;
            i++;
        }

        // Thêm ký tự và số lần vào chuỗi kết quả
        result += kytu;
        result += to_string(dem);
    }

    return result;
}

int main() {
    string s;
    cout << "Nhap chuoi: ";
    cin >> s;

    cout << "Chuoi ma hoa: " << maHoaChuoi(s) << endl;
    return 0;
}
