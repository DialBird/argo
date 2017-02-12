N = gets.to_i
prime_checker = Array.new(N+1, true)
primes = []
win_list = Array.new(N+1, false)

prime_checker[0] = false
prime_checker[1] = false
win_list[0] = true
win_list[1] = true

2.upto(N) do |i|
  if prime_checker[i]
    primes << i
    (i*2).step(N, i) do |x|
      prime_checker[x] = false;
    end
  end

  primes.each do |j|
    if !win_list[i - j]
      win_list[i] = true
    end
  end
end

puts win_list[N] ? "Win" : "Lose"
