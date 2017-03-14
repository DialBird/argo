class Yukicoder
  def initialize
    @n, m = gets.chomp.split.map(&:to_i)
    @points = {}
    m.times do
      a, b, c = gets.chomp.split.map(&:to_i)
      @points[[a, b]] = c
    end
    @dp = {}
  end

  def run
    return solve([], [*0...@n])
  end

  private

  def solve(done, rest)
    @dp[rest.sort!] ||= rest.map do |i|
      sum = 0
      done.each do |j|
        sum += @points[[i, j]] || 0
      end
      sum += solve(done + [i], rest - [i])
    end.max || 0
  end
end

puts Yukicoder.new.run
