def check_balanced(string):
    bracket_list = []
    bracket_dict = {")": "(", "}": "{", "]": "["}
    for a in string:
      if a in bracket_dict.values():
        bracket_list.append(a)
      elif a in bracket_dict.keys():
        if not bracket_list or bracket_list.pop() != bracket_dict[a]:
          return "NO"
    return "YES"


string=input("enter string of brackets: ")
print(check_balanced(string))

#Test case-1
#enter string of brackets:= {[()]}
#print(check_balanced(string))  # Output: YES

#Test case-2
#enter string of brackets: [)
#output: NO
