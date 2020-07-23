zero = 0
one = 1
two = 2
three = 3
four = 4
five = 5
six = 6
seven = 7
eight = 8
nine = 9

calc = \a b c d -> a b c d
new = \x func y -> func x y

plus = \x y -> x + y
minus = \x y -> x - y
times = \x y -> x * y
-- Note that the "/" operator doesn't work on integers, so I used "div" instead, which does floor division
divided_by = \x y -> div x y

main = do
	print (calc new one plus two)
	print (calc new five minus six)
	print (calc new seven times two)
	print (calc new nine divided_by three)