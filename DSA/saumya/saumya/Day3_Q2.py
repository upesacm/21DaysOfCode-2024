# QUES2
import string

def check_symmetry(input_str):
    input_str = input_str.lower()
    reversed_str = input_str[::-1]
    swapped_str = ''.join(chr(ord('z') - (ord(c) - ord('a'))) for c in reversed_str)
    if input_str == swapped_str:
        return "symmetrical"
        
    else:
      return "not symmetrical"


input_str = input("Enter a string: ")
print(check_symmetry(input_str))

#TEST CASE 1
#Enter a string: axcz
#symmetrical

#TEST CASE 2
#Enter a string: hello
#not symmetrical

