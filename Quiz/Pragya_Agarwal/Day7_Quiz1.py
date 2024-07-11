def value(s):
    n=len(s)
    x= s.count("x")
    y= n-x
    
    dig0=0
    min_value = n
    
    for i in range(0,n+1):
        dig1 = y-i
        min_value= min(min_value,max(dig0,dig1)
        if i<n and s[i]=='x':
            dig0 +=1
    return min_value

str_input=input()
print(value(str_input))
