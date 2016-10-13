count = 0;
while line = gets
  case count
  when 0
    color = "Gold "
  when 1
    color = "Silver "
  when 2
    color = "Bronze "
  end
  print color + line
  count += 1
end
