local i = 0 + io.read()

i = i + 1
local sum = 0
while i > 0 do
    i = i - 1
    sum = sum + i * i
end
io.write(sum, "\n")
