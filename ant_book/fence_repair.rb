

n = 3
L = [8,5,8]

ans = 0

while n > 1 do
  mii1,mii2 = 0,1
  mii1,mii2 = mii2,mii1 if L[mii1] > L[mii2]

  (2...n).each do |i|
    if L[i] < L[mii1]
      mii2 = mii1
      mii1 = i
    elsif L[i] < L[mii2]
      mii2 = i
    end
  end

  t = L[mii1] + L[mii2]
  ans += t

  mii1,mii2 = mii2,mii1 if mii1 == n-1
  L[mii1] = t
  L[mii2] = L[n-1]

  n -= 1
end

p ans
