require 'prime'

class Solve
  def initialize
    n = gets.to_i
    @factorial_list = n.prime_division
  end

  def run
    count = 0
    @factorial_list.each do |_, x|
      count += x
    end
    return count >= 3 ? "YES" : "NO"
  end
end

puts Solve.new.run
