class Yukicoder
  def initialize
    @n = gets.to_i
    @k = gets.to_i
    @trial = 1000000
  end

  def run
    taro_win = 0

    @trial.times do
      taro_val = 0
      jiro_val = 0

      @n.times do |i|
        if i < @k
          taro_val += rand(4..6)
        else
          taro_val += rand(1..6)
        end
      end

      @n.times do
        jiro_val += rand(1..6)
      end

      taro_win += 1 if taro_val > jiro_val
    end

    puts taro_win.to_f / @trial
  end
end

Yukicoder.new.run
