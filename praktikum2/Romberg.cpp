#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Fungsi contoh
double f(double x) {
    return exp(-x * x);
}

// Metode Trapezoidal
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));

    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }

    return sum * h;
}

// Metode Integrasi Romberg
double romberg(double a, double b, int maxIterations) {
    double R[maxIterations + 1][maxIterations + 1];

    // Langkah pertama: hitung R[0][0]
    R[0][0] = trapezoidal(a, b, 1);

    for (int i = 1; i <= maxIterations; i++) {
        // Hitung R[i][0] dengan trapezoidal
        R[i][0] = trapezoidal(a, b, pow(2, i));

        // Hitung R[i][j] untuk j = 1 hingga i
        for (int j = 1; j <= i; j++) {
            R[i][j] = (pow(4, j) * R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j) - 1);
        }
    }

    // Hasil akhir :
    return R[maxIterations][maxIterations];
}

int main() {
    double a, b;
    int maxIterations;

    cout << "fungsi sebagai contoh yakni : e^(-x^2)\n";
    cout << "Masukkan batas bawah (a): ";
    cin >> a;
    cout << "Masukkan batas atas (b): ";
    cin >> b;
    cout << "Masukkan jumlah iterasi maksimum (misalnya 4 atau 5): ";
    cin >> maxIterations;

    // Untuk pembandingan, hitung trapezoidal dengan interval 2^maxIterations (jumlah interval besar)
    int n = (int)pow(2, maxIterations);

    double trapezoid_result = trapezoidal(a, b, n);
    double romberg_result = romberg(a, b, maxIterations);

    cout << fixed << setprecision(8);
    cout << "\nHasil integrasi menggunakan Metode Trapezoidal dengan n = " << n << " interval: " << trapezoid_result << endl;
    cout << "Hasil integrasi menggunakan Metode Romberg dengan maxIteration = " << maxIterations << ": " << romberg_result << endl;

    cout << "\nKesimpulan: " << endl;
    cout << "- Metode Romberg memberikan hasil yang lebih akurat dengan jumlah iterasi yang relatif kecil." << endl;
    cout << "- Metode Trapezoidal membutuhkan jumlah interval yang besar (dalam contoh n = " << n << ") untuk mendekati akurasi yang sama." << endl;
    cout << "- Dengan Romberg, akurasi meningkat lebih cepat dan efisien mengatasi kelemahan Trapezoidal." << endl;

    return 0;
}

