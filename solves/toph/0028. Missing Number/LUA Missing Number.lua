local n = 0 + io.read()

for a in string.gmatch(io.read(), "[^ ]+") do
    local b = (0 + a)
    n = n - b
end
io.write(n)
