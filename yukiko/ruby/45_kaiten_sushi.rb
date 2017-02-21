class Solve
  def initialize
    @n = gets.to_i
    @v_list = gets.chomp.split.map(&:to_i)
    @dp = Array.new(@n, 0)
  end

  def run
    return call(0)
  end
  
  private

  def call(idx)
    return 0 if idx >= @n
    return @dp[idx] if @dp[idx] > 0
    return @dp[idx] = [call(idx+1), call(idx+2) + @v_list[idx]].max
  end
end

puts Solve.new.run
