# MATASANO CRYPTO CHALLENGE
# SET 1 CHALLENGE 8
# Detect AES in ECB mode
#
# By Larry Espenshade
# le91688@gmail.com
# ShadeSec.com
#
#
##########################
#FFFFFFfrom Crypto.Cipher import AES
import base64


key = 'YELLOW SUBMARINE'

f = open('8.txt', "r")

## use readlines to read all lines in the file
## The variable "lines" is a list containing all lines
ciphertext = f.readlines()
f.close()


def split_string(somestring,n):
    its= [i for i in range(len(somestring))]
    newlist = [] #def new list to throw split chunks into
#breaks hexstring into n size splits
    for i in its[::n]:
        newlist.append(somestring[i:i+n:1])
    return newlist



def detect_ecb(ct):
for l in ciphertext:
    l = split_string(l,16)
    print (l)
    if len(l)!=len(set(l)):
        print ('THE FOLLOWING CIPHERTEXT WAS ENCODED WITH ECB')
        result=''.join(l)
        print (result)



	
