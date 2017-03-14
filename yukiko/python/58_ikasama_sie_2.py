N = int(input())
K = int(input())

taro_num = [0]*(6*N+1)
jiro_num = [0]*(6*N+1)
taro_num[0] = 1
jiro_num[0] = 1

for i in range(1,N+1):
    new_taro_num = [0]*(6*N+1)
    for j in range(6*N+1):
        if i <= K:
            for s in range(4,7):
                if j-s >= 0:
                    new_taro_num[j] += taro_num[j-s] / 3
        else:
            for s in range(1,7):
                if j-s >= 0:
                    new_taro_num[j] += taro_num[j-s] / 6
    taro_num = new_taro_num

    new_jiro_num = [0]*(6*N+1)
    for j in range(6*N+1):
        for s in range(1,7):
            if j-s >= 0:
                new_jiro_num[j] += jiro_num[j-s] / 6
    jiro_num = new_jiro_num

result = 0
for i in range(0,6*N):
    for j in range(i+1, 6*N+1):
        result += jiro_num[i] * taro_num[j]

print(result)
