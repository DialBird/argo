class Solve
  def initialize
    @s = gets.chomp.split('')
    @results = []
  end

  def run
    call(@s, "")
    return @results.uniq.size
  end

  private

  def call(rest_str, maked_str)
    if rest_str.size == 1
      maked_str += rest_str[0]
      @results << maked_str
      return
    else
      new_str_1 = maked_str.dup
      new_str_1 += rest_str[0]
      call(rest_str[1..-1], new_str_1)
      new_str_2 = maked_str.dup
      new_str_2 += rest_str[-1]
      call(rest_str[0..-2], new_str_2)
    end
  end
end

puts Solve.new.run
