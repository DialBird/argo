require 'scanf'

capa = gets.to_i
N = gets.to_i

data = {}

N.times do
  hour, min, copies = gets.scanf("%d%d%d")
  if data.has_key?(hour)
    data[hour] += copies
  else
    data[hour] = copies
  end
end

result = 0
p arr
data.each do |key, val|
  need_time = val % capa == 0 ? val / capa : val / capa + 1
  result += need_time
end
puts result
