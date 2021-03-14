from fractions import Fraction
_, ans = input(), sum([Fraction(i) for i in input().split()])
if ans.numerator // ans.denominator != 0:
    print(ans.numerator // ans.denominator, end="")
    if ans.numerator % ans.denominator != 0:
        print(" " + str(ans.numerator % ans.denominator) + "/" + str(ans.denominator))
else:
    if ans.numerator % ans.denominator != 0:
        print(str(ans.numerator % ans.denominator) + "/" + str(ans.denominator))
    else:
        print("0")
