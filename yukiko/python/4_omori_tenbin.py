class Yukicoder:
    def __init__(self):
        _ = int(input())
        self.w_list = [int(i) for i in input().split()]

    def run(self):
        total = sum(self.w_list)
        if total & 1: return "impossible"

        half = total >> 1
        dp = set([0])
        for w in self.w_list:
            new_dp = set(dp)
            for i in dp:
                t = i + w
                if t == half:
                    return "possible"
                new_dp.add(t)
            dp = new_dp

        return "impossible"

y = Yukicoder()
print(y.run())
