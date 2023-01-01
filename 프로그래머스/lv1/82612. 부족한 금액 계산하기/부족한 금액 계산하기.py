def solution(price, money, count):
    
    return 0 if money>=sum(price*i for i in range(count+1)) else sum(price*i for i in range(count+1))-money