P = gets.to_i

P.times do |p|
  n,k = gets.chomp.split.map(&:to_i)
  if k < n && n % (k + 1) == 1
    puts "Lose"
  else
    puts "Win"
  end
end
