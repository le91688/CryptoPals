__author__ = 'larry'
import collections
import string

#the starting hex string
hexstring = '1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736'
final = []



alpha_scoring_dict = {
    'a': 8,
    'b': 2,
    'c': 2,
    'd': 4,
    'e': 13,
    'f': 2,
    'g': 2,
    'h': 6,
    'i': 7,
    'j': 0,
    'k': 1,
    'l': 4,
    'm': 2,
    'n': 7,
    'o': 8,
    'p': 2,
    'q': 1,
    'r': 6,
    's': 6,
    't': 9,
    'u': 3,
    'v': 1,
    'w': 2,
    'x': 0,
    'y': 2,
    'z': 0,
    ' ': 5,
}

def split_string(string,n):
# create list with length of string
      its = [i for i in range(len(string))]
      newlist = [] #def new list to throw split chunks into
#breaks hexstring into n size splits
      for i in its[::n]:
         newlist.append(string[i:i+n:1])
      return newlist


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

splitstring = split_string(hexstring,2)
for n in splitstring:
   final.append(n)

print (final)
print (score_plaintext(final))


