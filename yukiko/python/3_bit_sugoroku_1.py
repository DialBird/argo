class Yukicoder:
    def __init__(self):
        self.n = int(input())

    def run(self):
        dp = [0 for i in range(10001)]
        dp[1] = 1

        queue = [1]
        while len(queue) != 0:
            new_queue = []
            for q in queue:
                if q == self.n:
                    return dp[q]
                cnt = bin(q).count('1')
                for i in [-1, 1]:
                    next_pos = q + cnt*i
                    if 0 < next_pos and next_pos <= self.n and dp[next_pos] == 0:
                        dp[next_pos] = dp[q] + 1
                        new_queue.append(next_pos)
            queue = new_queue
        return -1

y = Yukicoder()
print(y.run())
