require 'bigdecimal'
require 'bigdecimal/util'

class Yukicoder
  def initialize
    n = gets.to_i
    @total = BigDecimal.new("0")
    n.times do
      val = BigDecimal.new(gets)
      @total += val
    end
  end

  def run
    str = @total.to_s("F")
    str =~ /^-?\d+\.(\d+)$/
    below_zero_count = 10 - Regexp.last_match(1).size
    below_zero_count.times { str << '0' }

    return str
  end
end

puts Yukicoder.new.run
