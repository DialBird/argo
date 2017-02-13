class Solve
  def initialize
    @n = gets.to_i
    @game_board = @n.times.map do
      gets.chomp.split('')
    end
    @wins = Array.new(@n, 0)
  end

  def run
    return calc(0,0)
  end

  private

  def calc(x,y)
    if x >= @n
      y += 1
      return get_rank if y >= @n
      x = y
    end

    case @game_board[x][y]
    when 'o'
      @wins[x] += 1 
      rank = calc(x+1, y)
      @wins[x] -= 1
      return rank
    when 'x'
      @wins[y] += 1 
      rank = calc(x+1, y)
      @wins[y] -= 1
      return rank
    when '-'
      @wins[x] += 1 
      rank_1 = calc(x+1, y)
      @wins[x] -= 1
      @wins[y] += 1 
      rank_2 = calc(x+1, y)
      @wins[y] -= 1
      return [rank_1, rank_2].min
    else
      return calc(x+1, y)
    end
  end

  def get_rank
    current_max = @wins[0]
    rank = 1
    wins_sort = @wins.sort

    wins_sort.each do |i|
      if current_max < i
        rank += 1
        current_max = i
      end
    end

    return rank
  end
end

p Solve.new.run
