# Laporan Praktikum Komputasi Numerik
|    NRP     |      Name      |
| :--------: | :------------: |
| 5025241197 | Syah Amin Zikri            |
| 5025241171 | Muhammad Sholihuddin Rizky |

## Praktikum 1
Anda sudah mengerti algortima pemrosesan metode *Regula Falsi*, dan anda sudah memahami cara kerjanya. Sekarang anda tinggal mengimplementasikan algoritma tersebut menjadi sebuah program komputer metode *Regula Falsi (yang dapat menampilkan proses iteratif numerik, dengan lengkap grafik fungsinya).

### Kode 
Pertama, untuk Regula Falsi ini kami membuat dua program, yang pertama untuk menghitung dan yang kedua untuk membuat grafik visualnya.
``` cpp
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



## Praktikum 2
