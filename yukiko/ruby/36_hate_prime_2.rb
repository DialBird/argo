n = gets.to_i
puts `factor #{n}`.count(' ') > 2 ? "YES" : "NO"
