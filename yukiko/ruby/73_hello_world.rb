class Yukicoder
  def initialize
    alpha_num = 26
    @alphas = Array.new(alpha_num, 0)
    @targets = []

    alpha_num.times do |i|
      @alphas[i] = gets.to_i
    end
  end

  def run
    if check()
      return calc()
    else
      return 0
    end
  end

  private
  
  def check
    necesarry_alpha_idx = [3, 4, 7, 11, 14, 17, 22]
    necesarry_alpha_num = [1, 1, 1, 3, 2, 1, 1]

    necesarry_alpha_idx.each_with_index do |i, idx|
      return false if @alphas[i] < necesarry_alpha_num[idx]
      @targets << @alphas[i]
    end

    true
  end

  def calc
    l_count = @alphas[11]
    o_count = @alphas[14]

    l_max = 0
    2.upto(l_count - 1) do |i|
      atai = i * (i - 1) * (l_count - i) / 2
      l_max = atai > l_max ? atai : l_max
    end

    o_max = 0
    1.upto(o_count - 1) do |i|
      atai = i * (o_count - i)
      o_max = atai > o_max ? atai : o_max
    end
    @targets[3] = l_max
    @targets[4] = o_max

    return @targets.inject(:*)
  end
end

puts Yukicoder.new.run
