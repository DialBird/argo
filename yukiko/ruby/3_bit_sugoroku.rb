def bit_count(n)
  res = 0;
  while n > 0
    n &= n-1
    res += 1
  end
  return res
end

def main
  n = gets.to_i
  dp = Array.new(10001, 0)
  dp[1] = 1

  queue = [1]
  while !queue.empty?
    q = queue.shift
    return dp[q] if q == n

    step_count = bit_count(q)
    [1, -1].each do |i|
      next_pos = q + i * step_count
      if 0 < next_pos && next_pos <= n && dp[next_pos] == 0
        dp[next_pos] = dp[q] + 1
        queue << next_pos
      end
    end
  end

  return -1
end

puts main()
