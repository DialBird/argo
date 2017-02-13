class Solve
  def initialize
    @n_arr = gets.chomp.split('').map(&:to_i)
  end

  def run
    len = @n_arr.size
    target_idx = nil

    @n_arr.each_with_index do |n, i|
      max = n

      (i+1).upto(len-1) do |j|
        if (max == n && max < @n_arr[j]) || (max != n && max <= @n_arr[j])
          max = @n_arr[j]
          target_idx = j
        end
      end

      if target_idx
        @n_arr[i], @n_arr[target_idx] = @n_arr[target_idx], @n_arr[i]
        break;
      end
    end

    return @n_arr.join('')
  end
end

puts Solve.new.run
