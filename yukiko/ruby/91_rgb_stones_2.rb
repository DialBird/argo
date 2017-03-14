class Yukicoder
  def initialize
    @stones = gets.chomp.split.map(&:to_i)
  end

  def run
    min = @stones.min
    max = @stones.max
    bs(min, max)
  end

  def bs(min, max)
    mid = (min + max) / 2
    if mid == min
      mid
    else
      check(mid) ? bs(mid, max) : bs(min, mid)
    end
  end

  def check(n)
    lack = @stones.inject(0){ |t, s| t + ((s < n) ? n - s : 0) }
    plus = @stones.inject(0){ |t, s| t + ((n < s) ? (s - n)/2 : 0) }
    lack <= plus
  end
end

puts Yukicoder.new.run
