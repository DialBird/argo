class Solve
  def initialize
    @s = gets.chomp.split('')
    @strs = []
  end

  def run
    call("")
    return @strs.uniq.size
  end
  
  private

  # 文字列は参照渡しなので、いちいち複製する必要がある。
  # 最後の一個の場合は人パターンだけなので複製する必要がない
  def call(maked)
    if @s.size == 1
      maked += @s[0]
      @strs << maked
      return
    else
      maked_dup_1 = maked.dup
      first_c = @s.shift
      maked_dup_1 += first_c
      call(maked_dup_1)
      @s.unshift(first_c)

      maked_dup_2 = maked.dup
      last_c = @s.pop
      maked_dup_2 += last_c
      call(maked_dup_2)
      @s.push(last_c)
    end
  end
end

puts Solve.new.run
