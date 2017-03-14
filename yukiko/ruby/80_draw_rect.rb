class Yukicoder
  def initialize
    @d = gets.to_i
  end

  def run
    two_side_total = @d >> 1
    x = two_side_total >> 1
    return x * (two_side_total - x)
  end
end

puts Yukicoder.new.run
