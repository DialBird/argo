require 'scanf'

totals = []
pal_n, user_n, top_n = gets.scanf("%d %d %d")
points = gets.split(' ').map(&:to_f)

user_n.times do |u|
  items = gets.split(' ').map(&:to_i)
  total = 0
  items.each_with_index do |e, i|
    total += e * points[i]
  end
  totals << total.round(0)
end

totals.sort!{|a, b| b <=> a}

top_n.times do |i|
  puts totals[i]
end
