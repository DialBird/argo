class Yukicoder
  def initialize
    @n, @m, _ = gets.chomp.split.map(&:to_i)
  end

  def run
    if @n == 1
      return @m == 2 ? "YES" : "NO"
    elsif @m == 1
      return @n == 2 ? "YES" : "NO"
    end

    @n.odd? && @m.odd? ? "NO" : "YES"
  end
end

puts Yukicoder.new.run
