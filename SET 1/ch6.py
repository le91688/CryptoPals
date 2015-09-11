__author__ = 'larry'
import string
import base64
import binascii
import codecs

data = b'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'

test = base64.b64decode(data)

###### dictionary with a character frequency occuring in english language
#########################################################################
#
#
#
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


################# Function to score plaintext
#############################################
def score_plaintext(final):
    test = []
    score = 0
    highscore = 0
    winner = 0
    c = 0
    while c < 128:
        for f in final:
            #f = ord(f) # py2.7
            test.append(chr(f ^ c))
        # print 'iteration of %d' % c
        test = ''.join(test)  # convert list to string
        # print test
        for t in test:
            if t in alpha_scoring_dict:
                score += alpha_scoring_dict[t]  # score test
        # print 'score = %d' % score
        if highscore < score:  # capture highscore through all iterations
            highscore = score
            winner = c
        score = 0
        c += 1
        test = []
    answer = []

    for f in final:
        #f = ord(f)
        answer.append(chr(f ^ winner))
    answer = ''.join(answer)
    return (winner)


######################################


def xor_strings(str1, str2):
    l = [str1 ^ str2 for str1, str2 in zip(str1,str2)]
    l = map(bin, l)

    ham = float(0)
    for x in l:
        # print x
        for b in x:
            if b == '1':
                ham += 1
    return float(ham)


def split_string(somestring, n):
    # create list with length of string
    its = [i for i in range(len(somestring))]
    newlist = []  # def new list to throw split chunks into
    # breaks hexstring into n size splits
    for i in its[::n]:
        newlist.append(somestring[i:i + n:1])
    return newlist


finalham = 100


# print xor_strings(str1,str2)
###########################################
def repeating_key_xor(plaintext, key):
    key.split()
    key = list(map(ord,key))
    # print key

    #plaintext = list(map(ord, plaintext))
    # print plaintext



    encrypted = []
    i = 0

    for p in plaintext:
        encrypted.append(key[i] ^ p)
        i += 1
        if i == len(key):
            i = 0

    # print encrypted


    hexed = map(chr, encrypted)
    # print hexed

    # encrypted= [x.strip('0x') for x in hexed]

    # final =   ''.join(encrypted)

    # string = '0x%s'%final

    return (hexed)


#############################################

keysize = range(41)

for i in range(1, len(keysize) - 1):

    # print 'it = %d' %i

    a = keysize[i]

    # print a

    string1 = test[:a:]

    # print 'string1%s' % string1

    string2 = test[a:a + a]

    # print 'string 2 %s' % string2

    string3 = test[a + a:a + a + a:]

    # print 'string 3 %s' % string3

    string4 = test[a + a + a:a + a + a + a:]

    # print 'string 4 %s' % string4


    hamming1 = (xor_strings(string1, string2)) / a
    # print 'hamming1 = %f'% hamming1
    hamming2 = (xor_strings(string2, string3)) / a
    # print 'hamming2 = %f'% hamming2
    hamming3 = (xor_strings(string3, string4)) / a
    # print 'hamming3 = %f'% hamming3
    hamming4 = (xor_strings(string4, string1)) / a
    # print 'hamming4 = %f'% hamming4
    hamming5 = (xor_strings(string4, string2)) / a
    # print 'hamming5 = %f'% hamming5
    hamming6 = (xor_strings(string3, string1)) / a
    # print 'hamming6 = %f'% hamming6

    hamming = (hamming1 + hamming2 + hamming3 + hamming4 + hamming5 + hamming6) / float(6)
    # print 'hamming avg  = %f'% hamming


    if hamming < finalham:
        finalham = hamming
        keylength = a
print('lowest ham = %f' % finalham)
print('keylength is = %d' % keylength)
######################################################
brokendata = split_string(test, keylength)

for b in brokendata:
    # print b
    # print '----'
    if len(b) != keylength:
        # print 'BAD'
        brokendata.pop() # remove last "not keylength size" element

transposed = {}
for i in range(keylength):
    #print('iteration %d' % i)
    key = i
    value = [item[i] for item in brokendata]
    transposed[key] = value
# print transposed[i]
XORkey = []

for key, value in transposed.items():
    XORkey.append(chr(score_plaintext(value)))
XORkey = ''.join(XORkey)
print('XOR KEY IS')
print(XORkey)

result = repeating_key_xor(test, XORkey)
print('RESULT =')
print(''.join(result))
