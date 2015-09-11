from Crypto.Cipher import AES
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


def AES_ECB(key,string):
    cipher = AES.new(key, AES.MODE_ECB)
    msg=cipher.decrypt(string)
    return msg

for l in ciphertext:
	l = split_string(l,32)
	if len(l)!=len(set(l)):
		print ('THE FOLLOWING CIPHERTEXT WAS ENCODED WITH ECB')
		result=''.join(l)
		print (result)



	
