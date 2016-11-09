require 'scanf'

MAX_N = 1000
N = gets.to_i

count = 0

N.times do 
  t, e, m, s, j, g = gets.scanf("%c%d%d%d%d%d")
  total = e + m + s + j + g
  s_total = m + s
  l_total = j + g

  next if total < 350
  count += 1 if t == 's' && s_total >= 160
  count += 1 if t == 'l' && l_total >= 160
end

p count
