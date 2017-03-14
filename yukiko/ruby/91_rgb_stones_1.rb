class Yukicoder
  def initialize
    @stones = gets.chomp.split.map(&:to_i)
  end

  def run
    @stones.sort!
    while @stones[-1] - @stones[0] >= 3
      @stones[-1] -= 2
      @stones[0] += 1
      @stones.sort!
    end
    @stones.min
  end
end

puts Yukicoder.new.run
