
def fries(n):
    p=[x for x in range(1,n+1)]  #create list of nums to n
    for x in range(len(p)):      #iterate that last
        if x > 2:                
            p[x] = p[x-1]+p[x-2]  #if the index is > 2 , the value at that index = sum previous 2 elements
    print(p[n-1])                 # print final element
    
    #this however, is not an efficient way to do this, as we would need to allocate memory to store the entire list up to n bytes
    

# in this method, we save memory by utilizing variables
def fries2(n):
    p1 = 1 # num of ways to eat one fry
    p2 = 2 # num of ways to eat 2 fries
    for x in range (3,n+1):   # iterate 3 - n;
        temp = p2   # save p2 to temp
        p2 +=p1     # p2 = sum of p2+p1
        p1 = temp   # p1 = old p2       
    print (p2)
    
        


fries(99999)