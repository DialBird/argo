class Yukicoder
  def initialize
    @k = gets.to_i
    @dp = Array.new(25, 0)
  end

  def run
    @dp[@k] = 0
    @dp[@k - 1] = 1

    (@k - 2).downto(0) do |i|
      (1..6).each do |j|
        @dp[i] += @dp[i + j]/6r
      end
      @dp[i] += 1
    end

    return @dp[0].to_f
  end
end

puts Yukicoder.new.run
