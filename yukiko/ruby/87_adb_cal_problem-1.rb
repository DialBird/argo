require 'date'

class Yukicoder
  def initialize
    @n = gets.to_i
  end

  def run
    # nが2400以下の時端数の計算
    first_span = Array.new((2400 - 2014) + 1, 0)

    first_cnt = 0
    wday = 0
    2015.upto(2400) do |i|
      if i % 400 == 0 || i % 4 == 0 && i % 100 != 0
        wday += 2
      else
        wday += 1
      end
      wday %= 7
      first_cnt += 1  if wday == 0
      first_span[i-2014] = first_cnt
    end

    # 400 * 7(足され方が一周するように一週間の日数をかける)
    span_2800 = Array.new(2800, 0)
    cnt = 0
    1.upto(2799) do |i|
      if i % 400 == 0 || i % 4 == 0 && i % 100 != 0
        wday += 2
      else
        wday += 1
      end
      wday %= 7
      cnt += 1  if wday == 0
      span_2800[i] = cnt
    end

    if @n <= 2400
      return first_span[@n-2014]
    end
    first_cnt + (@n - 2400) / 2800 * cnt + span_2800[(@n - 2400) % 2800]
  end
end

puts Yukicoder.new.run
