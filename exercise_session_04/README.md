# Excercise class 4

## Ex. 1

- File permission on $HOME are
```bash
drwx------ 2 crenda uzh8 4096 Oct 17 03:54 /users/crenda
```
owner can read/write/execute, group and others have no access.  

-File permission on $SCRATCH
```bash
drwxr-x---+ 2 crenda uzh8 4096 Oct 17 03:48 /capstor/scratch/cscs/crenda
```
owner and group can read/write/execute, others cannot.I and people in same group can access it, but not other students.

If you try: cd /users/otherstudent you get permission denied.

- New file gets premission:
for $HOME -rw-r--r-- 1 crenda uzh8 0 Oct 17 04:03 /users/crenda/testfile
for $SCRATCH -rw-r-----+ 1 crenda uzh8 0 Oct 17 04:09 testfile 
 
- Permission of other user dir:

```bash
drwx------ 2 meberlei uzh8 4096 Oct 16 17:35 /users/meberlei/
```

No I could not read the content of the file

- Create file and chmod
```bash
touch locked.txt
chmod 000 locked.txt
ls -l locked.txt
```
No one can read/write/execute. But since I'm still owner I can recover the permission with chmod. 


# Ex. 2
- Regex in grep: 
1. end with 00 "00$"
2. start and end with 1 "^1.*1$"
3. contain pattern 110 "110"
4. at least three 1’s (1.*){3}
5. at least three consecutive 1’s 111

4. at least three 1’s (1.*){3}
5. at least three consecutive 1’s 111


Run cmd in terminal:

```bash
grep -E '00$' binary.txt
0000000000000000
0000000000001100
0000000000010100
...
```



# Ex. 3

- What does the factor cmd do?

when running it in the console it gives back the facored numbers example factor 20 -> 2 2 5 or factor 31 -> 31 thus we know its a prime number.
 So one number against multiple. 

- What can we do with wc? 
We can use factor to get the composite numbers and count them and if wc gives backe more than 2 its not a prime nr. factor 31 | wc -w

- timed script results
```bash
time ./isprime 4572862171001
4572862171001 is prime

real	0m0.012s
user	0m0.004s
sys	0m0.008s
[eiger][crenda@eiger-ln001 exercise_session_04]$ time ./isprime 4230283
4230283 is prime

real	0m0.012s
user	0m0.003s
sys	0m0.010s

```

 
