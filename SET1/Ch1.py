# MATASANO CRYPTO CHALLENGE
# SET 1 CHALLENGE 1
# Convert hex to base64
#
# By Larry Espenshade
# le91688@gmail.com
# ShadeSec.com
#
#
##########################
#the starting hex string
hexstring = '49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d'


#####binary_string = '{0:b}'.format(int(hexstring, 16))

def hex_tobin64(hexstring):
### array for base64
   bin64_dict = {
   0: 'A',
   1: 'B',
   2: 'C',
   3: 'D',
   4: 'E',
   5: 'F',
   6: 'G',
   7: 'H',
   8: 'I',
   9: 'J',
   10:    'K',
   11:    'L',
   12:    'M',
   13:    'N',
   14:    'O',
   15:    'P',
   16:    'Q',
   17:    'R',
   18:    'S',
   19:    'T',
   20:    'U',
   21:    'V',
   22:    'W',
   23:    'X',
   24:    'Y',
   25:    'Z',
   26:    'a',
   27:    'b',
   28:    'c',
   29:    'd',
   30:    'e',
   31:    'f',
   32:    'g',
   33:    'h',
   34:    'i',
   35:    'j',
   36:    'k',
   37:    'l',
   38:    'm',
   39:    'n',
   40:    'o',
   41:    'p',
   42:    'q',
   43:    'r',
   44:    's',
   45:    't',
   46:    'u',
   47:    'v',
   48:    'w',
   49:    'x',
   50:    'y',
   51:    'z',
   52:    '0',
   53:    '1',
   54:    '2',
   55:    '3',
   56:    '4',
   57:    '7',
   60:    '8',
   61:    '9',
   62:    '+',
   63:    '/'
   }
   result = ''
   def split_string(somestring,n):
# create list with length of string
      its = [i for i in range(len(somestring))]
      newlist = [] #def new list to throw split chunks into
#breaks hexstring into n size splits
      for i in its[::n]:
         newlist.append(somestring[i:i+n:1])
      return newlist

   newlist = split_string(hexstring,6)
   #'this is your hex string split into 6 chars'

   #now we will iterate through and convert to binary'
   final = []
   for n in newlist:
   #print n
      b = int(n,16)
      b = '{:24b}'.format(b)  #magic key that pulls it as 24 bit
   #print b
      final.append(b)
      #print len(b)

   #'now split these into 6 bit parts'
   six_split = []
   for n in final:
      six_split.append(split_string(n,6))
   combined = [x for x in six_split for x in x]


   #now convert to int'
   for c in combined:

      c = int(c,2)
      result+=bin64_dict[c]

   return result


print(hex_tobin64(hexstring))