class Yukicoder:
    def __init__(self):
        self.n = int(input())

    def run(self):
        dp = set([0,1])
        # ふるい
        prime_checker = [1]*10001
        prime_list = set([])

        for i in range(2, self.n + 1):
            if prime_checker[i] == 1:
                prime_list.add(i)
                for j in range(i*2, 10001, i):
                    prime_checker[j] = 0

            for j in prime_list:
                if (i - j) not in dp:
                    dp.add(i)
                    break

        if self.n in dp:
            return "Win"
        else:
            return "Lose"

y = Yukicoder()
print(y.run())
