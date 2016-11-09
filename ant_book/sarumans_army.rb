
results = []

arr = [1,2,4,8,10,11, 16]
R = 2

count = 0
i = 0

while i <= arr.length-1 do
  # 最初に追加
  count += 1

  break if i == arr.length-1

  tmp_i = arr.index { |e| e > arr[i] + R }
  break if tmp_i.nil?

  next_i = arr.index { |e| e > arr[tmp_i - 1] + R }
  break if next_i.nil?

  i = next_i
end

p count
