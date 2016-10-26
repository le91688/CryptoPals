def fry_options(n):
    a_0 = 1 #one way to eat 0 fries
    a_1 = 1 #one way to eat 1 fry
    #for n fries we may either start by eating two fries
    #or we can eat only on fry.  Whence, if a(n) is the number
    #ways to eat n fries, we have a(n) = a(n-1) + a(n-2)
    for x in xrange (2, n+1):
        temp = a_1
        a_1 += a_0
        a_0 = temp
    return a_1
    
#a clearer way to see what is going on is shown below.
#However this is a horrible abuse of resources and simply
#won't scale well:

#def fries(n):
#    if n==0:
#        return 1
#    if n==1:
#        return 1
#    else:
#        return fries(n-1)+fries(n-2)
print(fry_options(100))