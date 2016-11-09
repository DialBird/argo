require 'scanf'

N, S, p = gets.scanf("%d%d%d")

data = {}

N.times do |n|
    size, cal = gets.scanf("%d%d")
    data[n + 1] = [size, cal]
end

good_one = {num: 0, size: 0}
data.each do |k, v|
    if v[1].between?(S-p, S+p) && v[0] > good_one[:size]
        good_one[:num] = k
        good_one[:size] = v[0]
    end
end

if (good_one[:num] == 0)
    puts "not found"
else
    puts good_one[:num]
end
