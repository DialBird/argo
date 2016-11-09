
n,m = 6,6
MAX_N, MAX_M = 1000,1000
@s,@t = "abcdcc","becccd"
@res = ""
@count = 0
@dp = Array.new(n+1) { Array.new(m+1, 0) }

def solve(n,m)
  (0...n).each do |i|
    (0...m).each do |j|
      if @s[i] == @t[j]
        @dp[i+1][j+1] = @dp[i][j] + 1
      else
        @dp[i+1][j+1] = [@dp[i+1][j], @dp[i][j+1]].max
      end
    end
  end
end

solve(n,m)
p @dp[n][m]
p @dp
