class Solve
  def initialize
    @devider = 1000003
    @x, _ = gets.chomp.split.map(&:to_i)
    @list = gets.chomp.split.map{ |i| i.to_i % (@devider - 1) }
    @dp = Array.new(@devider, -1)
    
    @x %= @devider
  end

  def run
    result = 0
    @list.each do |l|
      if @dp[l] == -1
        @dp[l] = my_pow(@x, l)
      end
      result += @dp[l]
    end

    p result % @devider
  end

  private

  def my_pow(n, idx)
    res = 1
    if idx > 0
      res = my_pow(n*n % @devider, idx/2)
      res = res * n % @devider if idx & 1 == 1
    end
    return res % @devider
  end
end

Solve.new.run
