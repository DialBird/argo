class Yukicoder
  def initialize
    @n,m,_ = gets.chomp.split.map(&:to_i)

    @g = Hash.new{|h,k| h[k]=Hash.new{[]}}

    m.times do
      a,b,c = gets.chomp.split.map(&:to_i)
      @g[c][a] += [b]
      @g[c][b] += [a]
    end

    @d_list = gets.chomp.split.map(&:to_i)
  end

  def run
    candidate_town = [*1..@n]
    @d_list.each do |d|
      candidate_town = @g[d].values_at(*candidate_town).flatten.uniq
    end

    puts candidate_town.size
    puts candidate_town.sort.join(' ')
  end
end

Yukicoder.new.run
