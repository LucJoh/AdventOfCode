
function f()

    list = readlines("inputsfortask2.txt")
    list2 = split.(list)
    
    valid_passwords = 0
    
    for i in list2
       a, b = split(i[1], "-")
       
       a = parse(Int64,a)
       b = parse(Int64,b)
    
       if (i[2][1] == i[3][a] && i[2][1] != i[3][b]) || (i[2][1] != i[3][a] && i[2][1] == i[3][b])
          valid_passwords += 1
       end 
    end
         println(valid_passwords)
    end
    f() 