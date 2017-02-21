class Yukicoder
  def initialize
    @n = gets.to_i
    @blocks = gets.chomp.split.map(&:to_i)
  end

  def run
    ans = 999999999

    1.upto(100) do |i|
      plus = 0
      minus = 0

      require_num = 1
      i.times do |j|
        if j < @n
          if @blocks[j] < require_num
            minus += require_num - @blocks[j]
          else
            plus += @blocks[j] - require_num
          end
        else
          minus += require_num
        end
        require_num += 1
      end

      require_num = i-1
      (i-1).times do |j|
        if (i + j) < @n
          if @blocks[i + j] < require_num
            minus += require_num - @blocks[i + j]
          else
            plus += @blocks[i + j] - require_num
          end
        else
          minus += require_num
        end
        require_num -= 1
      end

      ((2*i-1)...@n).each do |j|
        plus += @blocks[j]
      end

      break if plus < minus
      ans = plus if plus < ans
    end

    return ans
  end
end

puts Yukicoder.new.run
