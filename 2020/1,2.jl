words = readlines("inputsfortask1.txt")
numbers = parse.(Int64, words)

function g(sum)

for i = 1:200
    for j = i+1:200
        for k = j+1:200
            if((numbers[i]+numbers[j]+numbers[k]) == sum)
                return numbers[i], numbers[j], numbers[k]
            end
        end    
    end    
end
end