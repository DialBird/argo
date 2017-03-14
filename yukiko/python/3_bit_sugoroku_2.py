class Yukicoder:
    def __init__(self):
        self.n = int(input())

    def run(self):
        visited = set([])
        queue = [1]
        cnt = 0
        while len(queue) != 0:
            cnt += 1

            new_queue = []
            for q in queue:
                if q == self.n:
                    return cnt
                step = bin(q).count('1')
                for i in [-1, 1]:
                    next_pos = q + step*i
                    if 0 < next_pos and next_pos <= self.n and next_pos not in visited:
                        visited.add(next_pos)
                        new_queue.append(next_pos)
            queue = new_queue
        return -1

y = Yukicoder()
print(y.run())
