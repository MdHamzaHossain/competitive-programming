local A = 0 + io.read()

for i = 1, A + 1 do
    if A % i == 0 then
        io.write(i)
        io.write("\n")
    end
end
