class Solve
  def initialize
    @n_arr = gets.chomp.split('').map(&:to_i)
  end

  def run
    idxs = [*0...@n_arr.size]
    nums = idxs.product(idxs).map do |i,j|
      arr_d = @n_arr.dup
      arr_d[i], arr_d[j] = arr_d[j], arr_d[i]
      arr_d.join.to_i
    end

    return nums.max
  end
end

puts Solve.new.run
