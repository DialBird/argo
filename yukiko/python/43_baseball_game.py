N = int(input())
score_board = [0]*N
results = []
candidate_orders = set([])

def calc():
    point = score_board[0]
    sort_borad = sorted(score_board)
    cnt = 1
    for i in sort_borad:
        if point < i:
            cnt += 1
            point = i
    candidate_orders.add(cnt)

def check(x, y):
    if x == N:
        y += 1
        if y == N:
            return calc()
        x = y
    if results[y][x] == '#':
        check(x + 1, y)
    elif results[y][x] == 'o':
        score_board[y] += 1
        check(x + 1, y)
        score_board[y] -= 1
    elif results[y][x] == 'x':
        score_board[x] += 1
        check(x + 1, y)
        score_board[x] -= 1
    elif results[y][x] == '-':
        score_board[x] += 1
        check(x + 1, y)
        score_board[x] -= 1
        score_board[y] += 1
        check(x + 1, y)
        score_board[y] -= 1

for i in range(N):
    row = list(input())
    results.append(row)

check(0,0)

print(min(candidate_orders))
