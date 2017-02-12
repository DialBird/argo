W = gets.to_i
H = gets.to_i
N = gets.to_i

w_list = []
h_list = []

N.times do
  s,k = gets.chomp.split.map(&:to_i)
  w_list << s
  h_list << k
end

w_not_used_count = W - w_list.uniq.count
h_not_used_count = H - h_list.uniq.count

puts (W * H) - (w_not_used_count * h_not_used_count) - N
