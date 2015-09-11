__author__ = 'larry'
# MATASANO CRYPTO CHALLENGE
# SET 1 CHALLENGE 4
# Detect single-character XOR
#
# By Larry Espenshade
# le91688@gmail.com
# ShadeSec.com
#
# August 29, 2015
##########################


#the file

with open('4.txt') as f:
    content = f.read().splitlines()




###### dictionary with a character frequency occuring in english language
#########################################################################
#
#
#
alpha_scoring_dict = {
    'a':   8,
    'b':   2,
    'c':   2,
    'd':   4,
    'e':   13,
    'f':   2,
    'g':   2,
    'h':   6,
    'i':   7,
    'j':   0,
    'k':   1,
    'l':   4,
    'm':   2,
    'n':   7,
    'o':   8,
    'p':   2,
    'q':   1,
    'r':   6,
    's':   6,
    't':   9,
    'u':   3,
    'v':   1,
    'w':   2,
    'x':   0,
    'y':   2,
    'z':   0,
    ' ':   5,
    }



################# Function to split a string into a list of size N
##################################################################

def split_string(somestring,n):
    # create list with length of string
    its = [i for i in range(len(somestring))]
    newlist = [] #def new list to throw split chunks into
    #breaks hexstring into n size splits
    for i in its[::n]:
       newlist.append(somestring[i:i+n:1])
    return newlist



    ################# Function to score plaintext
    #############################################
def score_plaintext(final):
    test =[]
    score=0
    highscore=0
    winner=0
    c=0
    while c<128:
       for f in final:
          f=int(f,16)
          test.append(chr(f^c))
       #print 'iteration of %d' % c
       test = ''.join(test)  #convert list to string
       #print test
       for t in test:
          if t in alpha_scoring_dict:
             score+=alpha_scoring_dict[t] #score test
       #print 'score = %d' % score
       if highscore<score: #capture highscore through all iterations
          highscore=score
          winner=c
       score=0
       c+=1
       test=[]
    answer=[]

    for f in final:
       f=int(f,16)
       answer.append(chr(f^winner))
    answer = ''.join(answer)
    return (highscore,winner,answer)


    ################# Call zee functions
    #####################################
superwinner=0
winningkey=0
for l in content:
    #print (l)
    newlist=split_string(l,2) #split string in 2 char chunks (bc its hex)
    #print (newlist)

    a = score_plaintext(newlist)
    #print ('highscore = %d' % a[0])
    #print ('XOR KEY = %c' % chr(a[1]))
    if superwinner<a[0]:
       superwinner=a[0]
       winningkey=a[1]
       winningline=l
       winninganswer=a[2]

print ('=====RESULTS======')
print ('highscore = %d' % superwinner)
print ('win key = %d' % winningkey)
print ('win line = %s' % winningline)
print ('winning answer = %s' % winninganswer)