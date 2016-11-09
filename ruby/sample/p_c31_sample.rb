require 'scanf'
require 'time'

num = gets.chomp.to_i
all = {}

num.times do
  arr = gets.scanf("%s %d");
  all[arr[0]] = arr[1]
end

con, hour, min = gets.scanf("%s %d:%d");
base_time = all[con]

all.each do |key, val|
  t = Time.new(1991,4,1,hour,min)
  t += (val - base_time)*60*60
  puts t.strftime("%H:%M")
end
