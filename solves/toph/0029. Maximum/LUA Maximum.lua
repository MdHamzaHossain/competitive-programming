local n = 0 + io.read()
local max = 0


for a in string.gmatch(io.read(), "[^ ]+") do
    local b = (0 + a)
    if b > max then
        max = b
    end
end
io.write(max)
