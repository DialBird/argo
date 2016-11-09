
@pro = Proc.new do |x|
  p x * 2
end

def test(a, &arr)
  if block_given?
    yield(a)
  end
end

def test2(a)
  @pro.call(a)
end


test(1) do |x|
  p x * 2
end

test2(1)
