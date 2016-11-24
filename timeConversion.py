import sys
time = input().strip()
lst=time.split(":")
x=int(lst[0])
if((lst[2][2])=='P'):
    if(x!=12):
        x=x+12
        lst[0]=str(x)
        print(lst[0]+time[2:8])
    else:
        print(lst[0]+time[2:8])
else:
    if(x==12):
        x=(x+12)%24
        lst[0]=str(x)
        print(str(0)+lst[0]+time[2:8])
    else:
        print(lst[0]+time[2:8])
