words = readlines("inputsfortask1.txt")
numbers = parse.(Int64, words)

function f(sum)

for i = 1:200
    for j = i+1:200
        if((numbers[i]+numbers[j]) == sum)
            return numbers[i], numbers[j]
        end
    end    
end
end

