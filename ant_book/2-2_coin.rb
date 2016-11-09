require 'scanf'

@yens = [1,5,10,50,100,500]
@yen_count = gets.scanf("%d%d%d%d%d%d")
G = gets.to_i

@results = []
@res = 1000000
@flag = 0

def check(cur_count, sum)
  cur_count.each_with_index do |count, i|
    if count < @yen_count[i]
      new_count = cur_count.dup
      new_count[i] += 1
      new_sum = sum + @yens[i]
      if new_sum == G 
        @results << new_count
        @res = [@res, new_count.inject(:+)].min
      elsif new_sum < G
        check(new_count, new_sum)
      end
    end
  end
end

check([0,0,0,0,0,0], 0)

p @results
p @res
