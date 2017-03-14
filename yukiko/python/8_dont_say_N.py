class Yukicoder:
    def __init__(self):
        self.p = int(input())

    def run(self):
        for i in range(self.p):
            n,k = map(int, input().split())
            if k < n and n % (k + 1) == 1:
                print("Lose")
            else:
                print("Win")

y = Yukicoder()
y.run()
