# 알람 시계

H, M = map(int, input().split())

if M>=45:
    print(H, M-45)
elif H>0: # M<45
    print(H-1, 60-(45-M))
else: # H==0, M<45
    print(23, 60-(45-M))