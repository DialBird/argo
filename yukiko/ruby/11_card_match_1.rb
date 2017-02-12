W = gets.to_i
H = gets.to_i
N = gets.to_i

w_list = Array.new(W, false)
h_list = Array.new(H, false)

N.times do
  s,k = gets.chomp.split.map(&:to_i)
  w_list[s - 1] = true
  h_list[k - 1] = true
end

w_not_used_count = w_list.count(false)
h_not_used_count = h_list.count(false)

puts (W * H) - (w_not_used_count * h_not_used_count) - N
