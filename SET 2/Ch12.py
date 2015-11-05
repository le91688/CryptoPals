# MATASANO CRYPTO CHALLENGE
# SET 2 CHALLENGE 12
# Byte-at-a-time ECB decryption (Simple)
#
# By Larry Espenshade
# le91688@gmail.com
# ShadeSec.com
#
#11/4/2015
##########################

from nt import urandom
from Crypto.Cipher import AES
import random
import base64


unknown = "Um9sbGluJyBpbiBteSA1LjAKV2l0aCBteSByYWctdG9wIGRvd24gc28gbXkgaGFpciBjYW4gYmxvdwpUaGUgZ2lybGllcyBvbiBzdGFuZGJ5IHdhdmluZyBqdXN0IHRvIHNheSBoaQpEaWQgeW91IHN0b3A/IE5vLCBJIGp1c3QgZHJvdmUgYnkK"


def gen_rand_bytes(n):
    r = (urandom(n))
    return r

key = b'63oD\xd4\xc2n\x91\xd9DM\x83\x14\x89\xc31'


def pad_plaintext(ba, key):
    #print ("padding bytearray!")
    #print (ba)
    R = (len(ba) % len(key)) #remainder
    if len(ba) < len(key): #if bytearray is less than size of key
        pad = bytearray(R) #pad = bytearray made of 0s len of R
        padded = ba + pad
    if len(ba) > len(key):
        pad = bytearray((len(key)-R))
        padded = ba + pad
    else:
        padded = ba
    #print("padded = %s" %padded)
    return padded
    

def split_string(somestring, n):
    # create list with length of string
    try:
        somestring = str.encode(somestring)
    except TypeError:
        pass
    its = [i for i in range(len(somestring))]
    newlist = []  # def new list to throw split chunks into
    # breaks hexstring into n size splits
    for i in its[::n]:
        newlist.append(somestring[i:i + n:1])
    return newlist

def encrypt_AES_ECB(key,string):
    cipher = AES.new(key, AES.MODE_ECB)
    msg=cipher.encrypt(bytes(string))
    return msg
    
def decrypt_AES_ECB(key,string):
    cipher = AES.new(key, AES.MODE_ECB)
    msg=cipher.decrypt(string)
    return msg
#########################################################

def xor_strings(x, y):
    l = bytes([x ^ y for x, y in zip(x,y)])
    return l
    
def encrypt_CBC(key, string, IV):
    #IV = str.encode(IV)
    result=b''
    #padded = pad_plaintext(string,key) # pad plaintext to make even 
    split = split_string(string, len(key)) # split into keysize chunks
    XORd = xor_strings(split[0],IV) # XOR IV and plaintext
    ciphertext = encrypt_AES_ECB(key, XORd) #ecrypt first chunk with AES
    result+=(ciphertext)
    for i in range((len(split)))[1::]: # loop through chunks
        ciphertext = xor_strings(ciphertext,split[i])
        ciphertext = encrypt_AES_ECB(key, ciphertext)
        result+=(ciphertext)
    return result
    
def decrypt_CBC(key, string, IV):
    #IV = str.encode(IV)
    #result=b''
    split = split_string(string, len(key)) # split into keysize chunks
    ciphertext = decrypt_AES_ECB(key, split[0]) #ecrypt first chunk with AES
    XORd = xor_strings(ciphertext,IV) # XOR IV and plaintext
    result =result+(XORd)
    for i in range((len(split)))[1::]: # loop through chunks
        ciphertext = decrypt_AES_ECB(key, split[i])
        ciphertext = xor_strings(ciphertext,split[i-1])
        result= result+ciphertext
    return result
    

def encryption_oracle(pt,unknown,key):
    bytes = str.encode(unknown)
    bytes= base64.b64decode(bytes)
    #pre = gen_rand_bytes((random.randint(5,10))) 
    #post = gen_rand_bytes((random.randint(5,10)))

    b = bytearray()
    b.extend(map(ord,pt))
    b = b+bytes
    #b= pre + b
    #b = b + post
    #print ("bytearray = %s" %b)
    pt = pad_plaintext(b, key)
    choice = 1#random.randint(1,2) #choose ecb cbc  ### ALWAYS ECB
    if choice == 1:
        #print ("ecb")
        r = encrypt_AES_ECB(key, pt)
    else:
        #print ("cbc")
        IV = gen_rand_bytes(16)
        r = encrypt_CBC(key, pt, IV)
    
    return r
pt = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
print("given input : %s" %pt)
print("INPUT SIZE =%i" %len(pt))
print ( "encrypted:")
ct = (encryption_oracle(pt,unknown,key))
print (ct)
print ("")
    
def detect_ecb(ct):
    l = split_string(ct,16)
    print (ct[31])
    if len(l)!=len(set(l)):
        print ('THE CIPHERTEXT WAS ENCODED WITH ECB')
        #result=''.join(l)
        #print (l)    
    else:
        print ('NOPE')
        
detect_ecb(ct)