# 곱셈

A = input()
B = input()
int_A = int(A)
int_B = int(B)

line3 = int_A * (int_B % 10)
line4 = int_A * ((int_B // 10) % 10)
line5 = int_A * (int_B // 100)
line6 = line3 + (line4*10) + (line5*100)

print(line3)
print(line4)
print(line5)
print(line6)