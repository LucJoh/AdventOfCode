

#a, b = split.(list2[1][1], "-")

#parse.(Int64, a)
#parse.(Int64, b)

function f()

list = readlines("inputsfortask2.txt")
list2 = split.(list)

valid_passwords = 0

for i in list2
   a, b = split(i[1], "-")
   
   a = parse(Int64,a)
   b = parse(Int64,b)

   x=findall(==(i[2][1]),i[3])
   if length(x) >= a && length(x) <= b
      valid_passwords += 1
   end 
end
     println(valid_passwords)
end
f()

