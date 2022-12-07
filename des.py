from Crypto.Cipher import DES

key = b'-8B key-'
plaintext = b'Kajal Pawar'
cipher = DES.new(key, DES.MODE_OFB)
ivs = cipher.iv
msg =  cipher.encrypt(plaintext)
print(msg)
cipher = DES.new(key, DES.MODE_OFB,iv=ivs)
m1 = cipher.decrypt(msg)
print(m1)

