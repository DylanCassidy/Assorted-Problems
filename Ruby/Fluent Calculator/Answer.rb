class Calc
	def self.new
		return Operation.new 0
	end
end

class Operation
	def initialize(value)
		@value = value
	end

	def modify_value(value)
		if self.is_a?(PlusOperation)
			@value += value
		elsif self.is_a?(MinusOperation)
			@value -= value
		elsif self.is_a?(TimesOperation)
			@value *= value
		elsif self.is_a?(DividedByOperation)
			@value /= value
		else
			@value = value
			return self
		end
		return @value
	end

	def plus
		return PlusOperation.new @value
	end

	def minus
		return MinusOperation.new @value
	end

	def times
		return TimesOperation.new @value
	end

	def divided_by
		return DividedByOperation.new @value
	end

	def zero
		return modify_value 0
	end

	def one
		return modify_value 1
	end

	def two
		return modify_value 2
	end

	def three
		return modify_value 3
	end

	def four
		return modify_value 4
	end

	def five
		return modify_value 5
	end

	def six
		return modify_value 6
	end

	def seven
		return modify_value 7
	end

	def eight
		return modify_value 8
	end

	def nine
		return modify_value 9
	end
end

class PlusOperation < Operation
end

class MinusOperation < Operation
end

class TimesOperation < Operation
end

class DividedByOperation < Operation
end

puts Calc.new.one.plus.two
puts Calc.new.five.minus.six
puts Calc.new.seven.times.two
puts Calc.new.nine.divided_by.three