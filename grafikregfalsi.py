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