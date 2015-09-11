from Crypto.Cipher import AES



plaintext = 'THIS IS A TEST OF CBC MODE AES CIPHER STUFF'

IV = '0000000000000000'

key = 'YELLOW SUBMARINE'


def pad_plaintext(string, key):
	bytestring = str.encode(string)
	R = (len(bytestring) % len(key))
	if len(bytestring) < len(key):
		padded = string.ljust( len(key), '0')
	if len(bytestring) > len(key):
		padded = string.ljust(len(bytestring)+(len(key)-R), '0')
	else:
		padded = bytestring
	padded = str.encode(padded)
	return (padded)
	
def pad_plaintext(string, key):
	bytestring = str.encode(string)
	R = (len(bytestring) % len(key))
	print (('R= %d') % R)
	if len(bytestring) < len(key):
		padded = string.ljust( len(key), '0')
		padded = str.encode(padded)
	if len(bytestring) > len(key):
		padded = string.ljust(len(bytestring)+(len(key)-R), '0')

	return (padded)
	
padded = (pad_plaintext(plaintext,key))
print ('padded')
print (padded)
print (len(padded))


def split_string(somestring, n):
    # create list with length of string
    its = [i for i in range(len(somestring))]
    newlist = []  # def new list to throw split chunks into
    # breaks hexstring into n size splits
    for i in its[::n]:
        newlist.append(somestring[i:i + n:1])
    return newlist

def encrypt_AES_ECB(key,string):
    cipher = AES.new(key, AES.MODE_ECB)
    msg=cipher.encrypt(string)
    return msg
    
def decrypt_AES_ECB(key,string):
    cipher = AES.new(key, AES.MODE_ECB)
    msg=cipher.decrypt(string)
    return msg
#########################################################

def xor_strings(str1, str2):
	l = [str1 ^ str2 for str1, str2 in zip(str1,str2)]
	#l= list(map(chr,l))
	#print (l)
	
	#l = ''.join(l)
	#l= str.encode(l)
	return l
    
def encrypt_CBC(key, string, IV):
	result=''
	padded = pad_plaintext(string,key) # pad plaintext to make even 
	print (len(str.encode(padded)))
	split = split_string(padded, len(key)) # split into keysize chunks
	print (split)
	print ('first piece')
	print (len(split[0]))
	print (split[0])
	XORd = xor_strings(str.encode(split[0]),str.encode(IV)) # XOR IV and plaintext
	print ('XORd')
	print (XORd)
	print (len(XORd))
	ciphertext = encrypt_AES_ECB(key, XORd) #ecrypt first chunk with AES
	print ('first ciphertext ')
	print (ciphertext)
	print (len(ciphertext))
	result+=(str(ciphertext))
	for i in range((len(split)))[1::]: # loop through chunks
		print ('current chunk = %s' %(split[i]))
		print (len(str.encode(split[i])))
		print ('DEBUGGING')
		print ('CT')
		print (ciphertext)
		print (len(ciphertext))
		print ('split')
		print (str.encode(split[i]))
		print (len(str.encode(split[i])))
		ciphertext = xor_strings(ciphertext,str.encode(split[i]))
		print ('XORd with cipher')
		print (ciphertext)
		print (len(ciphertext))
		print ('AESd')
		ciphertext = encrypt_AES_ECB(key, ciphertext)
		result+=(str.encode(ciphertext))
		print (str.encode(ciphertext))
		print (len(str(ciphertext)))
	return result
	
def decrypt_CBC(key, string, IV):
	result=''
	split = split_string(string, len(key)) # split into keysize chunks
	print (split)
	print ('first CT')
	print (split[0])
	ciphertext = decrypt_AES_ECB(key, split[0]) #ecrypt first chunk with AES
	print ('AES decrypted ')
	print (ciphertext)
	XORd = xor_strings(ciphertext,IV) # XOR IV and plaintext
	print ('XORd with IV')
	print (str.encode(XORd))
	result+=(XORd)
	for i in range((len(split)))[1::]: # loop through chunks
		print ('current chunk = %s' %(split[i])) #next chunk of CT
		ciphertext = decrypt_AES_ECB(key, split[i])
		print ('AES decrypted')
		print (str.encode(ciphertext))
		print ('XORd with last CT')
		ciphertext = xor_strings(ciphertext,split[i-1])
		print (str.encode(ciphertext))
		result+=(ciphertext)
	return result
	
	
	
	
ciphertext = (encrypt_CBC(key, plaintext, IV))




print ('AFTER AES CBC encryption = %s '% ciphertext)
print ('----------------------------------------------')


#plaintext = (decrypt_CBC(key,ct, IV))

#print ('AFTER AES CBC decryption = %s' %(plaintext))

#print (decrypt_CBC(key, ciphertext, IV))

	
	
	
