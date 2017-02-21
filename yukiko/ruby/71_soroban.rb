class Yukicoder
  def initialize
    @n = gets.to_i
  end

  def run
    max = 0
    0.upto(@n) do |i|
      atai = (i + 1) * (@n - i) + i
      break if atai <= max
      max = atai
    end

    return max
  end
end

puts Yukicoder.new.run
