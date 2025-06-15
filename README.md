# Laporan Praktikum Komputasi Numerik
|    NRP     |      Name      |
| :--------: | :------------: |
| 5025241197 | Syah Amin Zikri            |
| 5025241171 | Muhammad Sholihuddin Rizky |

## Praktikum 1
Anda sudah mengerti algortima pemrosesan metode *Regula Falsi*, dan anda sudah memahami cara kerjanya. Sekarang anda tinggal mengimplementasikan algoritma tersebut menjadi sebuah program komputer metode *Regula Falsi (yang dapat menampilkan proses iteratif numerik, dengan lengkap grafik fungsinya).

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

### Gambar grafiknya

## Praktikum 2
Salah satu kelemahan dari metode Trapeziodal adalah kita harus menggunakan jumlah interval yang besar untuk memperoleh akurasi yang diharapkan. Buatlah sebuah program komputer untuk menjelaskan bagaimana metode Integrasi Romberg dapat mengatasi kelemahana tersebut.

### Kode


## Praktikum 2
