s1 = 'ciao'
s2 = 'buongiorno'

#indicizazione con mumeri positivi
print(s1[0])
print(s1[1])
print(s1[2])
print(s1[3])

print('\n')

#indicizazione con mumeri negativi
print(s1[-4])
print(s1[-3])
print(s1[-2])
print(s1[-1])

print('\n')

#slicing s1[p1 : p2 : g] inizio, arrivo e gap
print(s2[1 : 5]) #5 escluso, primo incluso e secondo escluso
print(s2[1 : 5 : 2]) #gap = 2, salta di due in due 

print(s2[:4]) #parte da 0 e 4 escluso
print(s2[3:]) #parte da 3 e va fino alla fine

print(s2[:-1])

l = len(s2)
print(l)

var = input('frase: ')
int(var)
print(var)