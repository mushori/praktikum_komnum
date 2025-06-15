# Laporan Praktikum Komputasi Numerik
|    NRP     |      Name      |
| :--------: | :------------: |
| 5025241197 | Syah Amin Zikri            |
| 5025241171 | Muhammad Sholihuddin Rizky |

## Praktikum 1
Anda sudah mengerti algortima pemrosesan metode *Regula Falsi*, dan anda sudah memahami cara kerjanya. Sekarang anda tinggal mengimplementasikan algoritma tersebut menjadi sebuah program komputer metode *Regula Falsi* (yang dapat menampilkan proses iteratif numerik, dengan lengkap grafik fungsinya).

### Kode 
Pertama, untuk Regula Falsi ini kami membuat dua program, yang pertama untuk menghitung dan yang kedua untuk membuat grafik visualnya. 
```cpp
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
//biar ga std std an

double f(double x){
    return pow(x,3)+ x-1;

}
//rumus f(x)

void regulafalsi(double a, double b, double tol, int maxiterasi){
    if (f(a)*f(b) >= 0){
        cout<< "FUNGSI TIDAK MEMENUHI SYARAT RGULA FALSI"<< endl;
        return;

    }
    
    double c;
    cout<< fixed<< setprecision(6);
    cout<< "iterasi\t" << "a\t\t" << "b\t\t" << "c\t\t" << "f(c)\t\t" << endl;

    for (int i=1 ; i<= maxiterasi; i++){
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        cout << i << "\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << "\n";

        if (fabs(f(c)) < tol)
            break;
        if (f(a) * f(c) < 0) b = c;
        else a = c;
    }

    cout<<"\nAkar hampiran: "<<c <<"\n";


}
//ini fungsi yg penting yaitu regula falsinya sendiri


int main (){
    double a, b, tol;
    int IterasiMAX;

    cout << "Masukkan batas bawah (a): ";
    cin >> a;
    cout << "Masukkan batas atas (b): ";
    cin >> b;
    cout << "Masukkan toleransi error: ";
    cin >> tol;
    cout << "Masukkan iterasi maksimum: ";
    cin >> IterasiMAX;

    regulafalsi(a, b, tol, IterasiMAX);
    return 0;
}

// Implementasi metode Regula Falsi untuk mencari akar dari fungsi non-linear
// Ditambah dengan proses iteratif numerik dan akan dilengkapi dengan visualisasi grafik menggunakan media terpisah.
```
Nanti dari kode diatas contoh kita akan memasukkan batas atas (a) = 0, batas bawahnya (b) = 1, kemudian toleransi errornya 0.0001 dan untuk iterasi maksimumnya = 20. Nanti output yang dihasilkan akan seperti ini,
```cpp
Masukkan batas bawah (a): 0
Masukkan batas atas (b): 1
Masukkan toleransi error: 0.0001
Masukkan iterasi maksimum: 20
iterasi a               b               c               f(c)
1       0.000000        1.000000        0.500000        -0.375000
2       0.500000        1.000000        0.636364        -0.105935
3       0.636364        1.000000        0.671196        -0.026428
4       0.671196        1.000000        0.679662        -0.006375
5       0.679662        1.000000        0.681691        -0.001525
6       0.681691        1.000000        0.682176        -0.000364
7       0.682176        1.000000        0.682292        -0.000087

Akar hampiran: 0.682292
```
Naahh! setelah kita mendapatkan outputnya, kita bisa mengetahui kalao *Akar hampirannya* = `0.682292`. Akar hampirannya itu kita akan masukkan ke program selanjutnya dengan bahasa pyhton, agar nanti bisa generate sebuah grafik.
```python
# install dulu masukan ini ke terminal: "python -m pip install numpy matplotlib"
import numpy as np
import matplotlib.pyplot as plt

#f(x) yang dipake
def f(x):
    return x**3 + x - 1

#nah yang tadi di cpp masukin lagi hasil akhirannya ke sini
akar = float(input("msukkan hasil akar dari program C++ tadi: "))
x = np.linspace(-2, 2, 400)
y = f(x)
plt.figure(figsize=(8,6))
plt.plot(x, y, label='f(x) = x³ + x - 1', color='blue')
plt.axhline(0, color='black', linewidth=1)
plt.axvline(0, color='black', linewidth=1)

plt.plot(akar, f(akar), 'ro', label=f'Akar Hampiran ({akar})')

plt.title("Grafik Fungsi f(x) = x³ + x - 1")
plt.xlabel("x")
plt.ylabel("f(x)")
plt.grid(True)
plt.legend()
plt.show()
```
Kemudian di run, nanti akan muncul `msukkan hasil akar dari program C++ tadi: `, kita bisa masukan nilai `0.682292` tadi ke situ, kemudian di-enter, nanti akan muncul sebuah grafik seperti ini,

![image.png](https://github.com/mushori/praktikum_komnum/blob/main/image.png)

---
## Praktikum 2
Salah satu kelemahan dari metode Trapeziodal adalah kita harus menggunakan jumlah interval yang besar untuk memperoleh akurasi yang diharapkan. Buatlah sebuah program komputer untuk menjelaskan bagaimana metode Integrasi Romberg dapat mengatasi kelemahana tersebut.

### Kode
Romberg ini hanya membutuhkan satu program untuk mengatasi dan membuat kesimpulan.
```cpp
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
```
Ketika dirun dan misal kita memasukkan angka batas ataa (a) = 1, batas bawahnya (b) = 2, dan jumlah iterasi maksimumnya = 5. Maka akan menghasilkan output seperti ini,
```cpp
fungsi sebagai contoh yakni : e^(-x^2)
Masukkan batas bawah (a): 1
Masukkan batas atas (b): 2
Masukkan jumlah iterasi maksimum (misalnya 4 atau 5): 5

Hasil integrasi menggunakan Metode Trapezoidal dengan n = 32 interval: 0.13531117
Hasil integrasi menggunakan Metode Romberg dengan maxIteration = 5: 0.13525726 

Kesimpulan:
- Metode Romberg memberikan hasil yang lebih akurat dengan jumlah iterasi yang relatif kecil.
- Metode Trapezoidal membutuhkan jumlah interval yang besar (dalam contoh n = 32) untuk mendekati akurasi yang sama.
- Dengan Romberg, akurasi meningkat lebih cepat dan efisien mengatasi kelemahan Trapezoidal.
```
Dan dari hal tersebut kita bisa langsung mendapatkan sebuah kesimpulan seperti yang disebutkan di dalam output programnya,
1. Metode Romberg memberikan hasil yang lebih akurat dengan jumlah iterasi yang relatif kecil.
2. Metode Trapezoidal membutuhkan jumlah interval yang besar (dalam contoh n = 32) untuk mendekati akurasi yang sama.
3. Dengan Romberg, akurasi meningkat lebih cepat dan efisien mengatasi kelemahan Trapezoidal.

Cukup sekian dari kami, kurang lebihnya mohon maaf, terima kasih!👋

