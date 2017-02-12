require 'prime'
N = gets.to_i
primes = []
win_list = Array.new(N+1, false)

win_list[0] = true
win_list[1] = true

2.upto(N) do |i|
  primes << i if i.prime?

  primes.each do |j|
    if !win_list[i - j]
      win_list[i] = true
    end
  end
end

puts win_list[N] ? "Win" : "Lose"
