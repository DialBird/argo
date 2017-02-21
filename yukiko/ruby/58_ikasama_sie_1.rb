class Yukicoder
  def initialize
    @n = gets.to_i
    @k = gets.to_i
    @taro_dp = Array.new(@n + 1) { Array.new(@n * 6 + 1, 0) }
    @jiro_dp = Array.new(@n + 1) { Array.new(@n * 6 + 1, 0) }
  end

  def run
    @taro_dp[0][0] = 1
    @jiro_dp[0][0] = 1

    1.upto(@n) do |i|
      (1..6*@n).each do |j|
        if i <= @k
          (4..6).each do |k|
            @taro_dp[i][j] += @taro_dp[i-1][j-k] / 3r
          end
        else
          (1..6).each do |k|
            @taro_dp[i][j] += @taro_dp[i-1][j-k] / 6r
          end
        end
      end
    end

    1.upto(@n) do |i|
      (1..6*@n).each do |j|
        (1..6).each do |k|
          @jiro_dp[i][j] += @jiro_dp[i-1][j-k] / 6r
        end
      end
    end

    result = 0
    (@n..@n*6).each do |i|
      (@n...i).each do |j|
        result += @taro_dp[@n][i] * @jiro_dp[@n][j]
      end
    end
    return result.to_f
  end
end

puts Yukicoder.new.run
