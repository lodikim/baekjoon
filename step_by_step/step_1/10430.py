# 나머지

A, B, C = input().split()
int_A = int(A)
int_B = int(B)
int_C = int(C)
print((int_A+int_B)%int_C)
print(((int_A%int_C) + (int_B%int_C))%int_C)
print((int_A*int_B)%int_C)
print(((int_A%int_C) * (int_B%int_C))%int_C)