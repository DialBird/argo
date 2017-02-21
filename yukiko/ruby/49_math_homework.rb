class Solve
  def initialize
    str = gets.chomp
    @list = str.scan(/\d+|[+*]/)
  end

  def run
    result = 0
    result = @list[0].to_i
    len = @list.size - 1

    1.step(len, 2) do |i|
      case @list[i]
      when '*'
        result += @list[i+1].to_i
      when '+'
        result *= @list[i+1].to_i
      end
    end

    return result
  end
end

puts Solve.new.run
