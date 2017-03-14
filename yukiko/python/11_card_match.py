W = int(input())
H = int(input())
N = int(input())

w_set = set([])
h_set = set([])

for i in range(N):
    s,k = map(int, input().split())
    w_set.add(s)
    h_set.add(k)

not_used_w_cnt = W - len(w_set)
not_used_h_cnt = H - len(h_set)

ans = (W*H) - (not_used_w_cnt * not_used_h_cnt) - N
print(ans)
