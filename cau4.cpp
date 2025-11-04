#include <iostream>
using namespace std;

// ===============================================
// NOTE: Em chưa biết dùng queue nên dùng cách cơ bản này để thay thế cho queue
// ===============================================


// Hàm kiểm tra số nguyên tố
bool soNguyenTo(int so) {
    if (so < 2) return false;
    for (int i = 2; i < so; i++) {
        if (so % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra số siêu nguyên tố
bool soSieuNguyenTo(int so) {
    // Chạy vòng lặp, bỏ dần chữ số cuối và kiểm tra điều kiện
    while (true) {
        if (!soNguyenTo(so)) return false;
        if (so < 10) break;
        so /= 10;
    }
    return true;
}

int main() {
    int n;
    cout << "Nhập n: ";
    cin >> n;
    cout << "Dãy số siêu nguyên tố nhỏ hơn hoặc bằng " << n << " là: " << endl;
    for (int i = 2; i <= n; i++) {
        if (soSieuNguyenTo(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
